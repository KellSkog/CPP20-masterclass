#include "exercise.hpp"
#include <iostream>
#include <string>
/**
 * https://cppinsights.io/
 */

template <typename T>
void func(T num)
{
    std::cout << num << ", " << sizeof(num) << "\n";
}
template <>
void func(std::string name)
{
    std::cout << name << "\n";
}
void TryingOutFunctionTemplates_234()
{
    int a = 4;
    [[maybe_unused]] float b = 40.1f;
    [[maybe_unused]] double c = 42.9;
    func<int>(a);
    func<double>(a);
    func(b);
    func(c);
    auto s = std::string("Hello");
    func(s);
    func("Hello");
}

void TemplateTypeDeductionAndExplicitArguments_235()
{
    func<int>(42);
}

#include <typeinfo>
template <typename T>
void func2(T &num)
{
    std::cout << num << ", " << typeid(num).name() << "\n";
}
void TemplateParametersByReference_236()
{
    // func2(42); // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    auto a{42};
    func2(a);
}

template <typename T>
void func3(T num)
{
    std::cout << num << ", " << typeid(num).name() << "\n";
}
template <typename T> // not possible to specialize for ref
void func4(T num)
{
    std::cout << num << ", "
              << "Inte"
              << "\n";
}
void func5([[maybe_unused]] int x) {}
void func5([[maybe_unused]] int &x) {}
template <typename T>
void func6([[maybe_unused]] T x) {}
template <>
void func6([[maybe_unused]] int *x) {}
void TemplateSpecialization_237()
{
    func3(42);
    auto a{42};
    func4(a);
    func5(42);
    // func5(a); // error: call of overloaded ‘func5(int&)’ is ambiguous
    func6(a);
    func6(&a);
}

void func7([[maybe_unused]] int *t) { std::cout << "Raw overload\n"; }
template <typename T>
void func7([[maybe_unused]] T t) { std::cout << "Template\n"; }
template <typename T>
void func7([[maybe_unused]] T *t) { std::cout << "Template overload\n"; }
template <>
void func7([[maybe_unused]] const char *t) { std::cout << "Template spec\n"; }
// template <>
// void func7([[maybe_unused]] char *t) { std::cout << "Template spec\n"; }
void FunctionTemplatesWithOverloading_238()
{
    auto a{42};
    auto b{'b'};
    func7(a);
    func7(&a);
    func7(&b);
    func7("Hello");
}
/// Compiler is required to deduce all template argument
template <typename T, typename R>
R func8(T t)
{
    return static_cast<R>(t);
}
template <typename R, typename T, typename S>
R func9(T t)
{
    return static_cast<R>(t);
}
template <typename R, typename T>
R func10(T t)
{
    return static_cast<R>(t);
}
void FunctionTemplatesWithMultipleParameters_239()
{
    auto c{func8<int, char>(65)};
    std::cout << c << "\n";

    // auto d{func9<char>(65)}; // error: no matching function for call to ‘func9<char>(int)
    /* note:   template argument deduction/substitution failed:
       note:   couldn’t deduce template parameter ‘S’
       */
    // std::cout << d << "\n";

    auto d{func10<char>(65)}; // T is deduced
    std::cout << d << "\n";
}

template <typename T>
auto func11(T t) -> char
{
    return t; // Implicitly cast to char
}
template <typename T, typename R>
auto func12(T a, R b)
{
    return (a > b) ? a : b; // Return type is deduced compile time to largest type
}
void TemplateReturnTypeDeductionWithAuto_240()
{
    std::cout << func11((65537 + 'C') * 1.0) << "\n";

    std::cout << func12(123.14, 'A') << "\n";
    std::cout << func12(3.14, 'A') << "\n";
}

template <typename T, typename R>
auto func13(T t, R r) -> decltype((t > r) ? t : r);
template <typename T, typename R>
auto func13(T t, R r) -> decltype((t > r) ? t : r)
{
    return (t > r) ? t : r;
}
void DecltypeAndTrailingReturnTypes_241()
{
    decltype((65537 + 'C') * 1.0) a{}; // a is double
    std::cout << typeid(a).name() << "\n";

    std::cout << typeid(func13(123.14, 'A')).name() << "\n"; // Double
    std::cout << typeid(func13(3.14, 'A')).name() << "\n";   //

    using Duplex = decltype((65537 + 'C') * 1.0);
    Duplex x{}; // using Duplex = double
    std::cout << typeid(x).name() << "\n";
}

// template <typename T, typename R> // error: call of overloaded ‘func14(double, char)’ is ambiguous
// auto func14(T t, R r) -> decltype((t > r) ? t : r);
template <typename T, typename R> // Can not be explicitly declared (header file)
decltype(auto) func14(T t, R r)   // -> a trailing return type requires the 'auto' type specifier
{
    return (t > r) ? t : r;
}
void DeclytpeAuto_242()
{
    std::cout << typeid(func14(3.14, 'A')).name() << "\n";
}

template <typename ReturnType = double, typename T, typename R>
ReturnType func15(T t, R r)
{
    return (t > r) ? t : r;
}
template <typename T, typename R, typename ReturnType = double>
ReturnType func16(T t, R r)
{
    return (t > r) ? t : r;
}
void DefaultArguments_243() // default Template Argument!
{
    std::cout << typeid(func15('B', 'A')).name() << "\n"; // Return type defaults to double
    std::cout << typeid(func15<char>('B', 'A')).name() << "\n";

    std::cout << typeid(func16('B', 'A')).name() << "\n"; // Return type defaults to double
    std::cout << typeid(func16<char, char>('B', 'A')).name() << "\n";
    std::cout << typeid(func16<char, char, char>('B', 'A')).name() << "\n"; // Tough to override default return type
}

template <int Size, typename T>
size_t search(T *array, T num)
{
    for (size_t i = 0; i < Size; ++i)
    {
        if (array[i] == num)
            return i;
    }
    return 0; // Not found... BAD!!
}
template <double avg> // floating-point template parameter is nonstandard
bool isGood()
{
    return 3.14 == avg;
}
#include <array>
template <double limit, typename T, size_t Size> // floating-point template parameter is nonstandard, not supported b4 C++20
bool withinLimit(std::array<T, Size> array)
{
    auto sum{0.0};
    for (auto v : array)
        sum += v;
    return (sum <= limit) ? true : false;
}
void NonTypeTemplateParameters_244()
{
    char a[]{"howdydowdy"};
    std::cout << a[search<11, char>(a, 'y')] << "\n";

    // std::cout << std::boolalpha << isGood<3.14f>() << "\n";//error: could not convert ‘3.1400001e+0f’ from ‘float’ to ‘double’
    std::cout << std::boolalpha << isGood<3.14>() << "\n";
    std::cout << std::boolalpha << isGood<3.15>() << "\n";

    using ArType = double;
    constexpr size_t arSz = 5;
    std::array<ArType, arSz> nums{5, 6, 7, 8, 9};

    std::cout << std::boolalpha << withinLimit<100.0, ArType, arSz>(nums) << "\n";
    std::cout << std::boolalpha << withinLimit<10.0, ArType, arSz>(nums) << "\n";
}

// auto func17(auto a) // template<class> auto func17(auto a)
// {
//     return a;
// }
template <typename T>
auto func17(T a) -> decltype(a) // template<class T> auto func17(T a)->T
{
    return a;
}
auto func18(auto a, auto b) { return a + b; }
/* Generated by https://cppinsights.io/
template <>
int func18<char, char>(char a, char b)
{
    return static_cast<int>(a) + static_cast<int>(b);
}*/
void AutoFunctionTemplates_245()
{
    std::cout << std::boolalpha << func17(true) << "\n";
    std::cout << typeid(func18(10.5, 2)).name() << "\n";
    std::cout << typeid(func18('!', ' ')).name() << "\n"; // Upcast to int!
    std::cout << func18('!', ' ') << "\n";
    std::cout << typeid('!').name() << "\n";
    std::cout << typeid('!' + ' ').name() << "\n"; // Upcast to int!
}

/* Generated by https://cppinsights.io/
class __lambda_7_19
{
public:
    template <class type_parameter_0_0, class type_parameter_0_1>
    inline  auto operator()(type_parameter_0_0 a, type_parameter_0_1 b) const
    {
        return a + b;
    }

    template <> // gcc doesn't allow inline template specialization
     int operator()(char a, char b) const
    {
        return static_cast<int>(a) + static_cast<int>(b);
    }

private:
    template <class type_parameter_0_0, class type_parameter_0_1>
    static inline auto __invoke(type_parameter_0_0 a, type_parameter_0_1 b)
    {
        return a + b;
    }

public:
    //  __lambda_7_19() = default;
};*/

void NamedTemplateParametersForLambdas_246()
{

    // __lambda_7_19 func20 = __lambda_7_19{};
    auto func19 = [](auto a, auto b)
    { return a + b; };
    std::cout << typeid(func19('!', ' ')).name() << "\n"; // Upcast to int!

    auto func20 = []<typename T>(T a, T b)
    { return a + b; };
    std::cout << typeid(func20(1ULL, 1ULL)).name() << "\n"; // y seem to represent ULL
    std::cout << typeid(1ULL).name() << "\n";               // y
    std::cout << typeid(1UL).name() << "\n";                // m
    std::cout << typeid(1U).name() << "\n";                 // j
}

#include <type_traits>
template <typename T>
void prnt(T n)
{
    // Both asserts will actually fail if T isn't integral
    static_assert(std::is_integral<T>::value, "Only accepts integer  type values");
    static_assert(std::is_integral_v<T>, "Can only accept integer  type values");
    std::cout << n << "\n";
}
void TypeTraits_247()
{
    std::cout << std::boolalpha;
    std::cout << std::is_integral<decltype(42)>::value << "\n";

    prnt(42);
    // prnt(2.5); // error: static assertion failed: Only accepts integer  type values

    []<typename T>(T n)
    {
        static_assert(std::is_floating_point_v<T>, "Only accepts floatsome  type values");
        std::cout << n << "\n";
    }(4.2);
}

template <typename T>
void HandleNums([[maybe_unused]] T v)
{
    if constexpr (std::is_integral_v<T>)
    {
        std::cout << "Integral!\n";
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        std::cout << "Floater!\n";
    }
    else
        static_assert(std::is_integral_v<T> || std::is_floating_point_v<T>, "Unsupported!");
}
void ConstexprIf_248()
{
    if constexpr (1 < 2)
        static_assert(true);
    if constexpr (1 > 2)
        // static_assert(false, "Not in this universe!");// assert has priority over constexpr if!
        return;
    std::cout << "One is less than 2!\n";
    HandleNums('c');
    HandleNums(4.2);
    // HandleNums(nullptr); // error: static assertion failed: Unsupported!
}

int main()
{
    std::cout << "Section 24: Function Templates\n";
    // TryingOutFunctionTemplates_234();
    // TemplateTypeDeductionAndExplicitArguments_235();
    // TemplateParametersByReference_236();
    // TemplateSpecialization_237();
    // FunctionTemplatesWithOverloading_238();
    // FunctionTemplatesWithMultipleParameters_239();
    // TemplateReturnTypeDeductionWithAuto_240();
    // DecltypeAndTrailingReturnTypes_241();
    // DeclytpeAuto_242();
    // DefaultArguments_243();
    // NonTypeTemplateParameters_244();
    // AutoFunctionTemplates_245();
    // NamedTemplateParametersForLambdas_246();
    // TypeTraits_247();
    ConstexprIf_248();
}