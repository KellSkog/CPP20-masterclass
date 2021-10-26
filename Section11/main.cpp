#include <iostream>

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
}

int main()
{
    std::cout << "Section 11, size_t is " << sizeof(size_t) << " Bytes\n";

    // for_loop_83();
    // exercise_sum_up_to(3);
    // exercise_printUppercase();
    comma_operator_85();
}