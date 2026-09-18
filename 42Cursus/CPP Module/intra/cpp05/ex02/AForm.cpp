#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(): name("Default Form"), isSigned(false),
      gradeToSign(150), gradeToExecute(150)
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();

    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();

    std::cout << "AForm parameterized constructor called"
              << std::endl;
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "AForm assignment operator called" << std::endl;

    if (this != &other)
        isSigned = other.isSigned;

    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}


const std::string &AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();

    isSigned = true;
}
void AForm::execute(const Bureaucrat &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();

    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();

    executeAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "form grade is too high";
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return "form grade is too low";
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return "form is not signed";
}
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form name: " << form.getName() << std::endl;
    out << "Signed: "
        << (form.getIsSigned() ? "yes" : "no")
        << std::endl;
    out << "Grade required to sign: "
        << form.getGradeToSign()
        << std::endl;
    out << "Grade required to execute: "
        << form.getGradeToExecute();

    return out;
}
