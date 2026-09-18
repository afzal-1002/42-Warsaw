#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &target): AForm("Robotomy Request Form", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;

    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }

    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* BZZZZZZZZ. DRRRRRRRRR. * "  << std::endl;
    std::cout << "* Loud drilling noises * "  << std::endl;

    if (std::rand() % 2 == 0)
    {
        std::cout << target << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << "Robotomy of " << target << " failed" << std::endl;
    }
}