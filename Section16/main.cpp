#include <iostream>
#include "exercise.hpp"
void Exercise_25()
{
    std::cout << digit_sum(62727289) << ", " << digit_sum(79) << "\n";
}

void Exercise_26()
{
    show_odds(98723713);
}

void Exercise_27()
{
    std::cout << std::boolalpha << is_palindrome(123454321) << "\n";
    std::cout << std::boolalpha << is_palindrome(12344321) << "\n";
    std::cout << std::boolalpha << is_palindrome(123454320) << "\n";
    std::cout << std::boolalpha << is_palindrome(12344320) << "\n";
}

void do_stuff(int *a, [[maybe_unused]] int *b)
{
    std::cout << a << "\n";
    (*a++);
    std::cout << a << "\n";
}

// void ByConstRef(int &const x) // error: ‘const’ qualifiers cannot be applied to ‘int&’
// {}
void ByConstRef([[maybe_unused]] int const &x)
{
    // x++; // error: increment of read-only reference ‘x’
}

void Exercise_28()
{
    char message[]{"Hello there"};
    find_character(message, std::size(message), 'o');
    std::cout << "\n";
    find_character(message, std::size(message), 'P');
}
constexpr unsigned kIgnoredValue{1234567890};
void sum([[maybe_unused]] int x[kIgnoredValue]) // decays to void sum(int*)
{
}
void summer([[maybe_unused]] int x[1]) // decays to void sum(int*)
{
}
// void summer([[maybe_unused]] int x[0]) // error: ISO C++ forbids zero-size array ‘x’ [-Werror=pedantic]
// {}
// void sum([[maybe_unused]] int *x) // error: redefinition of ‘void sum(int*)’
// {}
void SizeArrayRef([[maybe_unused]] const int (&thing)[5]) // error: invalid initialization of reference of type ‘const int (&)[6]’ from expression of type ‘int [5]’
{
}

#include <array>
template <typename T, int N>
void TheRealStuff([[maybe_unused]] std::array<T, N> &r)
{
}
void Experiment1()
{
    int aarg[]{1, 2, 3, 4, 5};
    sum(aarg);
    summer(aarg);
    SizeArrayRef(aarg);
    std::array<int, 5> bup{1, 2, 3, 4, 5};
    TheRealStuff<int, 5>(bup);
}
template <int I, int J, int K>
int sum3d(const int nums[I][J][K])
{
    int sum{};
    for (int i = 0; i < I; ++i)
    {
        for (int j = 0; j < J; ++j)
        {
            for (int k = 0; k < K; ++k)
            {
                sum += nums[i][j][k];
            }
        }
    }
    return sum;
}
void Experiment2()
{
    /**
     * nums contains 2 rows of int[3]
     */
    int nums[2][3][4]{
        {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 0xA, 0xB, 0xC}},
        {{1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 0xA, 0xB, 0xC}}};
    std::cout << std::size(nums) << ", " << sum3d<2, 3, 4>(nums) << "\n";
}
void DefaultFunctionArguments_172()
{
    std::cout << compute() << "\n";
}

void TheNothing([[maybe_unused]] int &gobledigook)
{
}
void TheSomething([[maybe_unused]] int &gobledigook)
{
}
void TheSomething([[maybe_unused]] const int &gobledigook)
{
    std::cout << &gobledigook << "\n"; // Referes to a temporary converted double -> int
}
void ImplicitConversionsWithReferences_174()
{
    auto val{30.5};
    // TheNothing(val); // a reference of type "int &" (not const-qualified) cannot be initialized with a value of type "double"
    std::cout << &val << "\n";
    TheSomething(val); // Will pick the function that is most apropriate
}
void TheOther([[maybe_unused]] int *p)
{
}
void sum([[maybe_unused]] const int &a)
{
}
void ImplicitConversionsWithPointers_175()
{
    auto p{30};
    TheOther(&p);
    /**
     * Pointers can not be converted to point to data of different size
     */
    auto p2{30.5};
    // TheOther(&p2); // argument of type "double *" is incompatible with parameter of type "int *"
    sum(p2);
}
void SayMyName(std::string &name)
{
    std::cout << name << "\n";
}
void SayMyOtherName(const std::string &name)
{
    std::cout << name << "\n";
}
void SaySomeName(std::string_view name)
{
    std::cout << name << "\n";
}
void string_viewParameters_176()
{
    std::string name{"Kubla Kahn"};
    SayMyName(name);
    // SayMyName("Kubla Kahn") // a reference of type "std::string &" (not const-qualified) cannot be initialized with a value of type "const char [11]"
    SayMyOtherName("Kubla Kahn"); // Uses a temporary conversion variable
    SaySomeName("Kubla Kahn");
    SaySomeName(name);
    SaySomeName(std::string_view(name));
}

void ImplicitConversionsFromStdString_viewToStdString_177()
{
    /* A string_view is a pointer and a size, concocted to minimize copying of strings
     * converting a string_view to a string necessitates copying
     counteracting its intention */
    std::string_view words{"Jabadabadoo bip bop"};
    //  SayMyName(words);// a reference of type "std::string &" (not const-qualified) cannot be initialized with a value of type "std::string_view"
    SayMyOtherName(std::string(words)); // Explicit copy
}

void ConstexprFunctions_178()
{
}
consteval int getter(int x) { return x; }
void ConstevalFunctions_179()
{
    [[maybe_unused]] int x = getter(42);
    // [[maybe_unused]] int y = getter(x); // call to consteval function "getter" did not produce a valid constant expression -- the value of variable "x" (declared at line 179) cannot be used as a constant
}

int main()
{
    std::cout << "Section 16\n";
    // Exercise_25();
    // Exercise_26();
    // Exercise_27();
    // TakesConst(42); // Calls void TakesConst(const int &x);
    // int x{42};
    // TakesConst(x); // Calls void TakesConst(int &x);
    // int x{3};
    // int y{4};
    // do_stuff(&x, &y);
    // std::cout << x << std::endl;
    // ByConstRef(x);
    // Exercise_28();
    // Experiment2();
    // DefaultFunctionArguments_172();
    // ImplicitConversionsWithReferences_174();
    // ImplicitConversionsWithPointers_175();
    // string_viewParameters_176();
    // ImplicitConversionsFromStdString_viewToStdString_177();
    // ConstexprFunctions_178();
    ConstevalFunctions_179();
}