#include <iostream>

template <typename T>
void dump([[maybe_unused]] T t) {}

void implicitDataConversion_54()
{
    auto earning = 10.0 * 2; // 2 will be up-cast to double
    static_assert(sizeof(earning) == 8);
    char x;
    x = 5; // Implicit narrowing
    static_assert(sizeof(x) == 1);
    x = 2.5;
    std::cout << "Char 2.5 eq. " << static_cast<int>(x) << "\n";
}
void explicitDataConversion_55()
{
    int x = static_cast<int>(2.5 + 2.5);
    int y = static_cast<int>(2.5) + static_cast<int>(2.5);
    std::cout << "Five: " << x << ", Four: " << y << "\n";
}
void overAndUderFlow_56()
{
    unsigned char val = 255;
    val++;
    std::cout << "Overflow. " << static_cast<int>(val) << "\n";
    signed char valium = 0;
    valium--;
    std::cout << "Underflow. " << static_cast<int>(valium) << "\n";
}
int main()
{
    std::cout << "Section 7\n";

    // implicitDataConversion_54();
    // explicitDataConversion_55();
    overAndUderFlow_56();
}