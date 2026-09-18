#include "Intern.hpp"
#include "AForm.hpp"

#include <iostream>

int main()
{
    // Create an Intern that will decide which concrete form to instantiate.
    Intern someRandomIntern;
    AForm *rrf;

    // Ask the Intern to create a robotomy request form for the target "Bender".
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");

    // If a form was successfully created, print it and free the allocated memory.
    if (rrf != 0)
    {
        std::cout << *rrf << std::endl;
        delete rrf;
    }

    return 0;
}