#include <iostream>
#include <array>
#include <type_traits>

namespace
{
    enum class Colors
    {
        RED,
        GREEN,
        BLUE,
        YELLOW,
    };
    enum class PoliceSign
    {
        None,
        Stop,
        Go
    };
} // namespace

[[maybe_unused]] void ifStatement_70(Colors color)
{
    std::string card;
    if (color == Colors::RED)
    {
        card = "Red card for you\n";
    }
    else if (color == Colors::GREEN)
    {
        card = "Green card for you\n";
    }
    bool notRedOrGreen = !((color == Colors::RED) || (color == Colors::GREEN));
    if (notRedOrGreen)
    {
        card = "Probably Blue\n";
    }
    std::cout << card;
}

[[maybe_unused]] void ifStatement_70b(Colors color, PoliceSign sign = PoliceSign::None)
{
    if (sign == PoliceSign::Stop)
        std::cout << "Stop on policemans sign!\n";
    else if (color == Colors::GREEN)
        std::cout << "Go!\n";
    else if (color == Colors::YELLOW)
        std::cout << "Stop on Yellow!\n";
    else
        std::cout << "Stop on Red!\n";
}

[[maybe_unused]] void switchStatement_72(const Colors color)
{
    std::string msg;
    switch (color)
    {
    case Colors::BLUE:
    {
        [[maybe_unused]] int x = 0; // Initialisation only within block
        msg = "For sure Blue";
        break;
        break;
    }
    break;
        break;
    case Colors::GREEN:
        // [[maybe_unused]] int y = 0; error: jump to case label note: crosses initialization of ‘int y’
        msg = "For sure Green";
        break;
    case Colors::RED:
        msg = "For sure Red";
        break;
    default:
        msg = "Probably yellow";
    }
    std::cout << msg << "\n";
}

/**
 * år som är jämnt delbara med 4, förutom de sekelår som inte är jämnt delbara med 400.
 * Ett sekelår är jämnt delbart med 100
 */
[[maybe_unused]] bool is_leap_year(unsigned int year)
{
    bool isLeap{};
    if (year % 100 == 0) // A century year e.g. 2000
        isLeap = ((year % 400) == 0);
    else
        isLeap = ((year % 4) == 0);

    return isLeap;
}
[[maybe_unused]] void leapYears()
{
    std::array<unsigned, 8> years{
        1700,
        1800,
        1900,
        1600,
        2000,
        1974,
        2016,
        2020,
    };
    for (auto year : years)
    {
        std::cout << year;
        if (is_leap_year(year))
            std::cout << " is Leap year\n";
        else
            std::cout << " is Normal year\n";
    }
}

[[maybe_unused]] void shortCircuits_73()
{
    int a{0};
    if (a > 0 && (++a > 0))
        a++;
    else
        std::cout << " ++a not executed: " << a << "\n";
    std::cout << "First a: " << a << "\n";
    if (a == 0 || (++a > 0))
        std::cout << " ++a not executed: " << a << "\n";
    else
        a++;
    std::cout << "Final a: " << a << "\n";
}

bool hasCar()
{
    std::cout << "Car\n";
    return true;
}
bool hasHouse()
{
    std::cout << "House\n";
    return true;
}
bool hasJob()
{
    std::cout << "Job\n";
    return false;
}
bool hasWife()
{
    std::cout << "Wife\n";
    return true;
}
[[maybe_unused]] void shortCircuits_73b()
{
    if (hasCar() && hasHouse() && hasJob() && hasWife())
        std::cout << "Happy\n";
    else
        std::cout << "Sad\n";
    std::cout << "\n";
    if (hasCar() || hasHouse() || hasJob() || hasWife())
        std::cout << "Worried\n";
    else
        std::cout << "Calm\n";
}

[[maybe_unused]] void IntegerLogicConditions_74()
{
    for (int i = -1; i <= 1; i++)
    {
        std::cout << std::boolalpha << static_cast<bool>(i) << "\n";
    }
}

[[maybe_unused]] void TernaryOperations_76()
{
    std::string text;
    for (int i = -1; i <= 1; i++)
    {
        text = static_cast<bool>(i) ? "TrUe" : "FaLsE";
        std::cout << text << "\n";
    }

    auto Integer = true ? 1 : 3.14; // Integer is of type double!
    auto Double = false ? 1 : 3.14;
    std::cout << Integer << ", " << Double << "\n";
    std::cout << std::boolalpha << std::integral<decltype(Integer)> << "\n";
    /**
     * https://en.cppreference.com/w/cpp/language/operator_other
     * 6.2) If both E2 and E3 have arithmetic or enumeration type: 
     * the usual arithmetic conversions are applied to bring them to common type, 
     * and that type is the result.
     */
}

[[maybe_unused]] void IfConstexp_76()
{
    // Compile time computation
    constexpr auto UseDouble{false};

    if constexpr (UseDouble)
    {
        // Include ony one of options in target code, both have to compile!
    }
    else
    {
        std::cout << "The code will exclude use of double\n";
    }
}

struct Stuff
{
    Stuff(int x) : x{x} {};
    int getX() { return x; }

private:
    int x;
};

Stuff stuff{42};
[[maybe_unused]] void IfWithInitializer_77()
{
    if (int x = stuff.getX(); x == 42)
    {
        std::cout << "Meaning of life\n";
    } // x1 goes out of scope
}

[[maybe_unused]] void SwitchInitializer_77(Colors color)
{
    switch (int x = stuff.getX(); color)
    {
    case Colors::RED:
        std::cout << "RED " << x << "\n";
        [[fallthrough]]; // Green
    case Colors::BLUE:
        std::cout << "Blue\n";
        break;
    default: // Yellow
        std::cout << "Not red\n";
    } // x goes out of scope
}
[[maybe_unused]] int x;
[[maybe_unused]] void VariableScopeRevisited_79()
{
    [[maybe_unused]] int x; // Shadows global x
    if (true)
        [[maybe_unused]]
        int x; // Shadows funcions x
    else
        [[maybe_unused]]
        int x; // Shadows funcions x
    //x++; If and else has different scope, surprise surprise
}

[[maybe_unused]] void SwitchScope_80()
{
    [[maybe_unused]] int x{42};
    // The entire switch is one common scope!
    switch (x)
    {
        // std::cout << "B4 first case\n"; error: statement will never be executed
        [[maybe_unused]] int y; //No code is ever going to executed between switch() and first case..:
                                // But this declarion does no pose a risk of failing initialization!
    case 42:                    // Definitions (e.g. int x{}) are not guarnteed to run, hence not allowed!
        y = 0;
        {
            [[maybe_unused]] int x{99}; //Separate scope, initialization before use is guaranteed!
        }
        break;
    default:
        [[maybe_unused]] int x{}; // Guarnteed to never be used unitialized
    }
}
[[maybe_unused]] void Assignment_4()
{
    int number;
    std::cout << "Please type in an integral value :\n";
    std::cin >> number;
    bool isEven = (number % 2) == 0;
    std::string eveness = isEven ? " is even" : " is odd";
    std::cout << number << eveness << "\n";
}

[[maybe_unused]] void Assignment_5()
{
    constexpr unsigned MinAge{21};
    constexpr unsigned MaxAge{39};
    std::cout << "Please type in your age : \n";
    unsigned age;
    std::cin >> age;
    if (age >= MinAge)
    {
        if (age <= MaxAge)
            std::cout << "You are eligible for the treatment\n";
        else
            std::cout << "You are too old for the treatment\n";
    }
    else
        std::cout << "You are too young for the treatment\n";
}

void printDay(std::string day)
{
    std::cout << "Today is " << day << ". Let's have some fun.\n";
}
[[maybe_unused]] void Assignment_6()
{
    std::cout << "Which day is today [1 : Monday,..., 7 : Sunday] :\n";
    int day;
    std::cin >> day;
    switch (day)
    {
    case 1:
        printDay("Monday");
        break;
    case 2:
        printDay("Tuesday");
        break;
    case 3:
        printDay("Wednesday");
        break;
    case 4:
        printDay("Thursday");
        break;
    case 5:
        printDay("Friday");
        break;
    case 6:
        printDay("Saturday");
        break;
    case 7:
        printDay("Sunday");
        break;
    default:
        std::cout << day << " is not a valid day. Bye!\n";
    }
}
void printTheDay(int day)
{
    switch (day)
    {
    case 1:
        std::cout << "Monday\n";
        break;
    case 2:
        std::cout << "Tuesday\n";
        break;
    case 3:
        std::cout << "Wednesday\n";
        break;
    case 4:
        std::cout << "Thursday\n";
        break;
    case 5:
        std::cout << "Friday\n";
        break;
    case 6:
        std::cout << "Saturday\n";
        break;
    case 7:
        std::cout << "Sunday\n";
    }
}
[[maybe_unused]] void Assignment_7()
{
    std::cout << "Which day is today [1 : Monday,..., 7 : Sunday] :\n";
    int day;
    std::cin >> day;
    if (day >= 1 && day <= 7)
    {
        std::cout << "How many days have passed up to today :\n";
        int days;
        std::cin >> days;
        int earlierDay = day - (days % 7);
        if (earlierDay < 1)
            earlierDay += 7;
        std::cout << "Today is ";
        printTheDay(day);
        std::cout << "If we went " << days << " days in the past we would hit a ";
        printTheDay(earlierDay);
    }
    else
        std::cout << day << " is not a valid day. Bye!\n";
}
[[maybe_unused]] void Assignment_8()
{
    constexpr double MinX{-10.0};
    constexpr double MinY{-5.0};
    constexpr double MaxX{10.0};
    constexpr double MaxY{5.0};
    std::cout << "Welcome to territory control. Please enter your x and y positions\n";
    double x, y;
    std::cout << "Type in your x location :\n";
    std::cin >> x;
    std::cout << "Type in your y location :\n";
    std::cin >> y;
    if (x >= MinX && x <= MaxX && y >= MinY && y <= MaxY)
        std::cout << "You are completely surrounded. Don't move!\n";
    else
        std::cout << "You're out of reach!\n";
}
int main()
{
    std::cout << "Section 10\n";
    // ifStatement_70(Colors::RED);
    // ifStatement_70(Colors::BLUE);
    // ifStatement_70b(Colors::RED);
    // ifStatement_70b(Colors::GREEN);
    // ifStatement_70b(Colors::GREEN, PoliceSign::Stop);
    // switchStatement_72(Colors::YELLOW);
    // switchStatement_72(Colors::RED);
    // switchStatement_72(Colors::BLUE);
    // leapYears();
    // shortCircuits_73();
    // shortCircuits_73b();
    // IntegerLogicConditions_74();
    // TernaryOperations_76();
    // IfConstexp_76();
    // IfWithInitializer_77();
    // SwitchInitializer_77(Colors::RED);
    // VariableScopeRevisited_79();
    // SwitchScope_80();
    // Assignment_4();
    // Assignment_5();
    // Assignment_6();
    // Assignment_7();
    Assignment_8();
}