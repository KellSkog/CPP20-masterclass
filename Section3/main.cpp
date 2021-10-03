#include <array>
#include <exception>
#include <iostream>
#include <iomanip>
#include <ranges>
#include <string_view>
#include <stdint.h>

consteval auto sqr(int x) { return x * x; }
constexpr std::string_view myName = "Kell Skogh";

void printNameRepeat(std::string_view myName, int repetitions)
{
    for (int i = 0; i < repetitions; i++)
    {
        std::cout << myName << "\n";
    }
}
void printStuff()
{
    std::string fullName;
    std::cout << "Enter name\n";
    std::getline(std::cin, fullName);
    std::istringstream names;
    names.str(fullName);
    for (std::string line; std::getline(names, line, ' ');)
    {
        std::cout << line << ' ';
    }
    std::cout << std::endl;
}
void tryCatch()
{
    try
    {
        // auto z = 7 / den; // Generates Floating point signal, not an exception
        throw std::runtime_error("All bad");
    }
    catch (const std::exception &ex)
    {
        std::cerr
            << ex.what()
            << "\n";
    }

    std::clog << "All done and dusted\n";
}
void getInput()
{
    int num;
    std::cout << "Gimme a num\n";
    std::cin >> num;
    std::cout << "Twice = " << 2 * num << std::endl;
}
void assignment1()
{
    /*
    Program prints : Where do you live?

    User types : Finland

    Program prints : I've heard great things about Finland. I'd like to go sometime.
    */
    std::string country;
    std::cout << "Where do you live? ";
    std::cin >> country;
    std::cout << "I've heard great things about " << country << ". I'd like to go sometime." << std::endl;
}
int main()
{
    // constexpr int count = 10;
    // printNameRepeat(myName, count);
    // printStuff();
    // tryCatch();
    // getInput();
    // int narrowed(2.9);
    // // int narrowed{2.9};
    // uint8_t value(-1);
    // std::cout << value << "\n";

    assignment1();
}