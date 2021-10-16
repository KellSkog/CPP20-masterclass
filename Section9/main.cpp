#include <iostream>
/**
 * Variable storage 
 * duration, scope and linkage
 */

[[maybe_unused]] static int staticDurationVariable; // Static duration exists until program exits, 0 initialized
[[maybe_unused]] extern int staticDurationVariable; // Static duration exists until program exits, 0 initialized

int *variableLifetime_67()
{
    {
        [[maybe_unused]] int automaticVar; // Unitialized automatic storage, exists until end of block
    }                                      // automaticVar expires
    int *dynamicStorage = new int;

    return dynamicStorage;
}

int main()
{
    std::cout << "Section 9\n";

    delete variableLifetime_67(); // dynamicStorage is deleted
}