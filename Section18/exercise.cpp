#include "exercise.hpp"
#include <iostream>
#include <cstring>

void CalculatorV1(int argc, char *argv[])
{
    auto operand1{1.0};
    auto operand2{1.0};
    auto operation{'-'};
    if (argc == 4)
    {
        operand1 = std::stod(argv[1]);
        operation = *argv[2];
        operand2 = std::stod(argv[3]);
        switch (operation)
        {
        case '+':
            std::cout << operand1 + operand2 << "\n";
            break;
        case '-':
            std::cout << operand1 - operand2 << "\n";
            break;
        case 'x':
            std::cout << operand1 * operand2 << "\n";
            break;
        case '/':
            std::cout << operand1 / operand2 << "\n";
            break;
        }
    }
    else
    {
        std::cout << argc << " is wong number of arguments\n";
        for (int i = 0; i < argc; ++i)
        {
            std::cout << argv[i] << " ";
        }
        std::cout << "\n";
    }
}
void CalculatorV2(int argc, char *argv[])
{
    auto operand1{1.0};
    auto operand2{1.0};
    auto operation{'-'};
    if (argc != 4)
    {
        std::cout << argc << " is wong number of arguments\n";
        for (int i = 0; i < argc; ++i)
        {
            std::cout << argv[i] << " ";
        }
        std::cout << "\n";
        return;
    }
    if (auto op = argv[2]; std::strlen(op) != 1)
    {
        std::cout << "Oh no..\n";
        return;
    }
    operand1 = std::stod(argv[1]);
    operand2 = std::stod(argv[3]);
    operation = *argv[2];
    switch (operation)
    {
    case '+':
        std::cout << operand1 + operand2 << "\n";
        break;
    case '-':
        std::cout << operand1 - operand2 << "\n";
        break;
    case 'x':
        std::cout << operand1 * operand2 << "\n";
        break;
    case '/':
        std::cout << operand1 / operand2 << "\n";
        break;
    }
}