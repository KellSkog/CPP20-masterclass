#include <iostream>
#include "exercise.hpp"

int sum(int a, int b)
{
    return a + b;
}
void DebuggingInVsCode_228()
{
    int a = 1;
    int b = 3;
    int result = sum(a, b);
    std::cout << result << "\n";
}

int main()
{
    std::cout << "Section 23: Function call stack and debugging\n";
    DebuggingInVsCode_228();
}