#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

// C is an empty class: it adds no data and no behaviour of its own,
// it exists only so we have something concrete to identify at runtime.
class C : public Base
{
    public:
        C();
        ~C();
};

#endif
