#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

/*
** Data is the structure we serialize / deserialize in this exercise.
*/
struct Data
{
    int         id;
    std::string name;

    // Called when a Data is created with no arguments, e.g. "Data d;"
    Data() : id(0), name("unknown")
    {
        std::cout << "Data: Default constructor called" << std::endl;
    }

    // Called when we build a Data directly from an id and a name,
    Data(int id, const std::string& name) : id(id), name(name)
    {
        std::cout << "Data: Parameterized constructor called" << std::endl;
    }

    // Called when a NEW Data is built FROM an existing one,
    // e.g. "Data copy(original);"
    Data(const Data& copy) : id(copy.id), name(copy.name)
    {
        std::cout << "Data: Copy constructor called" << std::endl;
    }

    // Called when an ALREADY EXISTING Data receives the contents of
    // another Data, e.g. "a = b;"
    Data& operator=(const Data &obj)
    {
        std::cout << "Data: Copy assignment operator called" << std::endl;
        if (this != &obj)
        {
            id = obj.id;
            name = obj.name;
        }
        return *this;
    }

    // Called automatically when a Data goes out of scope or is deleted.
    ~Data()
    {
        std::cout << "Data: Destructor called (id=" << id << ", name=" << name << ")" << std::endl;
    }
};

#endif
