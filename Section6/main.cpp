#include <iostream>
#include <type_traits>

template <typename T>
void dump([[maybe_unused]] T t)
{
}
void literals_48()
{
    // unsigned char ucar{-1};
    unsigned char uchar{1u};
    dump(uchar);
    long longing{1L};
    dump(longing);
    unsigned long long ulla{1'5'0'0'00'0ull};
    std::cout << std::hex << "Ulla: " << ulla << std::dec << "\n";
}
void constants_49()
{
    const int fortyfive{45};
    int *bother = const_cast<int *>(&fortyfive);
    *bother = 0; // Undefined behavior
    std::cout << "Oh bother: " << fortyfive << "\n";
}
void constExpressions_50(bool posibly)
{
    constexpr int HARDCODEDVALUE = 45;
    if constexpr (HARDCODEDVALUE == 10)
    {
        std::cout << 10 << "\n";
    }
    else
    {
        std::cout << "45\n";
    }
    if (posibly)
    {
        constexpr int zzz = 43;
        dump(zzz);
    }
    constexpr bool what = true;
    static_assert(what);
    // static_assert(HARDCODEDVALUE == 10);
}
constinit int initialized = 0;                         // Not const
[[maybe_unused]] constinit const int initialized2 = 0; // Const
// only one of 'constexpr', 'consteval', and 'constinit' can appear on a declaration
// constexpr constinit int bad = 0;
int main()
{
    // constinit int initialized = 0; // 'constinit' is only valid for declarations of variables with static or thread storage duration
    initialized = 3;
    // initialized2 = 3; // error: assignment of read-only variable ‘initialized2’
    std::cout << "Section 6\n";
    // literals_48();
    // constants_49();
    constExpressions_50(false);
}