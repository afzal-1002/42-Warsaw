#ifndef FORM_HP
#define FORM_HP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
        bool isSigned;
		const int grade_sign; 
        const int grade_exec;
		
	public:
		Form();
		Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();
		
        void beSigned(const Bureaucrat& b);

        const std::string getName() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool getIsSigned() const;

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw();
        };
    
        class AlreadySignedException : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& obj, const Form& form);

#endif