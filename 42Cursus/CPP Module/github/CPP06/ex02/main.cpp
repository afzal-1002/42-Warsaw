#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

/*
** generate():
**   Randomly creates an A, a B or a C, and hands it back as a Base*.
**   The caller only ever sees "a Base*" -- at compile time there is no
**   way to know whether the real object behind it is an A, a B or a C.
**   That's the whole point of this exercise: identify() has to figure
**   it out at RUNTIME, using dynamic_cast.
**
**   std::rand() % 3 gives 0, 1 or 2, so +1 shifts it to 1, 2 or 3.
*/
Base* generate(void)
{
    int randomValue = (std::rand() % 3) + 1;

    switch (randomValue)
    {
        case 1:
            std::cout << "-> A Object generate()" << std::endl;
            return new A();
        case 2:
            std::cout << "->   B Object generate()" << std::endl;
            return new B();
        default: // randomValue == 3
            std::cout << "-> C Object generate()" << std::endl;
            return new C();
    }
}

/*
** identify(Base*): Pointer version
*/
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
         std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

/*
** identify(Base&):
**   dynamic_cast on a REFERENCE cannot return "nothing" -- a reference
**   must always refer to a real object -- so when the cast is
**   impossible it THROWS a std::bad_cast exception instead. That's why
**   each attempt below is wrapped in its own try/catch: if no exception
**   is thrown, the cast worked, so we print the type and return right
**   away.
*/
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference version -> A" << std::endl;
        return;
    }
    catch (const std::bad_cast&)
    {
        std::cout << "Not A" << std::endl;
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Reference version -> B" << std::endl;
        return;
    }
    catch (const std::bad_cast&)
    {
        std::cout << "Not B" << std::endl;
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Reference version -> C" << std::endl;
        return;
    }
    catch (const std::bad_cast&)
    {
        std::cout << "Not C" << std::endl;
    }

    std::cout << "Unknown type" << std::endl;
}

int main()
{
    // Seed random generator once
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::cout << "Generating random object..." << std::endl;
    Base* obj = generate();

    std::cout << std::endl << "Identifying by pointer:" << std::endl;
    identify(obj);

    std::cout << std::endl << "Identifying by reference:" << std::endl;
    identify(*obj);

    std::cout << std::endl << "Deleting object..." << std::endl;
    delete obj;

    return 0;
}
