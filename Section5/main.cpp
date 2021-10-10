#include <iostream>
#include <tuple>
#include <array>
#include <limits>
#include <type_traits>
#include <cmath>

template <typename T>
void prettyPrint([[maybe_unused]] T t)
{
    std::cout << typeid(t).name() << ": " << std::numeric_limits<T>::lowest()
              << ", " << std::numeric_limits<T>::min()
              << ", " << std::numeric_limits<T>::max()
              << '\n';
}
void numericLimits_43()
{
    constexpr unsigned short shorty{1};
    constexpr long double longing{1};
    std::tuple toPrint{short{1},
                       shorty,
                       1,
                       unsigned{1},
                       long{1},
                       float{1},
                       double{1},
                       longing};

    std::apply([](auto &&...args)
               { ((prettyPrint(args)), ...); },
               toPrint);
}

double hexagonArea(double side)
{
    return 3 * std::sqrt(3) * side * side / 2.0;
}
double hexagonSide(double area)
{
    return std::sqrt(2.0 * area / 3 / std::sqrt(3));
}
void mathFunctions_44()
{
    // https://en.cppreference.com/w/cpp/header/cmath
    std::cout << "Floor: " << std::floor(0.99) << "\n";
    std::cout << "Ceil: " << std::ceil(0.01) << "\n";
    std::cout << "Abs: " << std::abs(-1) << "\n";
    std::cout << "Abs: " << std::abs(-3.149) << "\n";
    std::cout << "Exp 1: " << std::exp(1) << "\n";
    std::cout << "2^3: " << std::pow(2, 3) << "\n";
    std::cout << "Ln e^3: " << std::log(std::pow(std::exp(1), 3)) << "\n";
    std::cout << "Round down: " << std::round(3.49) << "\n";
    std::cout << "Round: " << std::round(3.5) << "\n";
    std::cout << "Round up: " << std::round(3.51) << "\n";
    std::cout << "Sqrt 3: " << std::sqrt(3) << "\n";
    std::cout << "Hex: " << hexagonArea(6.7) << "\n";
    std::cout << "Hex: " << hexagonSide(116.62764) << "\n";
}
template <typename T>
T add(T a, T b)
{
    return a + b;
}
void weirdIntegralTypes_45()
{
    // smaller numerics than 32 bit are implicitly upcast to do arithmetics!!!
    short a{3}, b{5};
    char c{40}, d{50};
    std::cout << sizeof(a) << ", "
              << sizeof(b) << ", "
              << sizeof(c) << ", "
              << sizeof(d) << "\n";
    std::cout << sizeof(add(a, b)) << ", "
              << sizeof(add(c, d)) << "\n";
    std::cout << sizeof(a + b) << ", "
              << sizeof(c + d) << "\n";
}
double CelsiusToFarenheit(double celsius)
{
    return 9.0 / 5.0 * celsius + 32;
}
void tempCalc()
{
    double celsius;
    std::cout << "Please enter temperature in Celsius (e.g. 20.5):"
              << "\n";
    std::cin >> celsius;
    std::cout << celsius << " degrees equals " << CelsiusToFarenheit(celsius) << " Farenheit."
              << "\n";
}
constexpr double rectangleArea(const double length, const double with)
{
    return length * with;
}
void calcBoxVolume()
{
    double length, width, height;
    std::cout << "Enter box length: ";
    std::cin >> length;
    std::cout << "Enter box width: ";
    std::cin >> width;
    std::cout << "Enter box height: ";
    std::cin >> height;
    const auto baseArea = rectangleArea(length, width);
    std::cout << "Base area: " << baseArea << "\n";
    std::cout << "Volume: " << baseArea * height << "\n";
}
int main()
{
    std::cout << "Section5: " << std::boolalpha << true << std::endl;
    // https://en.cppreference.com/w/cpp/io/manip
    // numericLimits_43();
    // mathFunctions_44();
    // weirdIntegralTypes_45();
    calcBoxVolume();
}