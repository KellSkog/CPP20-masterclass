#include <iostream>

int main() {
    auto result = (10 <=> 20) > 0;
    std::cout << "Windows opened!" << result << std::endl;
}