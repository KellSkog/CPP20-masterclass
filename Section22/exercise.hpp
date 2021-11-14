#ifndef SECTION22_EXERCISE
#define SECTION22_EXERCISE
#include <atomic>
// function included in multiple source files must be inline
inline int sum(int a, int b)
{
    return a + b;
}
// variable with external linkage included in multiple source files must be inline
inline std::atomic<int> counter(0);

namespace exercise
{
    int a();
}
#endif // Include guard