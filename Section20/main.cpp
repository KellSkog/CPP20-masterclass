#include <iostream>

#include "header_only.hpp"
#include "exercise.hpp"

void Ponder(unsigned char x)
{
    std::cout << "Unsigned char: " << x << "\n";
}
void Ponder(char *x)
{
    std::cout << "char *: " << x << "\n";
}
void Ponder(unsigned char &x)
{
    std::cout << "Unsigned char ref: " << x << "\n";
}
void Ponder(int x)
{
    std::cout << "Int: " << x << "\n";
}
void Ponder(float x)
{
    std::cout << "Float: " << x << "\n";
}
void OverloadingWithDifferentParameters_207()
{
    Ponder('a');  // char is signed, promoted to int
    Ponder(true); // Promoted to int
    Ponder(0);
    Ponder(3.14f);
    /*
    more than one instance of overloaded function "Ponder" matches the argument list: 
    -- function "Ponder(unsigned char x)" (declared at line 6) 
    -- function "Ponder(int x)" (declared at line 18) 
    -- function "Ponder(float x)" (declared at line 22) -- argument types are: (double)
    Ponder(3.14); // error: call of overloaded ‘Ponder(double)’ is ambiguous
    */
}
void OverloadingWithPointerParameters_208()
{
    auto q{'Q'};
    auto &q2{q};
    auto *q3{&q};
    Ponder(q);
    Ponder(q2);
    Ponder(q3);
}
void Wonder(double x)
{
    std::cout << "Double: " << x << "\n";
}
void Wonder(int &x)
{
    std::cout << "Int ref: " << x << "\n";
}
void Wonder(int *x)
{
    std::cout << "Int ref: " << x << "\n";
}
void Yonder(std::string name)
{
    std::cout << "std::string name: " << name << "\n";
}
void Yonder(std::string &name)
{
    std::cout << "std::string ref name: " << name << "\n";
}
// void Render(int x)
// {
//     std::cout << "Int: " << x << "\n";
// }
void Render(const int &x)
{
    std::cout << "Int ref: " << x << "\n";
}
void OverloadingWithReferenceParameters_209()
{
    auto a{'A'};
    // Implicit conversion needed, references do not participate in conversion!!!!
    // A ref is a pointer, it isn't possible to use a pointer to int refere to a char!
    Wonder(a); // Promoted to double
    // Wonder(&a); // error: invalid conversion from ‘char*’ to ‘int’ [-fpermissive]

    std::string name{"Kublah Khan"};
    // Yonder(name); //error: call of overloaded ‘Yonder(std::string&)’ is ambiguous

    auto x{42};
    Render(42);
    Render(x); // error: call of overloaded ‘Render(int&)’ is ambiguous
}

void Lender(int x); // const has no effect in a declaration, meaning only in definition
// void Lender(int x);
void Lender([[maybe_unused]] const int x) // Compiles more effectively
{
    // x++;
}
// void Lender([[maybe_unused]] const int x) // error: redefinition of ‘void Lender(int)’
// {}
void OverloadingWithConstParametersByValue_210()
{
    auto a{0};
    Lender(a);
}
/// const int* and int* are different types!
/// int const* and int* are same type
void Sender([[maybe_unused]] int *x)
{
    std::cout << "Ptr to int: " << x << "\n";
}
void Sender([[maybe_unused]] const int *x)
{
    std::cout << "Ptr to const int: " << x << "\n";
}
void OverloadingWithConstPointerAndPointerToConstParameters_211()
{
    auto x{42};
    Sender(&x);
    const auto *y{&x};
    Sender(y);
}

/// const int& and int& are different types!
void Tender([[maybe_unused]] int &x)
{
    std::cout << "Ref to int: " << x << "\n";
}
void Tender([[maybe_unused]] const int &x)
{
    std::cout << "Ref to const int: " << x << "\n";
}
void OverloadingWithConstReferences_212()
{
    auto x{0};
    const auto &y{x};
    Tender(x);
    Tender(y);
}
void Gender(int x = 54)
{
    std::cout << "int: " << x << "\n";
}
void Gender(long x = 45)
{
    std::cout << "Long int: " << x << "\n";
}
void OverloadingWithDefaultParameters_213()
{
    // Gender(); // error: call of overloaded ‘Gender()’ is ambiguous
}

int main()
{
    std::cout << "Section 20: Function Overloading\n\n";
    // OverloadingWithDifferentParameters_207();
    // OverloadingWithPointerParameters_208();
    // OverloadingWithReferenceParameters_209();
    // OverloadingWithConstParametersByValue_210();
    // OverloadingWithConstPointerAndPointerToConstParameters_211();
    // OverloadingWithConstReferences_212();
    OverloadingWithDefaultParameters_213();
}