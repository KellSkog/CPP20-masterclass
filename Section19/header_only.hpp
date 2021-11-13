#ifndef SECTION19_HEADERONLY
#define SECTION19_HEADERONLY
#include <optional>
#include <string>
auto q()
{
    return 42;
}

std::optional<int> FindCharacterV2(std::string str, char c)
{
    auto pos{str.find(c)};
    if (pos != std::string::npos)
        return pos;
    else
        return std::nullopt;
}

#endif