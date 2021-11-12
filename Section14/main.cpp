#include <array>
#include <iostream>

void DeclaringAndUsingReferences_131()
{
    int x{42};
    auto &xx{x};
    std::cout << xx << ", " << sizeof(xx) << "\n";

    auto *x2{&x};
    auto &xxx{x2};
    std::cout << *xxx << ", " << sizeof(xxx) << "\n";
}

void refs()
{

    int value1{33};

    //Don't modify anything above this line
    //Your code will go below this line
    auto &ref_value1{value1};
    //Your code will go above this line
    //Don't modify anything below this line

    std::cout << value1 << ref_value1;
}
void exercise_18()
{
    refs();
}

void ReferencesAndConst_133()
{
    int alpha{42};
    const int &r_alpha{alpha};
    std::cout << &r_alpha << ", " << &alpha << "\n";
    // r_alpha = 0; expression must be a modifiable lvalueC/C++(137)
    alpha = 0;
    std::cout << r_alpha << "\n";
    // const int beta = 0;
    // int &r_beta = beta; qualifiers dropped in binding reference of type "int &" to initializer of type "const int"C/C++(433)
}

void ReferencesWithRangeBasedForLoops_134()
{
    std::array<int, 5> alpha{1, 2, 3, 4, 5};
    for (auto &ref : alpha)
    {
        ref = 0;
    }
    for (auto ref : alpha)
    {
        std::cout << ref << ", ";
    }
}

int main()
{
    std::cout << "Section 14: References\n";
    // DeclaringAndUsingReferences_131();
    // exercise_18();
    // ReferencesAndConst_133();
    ReferencesWithRangeBasedForLoops_134();
}