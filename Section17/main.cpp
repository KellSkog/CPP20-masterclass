#include <iostream>
#include "exercise.hpp"

enum class Week : unsigned char
{
    // Mon = -2, error: enumerator value ‘-2’ is outside the range of underlying type ‘unsigned char’
    Mon = 42,
    Tue,
    Wed,
    Thu,
    Sat,
    Sun,
};
void EnumeratedTypesEnumClass_182()
{
    enum class State : signed char
    {
        Off = -1,
        On = 1,
    };
    Week day{Week::Tue};
    std::cout << static_cast<unsigned>(day) << "\n";
    std::cout << static_cast<signed>(State::Off) << "\n";
    std::cout << std::boolalpha << (char{-128} == -128) << "\n"; // char is signed in GCC!
}

void Exercise_29()
{
    print_day(DayOfWeek::Monday);
    DayOfWeek day{9};
    print_day(day);
}

void UsingEnum_183()
{
    Week day{Week::Sun};
    switch (day)
    {
        using enum Week; // Supported in my compiler (GCC 11.1)
    case Sun:
        std::cout << "Sun\n";
        break;
    default:
        std::cout << "Other\n";
    }
}
enum Things : char
{
    Box = 65,
    Chair,
    Table,
};
enum Actions
{
    Lift,
    Push,
    Pull
};
void identify(Things m)
{
    switch (m)
    {
        using enum Things;
    case Box:
        std::cout << Box << "Box\n";
        break;
    case Chair:
        std::cout << "Chair\n";
        break;
    case Table:
        std::cout << "Table\n";
        break;
    }
}
void LegacyEnumeratedTypes_184()
{
    // if (Box == Lift) // error: comparison between ‘enum Things’ and ‘enum Actions’ [-Werror=enum-compare]
    identify(Box);
    // identify(Lift);// argument of type "Actions" is incompatible with parameter of type "Things"
}

void TypeAliases_185()
{
    using Huge = unsigned long long;
    typedef unsigned long long Huge; // Allowed as in agreement!
#define one 1
#define one 1
    // #define one 2 // error: "one" redefined [-Werror]
    [[maybe_unused]] Huge x{3};
}
int main()
{
    std::cout << "Section 17: Enums and Type aliases\n";
    // EnumeratedTypesEnumClass_182();
    // Exercise_29();
    // UsingEnum_183();
    // LegacyEnumeratedTypes_184();
    TypeAliases_185();
}