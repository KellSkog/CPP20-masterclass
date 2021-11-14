#include "exercise.hpp"

int ExtGlobalApplicationLifetimeRef = 666; //External linkage, visible every where, lives until program ends

namespace exercise
{
    int a()
    {
        ++counter;
        return sum(1, 2);
    }
}