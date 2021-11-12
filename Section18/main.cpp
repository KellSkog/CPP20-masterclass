#include <iostream>
#include "exercise.hpp"

void GrabAndUseTheArguments_188(int argc, char *argv[])
{
    std::cout << "Section 18: Arguments to main\n";
    for (int i = 0; i < argc; ++i)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << "\n";
}

void CalculatorV1_189(int argc, char *argv[])
{
    CalculatorV2(argc, argv);
}

int main(int argc, char **argv)
{
    // GrabAndUseTheArguments_188(argc, argv);
    CalculatorV1_189(argc, argv);
}