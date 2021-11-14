#include <iostream>
#include "exercise.hpp"

void PrintIt(auto F)
{
    F(13); // A Lambda captures from the scope it was created in
}
void DeclaringAndUsingLambdaFunctions_216()
{
    int x = 42;
    PrintIt([&x](int y)
            { std::cout << (x += y) << "\n"; });
    auto F = [](int x)
    { std::cout << x << "\n"; };
    F(x);

    [x]()
    { std::cout << x << "\n"; }();

    [](auto x)
    { std::cout << x << "\n"; }(x);

    auto z = [](int x, int y) //-> double
    { return x + y + 0.5; }(40, 2);
    std::cout << z << "\n";
}
#include <tuple>
void CaptureLists_217()
{
    std::pair<int, int> q{1, 0};
    auto func = [=]() // Captures everything by value, & would capture by ref
    { return std::pair<int, int>{q.second, q.first}; };
    auto r = func();
    std::cout << r.first << ", " << r.second << "\n";
}

int main()
{
    std::cout << "Section 21: Lambda Functions\n";
    // DeclaringAndUsingLambdaFunctions_216();
    CaptureLists_217();
}