#include <iostream>
#include <string_view>
#include <utility>

struct S
{
    std::string_view get()
    {
        return "Non-const";
    }
    std::string_view get() const
    {
        return "Const";
    }
};

int main()
{
    [[maybe_unused]] auto result = (10 <=> 20) > 0;
    S s;
    const S sc;
    std::cout << const_cast<const S *>(&s)->get() << std::endl;
    std::cout << const_cast<S &>(sc).get() << std::endl;
    std::cout << static_cast<S>(sc).get() << std::endl;
    std::cout << std::as_const(s).get() << std::endl;
}