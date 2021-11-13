#include <iostream>
#include <array>
#include "exercise.hpp"
void exercise_30()
{
    int data[]{2, 4, 6, 8, 11};
    bool result;
    is_sum_even(data, std::size(data), result);
    if (result)
        std::cout << "Even!\n";
    else
        std::cout << "How odd!\n";
}
void ReturningFromFunctionsByValue_194()
{
    std::string first{"Howdy"};
    std::string second{"Dowdy"};
    std::string res = AddStrings(first, second);
    std::cout << res << " @: " << &res << "\n";
    /* res is assigned the address of AddString local variable!
    * Concat @: 0x7ffcf9d34130
    * res @: 0x7ffcf9d34130 */
}
int &returner(int &a, int &b)
{
    // int x{42};
    // return x; // error: reference to local variable ‘x’ returned [-Werror=return-local-addr]
    return (a > b) ? a : b;
}
void ReturningByReference_195()
{
    int a{3}, b{2};
    std::cout << "a: " << &a << ", b: " << &b << "\n";
    int &c = returner(a, b);
    int d = returner(a, b);
    std::cout << "c: " << &c << ", d: " << &d << "\n";
}
void ReturningByPointer_196()
{
}
template <typename T, int N>
const double *GetPtrToMax(const std::array<T, N> *data)
{
    int max{-2000000000};
    unsigned maxindex{};
    for (int i = 0; i < N; ++i)
    {
        if ((*data)[i] > max)
        {
            max = (*data)[i];
            maxindex = i; // a value of type "const double *" cannot be assigned to an entity of type "double *"
        }
    }
    return data->data() + maxindex;
}
template <typename T, int N>
const double *GetPtrToMax(const std::array<T, N> &data)
{
    int max{-2000000000};
    unsigned maxindex{};
    for (int i = 0; i < N; ++i)
    {
        if (data[i] > max)
        {
            max = data[i];
            maxindex = i;
        }
    }
    return data.data() + maxindex;
}
void ReturningArrayElementPointer_197()
{
    std::array<double, 5> nums{1.5, 2.7, 3.14, 2.78, 0.0};
    std::cout << *GetPtrToMax<double, 5>(nums) << "\n";
    std::cout << sizeof(nums) << ", " << std::size(nums) << ", " << &nums << "\n";
    std::cout << *GetPtrToMax<double, 5>(&nums) << "\n";
    std::cout << sizeof(nums) << ", " << std::size(nums) << ", " << &nums << "\n";
}
void BareAutoTypeDeduction_198()
{
    [[maybe_unused]] auto x{42};  //int
    [[maybe_unused]] auto c{'@'}; // char
    auto d{3.14};                 // double
    const auto &dd{d};            // Deduced as const ref to double
    // dd++; // error: increment of read-only reference ‘dd’
    auto dd2{&d}; // Deduced to pointr
    auto ddd{dd}; // Not deduced as ref to double but just double
    auto ddd2{dd2};
    ddd += 1.5;
    *ddd2 -= 1.5;
    std::cout << ddd << " != " << d << "\n";
    std::cout << *ddd2 << " == " << d << "\n";
}
enum class Types
{
    Bool,
    Char,
    Float,
    Double,
};
/**
 * return int or double type
 */
auto process(Types om) -> char // All return types are cast to char
{
    switch (om)
    {
        using enum Types;
    case Double:
        return 2.81;
    case Float:
        return 3.14f;
    case Char:
        return 'A'; // error: inconsistent deduction for auto return type: ‘bool’ and then ‘char’
    case Bool:
        return true;
    // } // error: control reaches end of non-void function [-Werror=return-type]
    default:
        return 0;
    }
}
#include <typeinfo>
template <typename T>
auto process() -> T
{

    if (typeid(T) == typeid(double))
        return 2.81;
    if (typeid(T) == typeid(float))
        return 3.14f;
    if (typeid(T) == typeid(char))
        return 'A'; // error: inconsistent deduction for auto return type: ‘bool’ and then ‘char’
    if (typeid(T) == typeid(bool))
        return true;
    return static_cast<T>(0);
}
void FunctionReturnTypeDeduction_199()
{
    auto a{process(Types::Float)};
    std::cout << a << ", " << sizeof(a) << "\n";
    auto b{process(Types::Char)};
    std::cout << b << ", " << sizeof(b) << "\n";
    auto c{process(Types::Bool)};
    std::cout << c << ", " << sizeof(c) << "\n";

    auto aa{process<float>()};
    std::cout << aa << ", " << sizeof(aa) << "\n";
    auto bb{process<double>()};
    std::cout << bb << ", " << sizeof(bb) << "\n";
    auto cc{process<bool>()};
    std::cout << cc << ", " << sizeof(cc) << "\n";
}
// max returns a copy e.g. 'int', not a reference!
auto max(auto &a, auto &b)
{
    return (a > b) ? a : b;
}
// min returns a ref!
auto &minRef(auto &a, auto &b)
{
    return (a < b) ? a : b;
}
void ReturnTypeDeductionWithReferences_200()
{
    auto a{1};
    auto b{2};
    auto c = max(a, b);
    auto &d = minRef(a, b); // d is a reference to a
    std::cout << &b << ", " << &c << "\n";
    ++d;
    std::cout << a << ", " << &a << ", " << &d << "\n";
}
#include "header_only.hpp"
void FunctionDefinitionsWithReturnTypeDeduction_201()
{
    auto r{q()}; // error: use of ‘auto q()’ before deduction of ‘auto’
    std::cout << r << ", " << sizeof(r) << "\n";
}
void OptionalOutputFromFunctions_202()
{
    // blah blah blah
}
#include <optional>
template <typename T>
std::optional<T> possible(bool om)
{
    if (om)
        return static_cast<T>(42);
    else
        return std::nullopt;
}
void IntroducingStdOptional_203()
{
    auto hasVal = possible<int>(true);
    auto hasNoVal = possible<double>(false);
    if (hasVal)
        std::cout << *hasVal << "\n";
    std::cout << hasNoVal.value_or(-1) << "\n";

    std::optional<std::string> catsName{}; // Initialized to std::nullopt
    std::optional<std::string> myName{"Kell Skog"};
    std::optional<std::string> noName{std::nullopt};
    // std::cout << catsName.value() << "\n"; // terminate called after throwing an instance of 'std::bad_optional_access'
    if (catsName)
        std::cout << catsName.value() << "\n";
    if (myName.has_value())
        std::cout << *myName << "\n";
    noName = std::string{"Incognitius"};
    noName = "Anonymus";
    std::cout << noName.value_or("nullopt\n") << "\n";

    std::cout << std::boolalpha << catsName.has_value() << "\n";
}
void OptionalOutputWithStdOptional_204()
{
    std::string sentence{"It is quickly drawing darker outside now that the sun settles early"};
    auto pos{FindCharacterV2(sentence, 'h')};

    if (pos.has_value())
        std::cout << sentence[pos.value()] << " @ " << pos.value() << "\n";
}

/* https://stackoverflow.com/questions/24621954/deduced-conflicting-types-for-parameter-t-for-universal-reference
The reason universal references match everything is because the template argument deduction rules say that when 
T && is paired with an lvalue of type X, T is deduced to be X&, and then reference collapsing makes X& && become X& */

int main()
{
    std::cout << "Section 19: Getting things out of functions \n";
    // exercise_30();
    // ReturningFromFunctionsByValue_194();
    // ReturningByReference_195();
    // ReturningByPointer_196();
    // ReturningArrayElementPointer_197();
    // BareAutoTypeDeduction_198();
    // FunctionReturnTypeDeduction_199();
    // ReturnTypeDeductionWithReferences_200();
    // FunctionDefinitionsWithReturnTypeDeduction_201();
    // OptionalOutputFromFunctions_202();
    // IntroducingStdOptional_203();
    OptionalOutputWithStdOptional_204();
}