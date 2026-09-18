#include "Array.hpp"

#include <iostream>
#include <string>

int main(void)
{
    Array<int> numbers(3);
    numbers[0] = 5;
    numbers[1] = 10;
    numbers[2] = 15;

    std::cout << "numbers size: " << numbers.size() << std::endl;
    std::cout << "numbers: " << numbers[0] << " " << numbers[1] << " " << numbers[2] << std::endl;

    Array<int> copy(numbers);
    copy[1] = 42;
    std::cout << "copy: " << copy[0] << " " << copy[1] << " " << copy[2] << std::endl;
    std::cout << "original: " << numbers[0] << " " << numbers[1] << " " << numbers[2] << std::endl;

    Array<std::string> words(2);
    words[0] = "hello";
    words[1] = "world";
    std::cout << "words: " << words[0] << " " << words[1] << std::endl;

    try
    {
        numbers[2] = 99;
    }
    catch (std::exception const &e)
    {
        std::cout << "Out-of-range access caught" << std::endl;
    }

	std::cout << "numbers[2]: " << numbers[2] << std::endl;


	try
    {
        numbers[5] = 99;
    }
    catch (std::exception const &e)
    {
        std::cout << "Out-of-range access caught" << std::endl;
    }


    return 0;
}
