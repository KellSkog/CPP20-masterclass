#include <iostream>
#include <tuple>
#include <array>
#include <iomanip>

int main()
{
    std::cout << "Section5: " << std::boolalpha << true << std::endl;
    // https://en.cppreference.com/w/cpp/io/manip
    std::array toPrint{
        std::tuple{"Hey", "you", 15},
        std::tuple{"Larry", "Haagman", 33},
        std::tuple{"Bip", "Bop", 7},
    };

    constexpr auto colWidth = 10;
    std::cout << std::left;
    std::cout << std::setfill('~');
    for (auto pp : toPrint)
    {
        auto [a, b, c] = pp;
        std::cout << std::setw(colWidth) << a << std::setw(colWidth) << b << std::setw(colWidth) << c << std::endl;
    }
    std::cout << std::right; // default
    std::cout << std::setw(colWidth) << -3.14 << "\n";
    std::cout << std::internal << std::setw(colWidth) << -3.14 << "\n";

    std::cout << std::showpos;

    std::cout << std::scientific << std::fixed;
    std::cout << 3.1415 << "\n";
    std::cout << std::noshowpos << "\n";
    std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    std::cout << std::setprecision(2) << 314.1415 << "\n";
}