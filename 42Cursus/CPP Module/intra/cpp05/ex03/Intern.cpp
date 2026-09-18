#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called"  << std::endl;
}

AForm *Intern::createShrubbery( const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy( const std::string &target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardon( const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm( const std::string &formName, const std::string &target) const
{
    const std::string validNames[3] = { "shrubbery creation", "robotomy request", "presidential pardon"};
    FormCreator creators[3] = { &Intern::createShrubbery,  &Intern::createRobotomy, &Intern::createPresidentialPardon };

    for (int i = 0; i < 3; i++)
    {
        if (formName == validNames[i])
        {
            AForm *form = creators[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cerr << "Intern cannot create \"" << formName << "\" because this form does not exist" << std::endl;
    return 0;
}