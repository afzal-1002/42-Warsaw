#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename Func>
void iter(T *array, std::size_t length, Func func)
{
    for (std::size_t i = 0; i < length; i++)
        func(array[i]);
}

template <typename T>
void printElement(T const &value)
{
    std::cout << value << " ";
}

template <typename T>
void increment(T &value)
{
    ++value;
}

#endif
