#include "exercise.hpp"

#include <iostream>

void show_odds(unsigned long long num)
{
    while (num)
    {
        if (num % 2) // odd
        {
            std::cout << num % 10;
        }
        num /= 10;
    }
}

unsigned digit_sum(unsigned num)
{
    int sum{};
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool is_palindrome(unsigned long long num)
{
    unsigned char numbers[32]{};
    unsigned count{};
    while (num)
    {
        numbers[count++] += num % 10;
        num /= 10;
    }
    bool result{true};
    for (unsigned i = 0; i < count / 2; ++i)
    {
        if (numbers[i] != numbers[count - i - 1])
            result = false;
        break;
    }
    return result;
}

void TakesConst(int &x)
{
    std::cout << ++x << "\n";
}
void TakesConst(const int &x)
{
    std::cout << x << "\n";
}

int contains_character(const char *str, unsigned size, char c)
{
    int result{-1};
    for (unsigned i = 0; i < size; ++i)
    {
        if (str[i] == c)
        {
            result = i;
            break;
        }
    }
    return result;
}

void find_character(const char *str, unsigned int size, char c)
{
    if (int pos = contains_character(str, size, c); pos != -1)
    {
        std::cout << "Found character " << c << " at index " << pos;
    }
    else
    {
        std::cout << "Could not find the character " << c << " in " << str;
    }
}

int compute(int x, int y, int z) // default values only in declaration!
{
    return x + y + z;
}