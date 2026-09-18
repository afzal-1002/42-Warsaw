#include "Serializer.hpp"


Serializer::Serializer()
{
    std::cout << "Serializer: Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& copy)
{
    (void)copy;
    std::cout << "Serializer: Copy constructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    std::cout << "Serializer: Assignment operator called" << std::endl;
    if(this != &rhs)
        (void)rhs;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Serializer: Destructor called" << std::endl;
}

/*
** A pointer is really just an address stored in memory, and uintptr_t
** is an unsigned integer type guaranteed to be big enough to hold that
** same address. reinterpret_cast changes only how the compiler LABELS
** the bits (pointer vs integer) -- it does not touch the bits or the
** memory the pointer refers to. That's why converting Data* -> uintptr_t
** -> Data* and back gives us the exact same address we started with.
**
**   Data*  --serialize()-->  uintptr_t  --deserialize()-->  Data*
*/
uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}