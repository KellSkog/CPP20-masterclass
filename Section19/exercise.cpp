#include "exercise.hpp"
#include <iostream>

void is_sum_even(int data[], unsigned int size, bool &result)
{
    int sum{};
    for (unsigned i = 0; i < size; ++i)
    {
        sum += data[i];
    }
    result = (sum % 2) ? false : true;
    return;
}

std::string AddStrings(std::string one, std::string other)
{
    std::string concat{one + other};
    std::cout << "Concat @: " << &concat << "\n";
    return concat;
}

// auto q() // error: ambiguating new declaration of ‘auto q()’
// auto q() -> bool
// {
//     return 42;
// }