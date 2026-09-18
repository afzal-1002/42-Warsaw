#include "iter.hpp"

#include <string>

int main(void)
{
    int numbers[5] = {1, 2, 3, 4, 5};

    std::cout << "Before increment: ";
    ::iter(numbers, 5, printElement<int>);
    std::cout << std::endl;

    ::iter(numbers, 5, increment<int>);

    std::cout << "After increment: ";
    ::iter(numbers, 5, printElement<int>);
    std::cout << std::endl;

    std::string words[3] = {"one", "two", "three"};
    std::cout << "Strings: ";
    ::iter(words, 3, printElement<std::string>);
    std::cout << std::endl;
	

    return 0;
}
