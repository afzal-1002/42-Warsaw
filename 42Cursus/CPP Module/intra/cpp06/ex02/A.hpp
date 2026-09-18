#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

// A is an empty class: it adds no data and no behaviour of its own,
// it exists only so we have something concrete to identify at runtime.
class A : public Base
{
    public:
        A();
        ~A();
};

#endif
