#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

// B is an empty class: it adds no data and no behaviour of its own,
// it exists only so we have something concrete to identify at runtime.
class B : public Base
{
    public:
        B();
        ~B();
};

#endif
