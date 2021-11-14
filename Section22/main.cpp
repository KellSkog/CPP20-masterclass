#include <iostream>
#include "exercise.hpp"
/**
 * https://en.cppreference.com/w/cpp/language/storage_duration
 *  The static specifier is only allowed in the declarations of objects (except in function parameter lists), 
 * declarations of functions (except at block scope), and declarations of anonymous unions. 
 * When used in a declaration of a class member, it declares a static member. 
 * When used in a declaration of an object, it specifies static storage duration (except if accompanied by thread_local). 
 * When used in a declaration at namespace scope, it specifies internal linkage.
 * 
 * The extern specifier is only allowed in the declarations of variables and functions (except class members or function parameters). 
 * It specifies external linkage, and does not technically affect storage duration, but it cannot be used in a definition of 
 * an automatic storage duration object, so all extern objects have static or thread durations. 
 * In addition, a variable declaration that uses extern and has no initializer is not a definition.
 * 
 *  Duration and Linkage
 */

// [[maybe_unused]] extern int ExtGlobalVisApplicationLifetime = 0; // extern is implicit! but implies initialized elewhere!
[[maybe_unused]] int ExtGlobalVisApplicationLifetime = 0;         //External linkage, visible every where, lives until program ends
[[maybe_unused]] static int StaticFileVisApplicationLifetime = 0; // Internal linkage, only visible within TU, lives until program ends

void StaticVariables_221()
{
    [[maybe_unused]] extern int ExtGlobalApplicationLifetimeRef; // Storage not defined here!
    [[maybe_unused]] static int Ztatic = 0;                      // No linkage - Only visible within its scope, lives until program ends
    [[maybe_unused]] auto automatic{0};                          // No linkage - Only visible within its scope, Automatic duration, destroyed at scope end
}

int a() // yet another function with name `a`
{
    ++counter;
    return sum(3, 4);
}
int b()
{
    ++counter;
    return sum(5, 6);
}
void InlineFunctions_222()
{
    // "Inline is just a sugestion to the compiler"
    std::cout << counter << "\n";
    a();
    b();
    std::cout << counter << "\n";
    exercise::a();
    std::cout << counter << "\n"; //If counter is inline, shouldn't counter be 2 here????
}
int sum(int x)
{
    if (x == 0)
        return 0;
    return x + sum(x - 1);
}
void RecursiveFunctions_223()
{
    std::cout << sum(5) << "\n";
}
int main()
{
    std::cout << "Section 22: Functions : The misfits\n";
    // StaticVariables_221();
    // InlineFunctions_222();
    RecursiveFunctions_223();
}