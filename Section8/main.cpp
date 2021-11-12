#include <iostream>
#include <bitset>
#include <typeinfo>
#include <cxxabi.h>
#include <array>
#include <utility>
#include <stdint.h>

template <typename T>
void dump([[maybe_unused]] T t) {}

void bitwiseOperators_59()
{
    auto data{0b11111110};
    auto intData{65};
    std::cout << "Base: " << std::hex << data << "\n";
    std::cout << "Base: " << std::showbase << std::hex << data << "\n";
    std::cout << "Base: " << std::hex << data << "\n"; // showbase persists
    std::cout << "Data(bin): " << std::bitset<16>(data) << "\n";
    std::cout << "intData(bin): " << std::bitset<7>(intData) << "\n";
}
void types()
{
    int status;
    char data{};
    char *realname = abi::__cxa_demangle(typeid(data).name(), nullptr, nullptr, &status);
    std::cout << "Type: " << *realname << " => " << typeid(data).name() << "\n";

    signed char data1{};
    realname = abi::__cxa_demangle(typeid(data1).name(), nullptr, nullptr, &status);
    std::cout << "Type: " << *realname << " => " << typeid(data1).name() << "\n";

    unsigned short data2{};
    realname = abi::__cxa_demangle(typeid(data2).name(), nullptr, nullptr, &status);
    std::cout << "Type: " << *realname << " => " << typeid(data2).name() << "\n";

    signed short data3{};
    realname = abi::__cxa_demangle(typeid(data3).name(), nullptr, nullptr, &status);
    std::cout << "Type: " << *realname << " => " << typeid(data3).name() << "\n";

    signed data4{};
    realname = abi::__cxa_demangle(typeid(data4).name(), nullptr, nullptr, &status);
    std::cout << "Type: " << *realname << " => " << typeid(data4).name() << "\n";

    free(realname);
}
void shiftOperators_60()
{
    unsigned short data{0x8001};
    [[maybe_unused]] auto shifted = data << 1; // bitwise operators return an int
    data <<= 1;
    std::cout << "Type: " << typeid(data).name() << "\n";
    std::cout << "Base: " << std::hex << data << ", " << std::hex << static_cast<short unsigned>(data) << "\n";
    data >>= 1;
    std::cout << "Base: " << std::hex << static_cast<short unsigned>(data) << "\n";
    int d{INT32_MIN};
    d >>= 4; // Sign bit is shifted in
    std::cout << "d >>= 4 " << std::hex << d << "\n";
}
void bitwiseLogical_61()
{
    std::cout << " 1100 | 0011 -> " << std::bitset<4>(0b1100 | 0b0011) << "\n";
    std::cout << " 1100 & 0011 -> " << std::bitset<4>(0b1100 & 0b0011) << "\n";
    std::cout << " 0101 ^ 0011 -> " << std::bitset<4>(0b0101 ^ 0b0011) << "\n";
    std::cout << " ~1100 -> " << std::bitset<4>(~0b1100) << "\n";
}
void compoundBitwiseAssign()
{
    int var1{0b1010};
    [[maybe_unused]] int var2{0b0110};
    var1 <<= 2;
    std::cout << " var1 <<= 2 -> " << std::bitset<4>(var1) << "\n";
    var1 |= var2;
    std::cout << " var1 |= var2 -> " << std::bitset<4>(var1) << "\n";
}
void masks_63()
{
    constexpr auto mask{std::array<int, 4>{0b0001, 0b0010, 0b0100, 0b1000}};
    for (auto m : mask)
    {
        std::cout << "0b1111 & " << std::bitset<4>(m) << ": " << std::bitset<4>(0b1111 & m) << "\n";
    }
    std::cout << "Clearing a bit\n";
    std::cout << "0b1111 & ~bit2: " << std::bitset<4>(0b1111 & ~mask[2]) << "\n";
    std::cout << "Toggeling a bit\n";
    for (auto m : mask)
    {
        std::cout << "0b1011 ^ " << std::bitset<4>(m) << ": " << std::bitset<4>(0b1011 ^ m) << "\n";
    }
    int bigTog = 0b1010 ^ (mask[0] | mask[1] | mask[2] | mask[3]);
    std::cout << "Toggle all bits of 1010: " << std::bitset<4>(bigTog) << "\n";
}
void masks_64(char mask)
{
    std::cout << std::bitset<4>(mask) << " & 0b1100 " << std::bitset<4>(mask & 0b1100) << "\n";
    std::cout << std::bitset<4>(mask) << " | 0b1100 " << std::bitset<4>(mask | 0b1100) << "\n";
}
class Color
{
public:
    static constexpr std::pair<int, int> RED{0xFF000000, 24};
    static constexpr std::pair<int, int> GREEN{0x00FF0000, 16};
    static constexpr std::pair<int, int> BLUE{0x0000FF00, 8};
    static constexpr std::pair<int, int> ALPHA{0x000000FF, 0};
    Color(const unsigned color) : color_{color} {}
    auto operator[](std::pair<int, int> mask) { return static_cast<unsigned char>((color_ & mask.first) >> mask.second); }

private:
    unsigned color_;
};
void packingColorInformation_65()
{
    Color grey{0x808080FF};
    std::cout << "Red component: " << std::showbase << std::hex << static_cast<int>(grey[Color::RED]) << "\n";
    std::cout << "Green component: " << static_cast<int>(grey[Color::GREEN]) << "\n";
    std::cout << "Blue component: " << static_cast<int>(grey[Color::BLUE]) << "\n";
    std::cout << "Alpha component: " << static_cast<int>(grey[Color::ALPHA]) << "\n";
    std::cout << std::noshowbase << std::dec; // Both are persistant!
}

int main()
{
    std::cout << "Section 8: Bitwise Operators\n";

    // implicitDataConversion_54();
    // explicitDataConversion_55();
    // bitwiseOperators_59();
    // types();
    // shiftOperators_60();
    // bitwiseLogical_61();
    // compoundBitwiseAssign();
    // masks_63();
    // masks_64(0b0110);
    // masks_64(0b1001);
    // packingColorInformation_65();
}