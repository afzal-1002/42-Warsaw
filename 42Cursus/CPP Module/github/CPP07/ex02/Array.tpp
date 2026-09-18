#include <iostream>
# include "Array.hpp"

template <typename T>
Array<T>::Array(void) : array(NULL), len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), len(n)
{
}

template <typename T>
Array<T>::Array(Array const &src) : array(NULL), len(0)
{
    *this = src;
}

template <typename T>
Array<T>::~Array(void)
{
    delete [] array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &obj)
{
    if (this != &obj)
    {
        delete [] array;
        len = obj.len;
        array = new T[len]();
        for (unsigned int i = 0; i < len; ++i)
        {
            array[i] = obj.array[i];
        }
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= len)
    {
        throw SizeExceedException();
    }
    return array[index];
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
    if (index >= len)
    {
        throw SizeExceedException();
    }
    return array[index];
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return len;
}

template <typename T>
const char *Array<T>::SizeExceedException::what() const throw()
{
    return "Index exceeds the size";
}
