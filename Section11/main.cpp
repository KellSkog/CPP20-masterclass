#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>
#include "array"
#include <assert.h>
// typedef unsigned long size_t;

void for_loop_83()
{
    for (size_t i{}; i < 10; i++)
    {
        i++;
        std::cout << ++i << "\n";
    }
}

void exercise_sum_up_to(unsigned count)
{
    unsigned sum{};
    for (unsigned i = 0; i <= count; i++)
    {
        sum += i;
    }
    std::cout << sum << "\n";
}

void exercise_printUppercase()
{
    for (unsigned char i{}; i < 255; ++i)
    {
        if ((i >= 'A') && i <= 'Z')
        {
            std::cout << i;
            if (i < 'Z')
            {
                std::cout << " ";
            }
            //  No final end of line requested..
            // else
            // {
            //     std::cout << "\n";
            // }
        }
    }
}

void comma_operator_85()
{
    unsigned a{2}, b{3}, c{5};
    auto i = (a++, b++, ++c);
    std::cout << "Last evaluation resulted in: " << i << "\n";
}

void range_based_for_loop_86()
{
    std::array<int, 10> bagOfValues{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto value : bagOfValues)
    {
        std::cout << "Value: " << value << "\n";
    }
    std::cout << "\n";
    for (auto value : std::array<int, 5>{5, 4, 3, 2, 1})
    {
        std::cout << "Eulav: " << value << "\n";
    }
}

void exercise_filter_in_multiple_of_3()
{
    std::vector<int> numbers{1, 2, 31, 4, 5, 7, 3, 9, 3, 5, 17, 15};
    for (auto num : numbers)
    {
        if (num % 3 == 0)
        {
            std::cout << num << " ";
        }
    }
}

void while_loop_87()
{
    constexpr unsigned COUNT{10};
    unsigned i{0};
    while (i++ < COUNT)
    {
    }
    std::cout << "Loop done @: " << i << "\n";
    // i = COUNT + 1
    do
    {
        /* code */
    } while (--i > 0);
    std::cout << "Loop done @: " << i << "\n";
}

void exercise_i_am_stringy()
{
    std::vector<double> unit_prices{10.4, 21.5, 14.0, 15.2, 7.9};
    std::vector<unsigned> number_of_items{60, 20, 10, 30, 20, 50};
    // assert(number_of_items.size() <= unit_prices.size());
    double least_cost{std::numeric_limits<double>::max()};
    unsigned index{0};
    while (index < unit_prices.size())
    {
        auto value = number_of_items[index] * unit_prices[index];
        if (least_cost > value)
        {
            least_cost = value;
        }
        index++;
    }
    std::cout << "Least :" << least_cost << "\n";
}

void do_while_89()
{
    do
    {
        std::cout << "But it's false...\n";
    } while (false);
}

void exercise_multiples_of_19()
{
    constexpr int End{1000};
    int count{100};
    do
    {
        if (count % 19 == 0)
        {
            std::cout << count << " ";
        }
    } while (count++ < End);
}

void infinite_loops_90()
{
    for (int i = 0;; i++)
    {
        std::cout << "I love C++\n";
        if (i > 0)
            break;
    }
    for (int i = 0; true; i++)
    {
        std::cout << "I too love C++\n";
        break;
    }
    while (true)
    {
        std::cout << "I three love C++\n";
        break;
    }
}

void decrementing_loop_92()
{
    // Shoot "-Werror=type-limits"
    for (unsigned char num{0}; /*num >= 0*/; num--)
    {
        if (num > 0)
        {
            std::cout << static_cast<int>(num) << "\n";
            break;
        }
    }
}

void nested_loops_93()
{
    // std::cout << std::setw(4);
    for (auto row{1}; row < 4; row++)
    {
        for (auto col{1}; col < 4; col++)
        {
            std::cout << "(" << std::setw(2) << row << ", " << std::setw(2) << col << ")";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    auto row{1};
    do
    {
        auto col{1};
        do
        {
            std::cout << "(" << std::setw(2) << row << ", " << std::setw(2) << col << ")";
        } while (++col < 4);
        std::cout << "\n";
    } while (++row < 4);
}

void break_and_continue_94()
{
    for (auto i{1}; i < 20; i++)
    {
        if ((i % 3 == 0) && (i % 5 == 0))
            break;
        if ((i % 3 == 0) || (i % 5 == 0))
            continue;
        std::cout << i << ", ";
    }
}

void fix_the_calculator_95()
{
    // 1. Shall print welcome
    // 2. Ask what to do
    // 3. State "Unable to comply" if so -> 2
    // 4. Exit if requested
    // 5. ask for operands
    // 6. Print result -> 2
    std::cout << "Calcium\n";
    bool done{false};
    do // 2.
    {
        char op;
        double op1, op2, result;
        std::cout << "Op:";
        std::cin >> op;
        if (op == '+' || op == '-')
        {
            std::cout << "operands: ";
            std::cin >> op1 >> op2;
            switch (op)
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            }
            std::cout << op1 << op << op2 << "=" << result << "\n";
        }
        else if (op != 'q' && op != 'Q')
        {
            std::cout << "Unable to comply\n";
        }
        else
        {
            std::cout << "G'bye!\n";
            done = true;
        }
    } while (!done);
}

void for_loop_with_init_condition_96()
{
    // Range based for loop with initializer (c++20!)
    for (auto factor{4}; auto item : {1, 2})
    {
        std::cout << factor * item << "\n";
    }
}

constexpr bool is_leap_year(unsigned int year)
{
    if (year % 100 == 0) // A century year e.g. 2000
        return ((year % 400) == 0);
    else
        return ((year % 4) == 0);
}
void assignment_year_calendar()
{
    int year;
    int dayIndex;
    struct Month
    {
        int days;
        const char *name;
    };
    constexpr std::array<const char *, 7> weekDay{"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    std::array<Month, 12> months{31, "Jan", 28, "Feb", 31, "Mar", 30, "April", 31, "May", 30, "June",
                                 31, "July", 31, "August", 30, "September", 31, "October", 30, "November", 31, "December"};
    std::cout << "Year? ";
    std::cin >> year;
    if (is_leap_year(year))
        months[1].days = 29;
    std::cout << "FirstDay (1-7)? ";
    std::cin >> dayIndex;
    --dayIndex; // 0 base
    std::cout << "Calendar for " << year << "\n";
    for (auto month : months)
    {
        std::cout << "--" << month.name << " " << year << " --\n";
        for (int i = 0; i < 7; i++)
        {
            std::cout << std::setw(4) << weekDay[i];
        }
        std::cout << "\n";
        int date = 1;
        // Print first week
        for (int day = 0; day < 7; day++)
        {
            std::cout << std::setw(4);
            if ((day < dayIndex))
                std::cout << " ";
            else
            {
                std::cout << date;
                date++;
            }
        }
        std::cout << "\n";
        do // Print remaining weeks
        {
            for (int day = 0; day < 7; day++)
            {
                std::cout << std::setw(4);
                if (date <= month.days)
                {
                    if (date == month.days)
                    {
                        // Ensure month ending on sunday is followed by week starting on Monday
                        dayIndex = (day == 6) ? 0 : day + 1;
                    }
                    std::cout << date;
                    date++;
                }
            }
            std::cout << "\n"; // End of week
        } while (date <= month.days);
        std::cout << "\n"; // End of Month
    }
}

int main()
{
    std::cout << "Section 11, size_t is " << sizeof(size_t) << " Bytes\n";

    // for_loop_83();
    // exercise_sum_up_to(3);
    // exercise_printUppercase();
    // comma_operator_85();
    // range_based_for_loop_86();
    // exercise_filter_in_multiple_of_3();
    // while_loop_87();
    // exercise_i_am_stringy();
    // i_wont_do_88();
    // do_while_89();
    // exercise_multiples_of_19();
    // infinite_loops_90();
    // decrementing_loop_92();
    // nested_loops_93();
    // break_and_continue_94();
    // fix_the_calculator_95();
    // for_loop_with_init_condition_96();
    assignment_year_calendar();
}