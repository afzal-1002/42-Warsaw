#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main(void)
{
	std::cout << "---- Form: invalid grade (too high) ----" << std::endl;
	try
	{
		Form bad("Bad", 0, 50);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n---- Form: invalid grade (too low) ----" << std::endl;
	try
	{
		Form bad("Bad", 50, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n---- Form: bureaucrat grade too low to sign ----" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 50);
		Form tax("TaxForm", 10, 10);
		std::cout << tax;
		bob.signForm(tax);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n---- Form: successful sign ----" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 5);
		Form tax("TaxForm", 10, 10);
		alice.signForm(tax);
		std::cout << tax;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "\n---- Form: sign already signed form ----" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 5);
		Form tax("TaxForm", 10, 10);
		alice.signForm(tax);
		alice.signForm(tax);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	return (0);
}