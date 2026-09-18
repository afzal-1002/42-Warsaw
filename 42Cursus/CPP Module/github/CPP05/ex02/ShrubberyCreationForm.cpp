#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), target(other.target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;

    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }

    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::executeAction() const
{
    std::string filename = target + "_shrubbery";
    std::ofstream outputFile(filename.c_str());

    if (!outputFile.is_open())
        throw FileCreationException();

    outputFile << "        *" << std::endl;
    outputFile << "       ***" << std::endl;
    outputFile << "      *****" << std::endl;
    outputFile << "     *******" << std::endl;
    outputFile << "    *********" << std::endl;
    outputFile << "   ***********" << std::endl;
    outputFile << "  *************" << std::endl;
    outputFile << "        |||" << std::endl;
    outputFile << "        |||" << std::endl;

    outputFile.close();

    if (outputFile.fail())
        throw FileCreationException();
}

const char *ShrubberyCreationForm::FileCreationException::what() const throw()
{
    return "could not create or write the shrubbery file";
}