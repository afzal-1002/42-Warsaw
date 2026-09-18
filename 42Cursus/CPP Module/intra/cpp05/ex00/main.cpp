#include "Bureaucrat.hpp"

#include <iostream>


int main(void)
{
	std::cout << "---- Valid construction and output ----" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 42);
		std::cout << alice << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n---- Invalid construction (too high) ----" << std::endl;
	try
	{
		Bureaucrat top("Top", 0);
		std::cout << top << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n---- Invalid construction (too low) ----" << std::endl;
	try
	{
		Bureaucrat low("Low", 151);
		std::cout << low << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n---- Increment and decrement ----" << std::endl;
	try
	{
		Bureaucrat worker("Worker", 2);
		std::cout << worker << std::endl;
		worker.incrementGrade();
		std::cout << "After increment: " << worker << std::endl;
		worker.incrementGrade();
		std::cout << worker << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat trainee("Trainee", 149);
		std::cout << trainee << std::endl;
		trainee.decrementGrade();
		std::cout << "After decrement: " << trainee << std::endl;
		trainee.decrementGrade();
		std::cout << trainee << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n---- Canonical form checks ----" << std::endl;
	try
	{
		Bureaucrat a("A", 10);
		Bureaucrat b(a);
		Bureaucrat c("C", 100);
		c = a;
		std::cout << "A: " << a << std::endl;
		std::cout << "B (copy): " << b << std::endl;
		std::cout << "C (assigned): " << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	return (0);
}