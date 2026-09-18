#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), grade_sign(100), grade_exec(100)
{
    std::cout << " From Default constructor called" << std::endl;
}

Form::Form(const std::string& name, const int gradeToSign, const int gradeToExecute) : name(name), grade_sign(gradeToSign), grade_exec(gradeToExecute)
{
    this->isSigned = false;
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    
    std::cout << "Form argument constructor called. " << std::endl;
}

Form::Form(const Form& copy) : name(copy.name), grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
    *this = copy;
     std::cout << "Form argument constructor called. " << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
    if(this != &rhs)
    {
        this->isSigned = rhs.isSigned;
    }
    std::cout << "Form assigned to " << name << " is created" << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Form " << name << " is destroyed" << std::endl;
}

const std::string Form::getName() const
{
    return name;
}

int Form::getSignGrade() const
{
    return grade_sign;
}

int Form::getExecuteGrade() const
{
    return grade_exec;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Exception: Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Exception: Grade is too low");
}

const char *Form::AlreadySignedException::what() const throw()
{
    return ("Exception: Form is already signed");
}

// bureaucrat wants to sign a form
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if(isSigned)
        throw Form::AlreadySignedException();
    if(bureaucrat.getGrade() > grade_sign)
        throw Form::GradeTooLowException();
    isSigned = true;
}
std::ostream& operator<<(std::ostream& obj, const Form& form)
{
    obj << form.getName() << ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade()
        << ", signed: " << (form.getIsSigned() ? "yes" : "no") << std::endl;
    return obj;
}