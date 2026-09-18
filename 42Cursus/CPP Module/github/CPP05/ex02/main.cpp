#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>


// ShrubberyCreationForm:
// sign required: 145
// execute required: 137
// a bureaucrat with grade 145 can sign
// a bureaucrat with grade 137 can execute
// a bureaucrat with grade 146 or 138 cannot


// Helper to print a section title before each scenario.
static void printSeparator(const std::string &title)
{
    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << title << std::endl;
    std::cout << "========================================" << std::endl;
}

// Test 1: a bureaucrat can sign and execute a form when they meet the grade requirements.
static void testShrubbery()
{
    printSeparator("TEST 1: SHRUBBERY CREATION");

    Bureaucrat gardener("Gardener", 130);
    ShrubberyCreationForm form("home");

    std::cout << gardener << std::endl;
    std::cout << form << std::endl;

    gardener.signForm(form);
    gardener.executeForm(form);
}

// Test 2: executing an unsigned form should fail, even for a very high-ranking bureaucrat.
static void testUnsignedForm()
{
    printSeparator("TEST 2: EXECUTE UNSIGNED FORM");

    Bureaucrat boss("Boss", 1);
    PresidentialPardonForm form("Arthur Dent");

    boss.executeForm(form);
}

// Test 3: a bureaucrat without the required grade cannot sign a form.
static void testCannotSign()
{
    printSeparator("TEST 3: BUREAUCRAT CANNOT SIGN");

    Bureaucrat worker("Worker", 100);
    RobotomyRequestForm form("Bender");

    worker.signForm(form);
}

// // Test 4: the bureaucrat can sign, but still cannot execute because the execution grade is too high.
// static void testCanSignButCannotExecute()
// {
//     printSeparator("TEST 4: CAN SIGN BUT CANNOT EXECUTE");

//     Bureaucrat officer("Officer", 70);
//     RobotomyRequestForm form("Bender");

//     officer.signForm(form);
//     officer.executeForm(form);
// }

// // Test 5: robotomy execution is allowed after signing and relies on randomness.
// static void testRobotomy()
// {
//     printSeparator("TEST 5: ROBOTOMY");

//     Bureaucrat scientist("Scientist", 40);
//     RobotomyRequestForm form("Bender");

//     scientist.signForm(form);

//     for (int i = 0; i < 10; i++)
//         scientist.executeForm(form);
// }

// // Test 6: presidential pardon is a high-level form that succeeds for the president.
// static void testPresidentialPardon()
// {
//     printSeparator("TEST 6: PRESIDENTIAL PARDON");

//     Bureaucrat president("President", 1);
//     PresidentialPardonForm form("Arthur Dent");

//     president.signForm(form);
//     president.executeForm(form);
// }

// Test 7: exact threshold grade should be accepted for signing and execution.
static void testExactGradeBoundary()
{
    printSeparator("TEST 7: EXACT GRADE BOUNDARY");

    Bureaucrat signer("Signer", 145);
    Bureaucrat executor("Executor", 137);
    ShrubberyCreationForm form("garden");

    signer.signForm(form);
    executor.executeForm(form);
}

// Test 8: one grade below the threshold is still invalid.
static void testGradeBelowBoundary()
{
    printSeparator("TEST 8: INSUFFICIENT BY ONE GRADE");

    Bureaucrat signer("Signer", 146);
    Bureaucrat executor("Executor", 138);
    ShrubberyCreationForm form("office");

    signer.signForm(form);
    executor.executeForm(form);
}

// Test 9: the same code works through polymorphism with different concrete form types.
static void testPolymorphism()
{
    printSeparator("TEST 9: POLYMORPHISM");

    Bureaucrat boss("Boss", 1);

    ShrubberyCreationForm shrubbery("campus");
    RobotomyRequestForm robotomy("Marvin");
    PresidentialPardonForm pardon("Ford Prefect");

    AForm *forms[3];

    forms[0] = &shrubbery;
    forms[1] = &robotomy;
    forms[2] = &pardon;

    for (int i = 0; i < 3; i++)
    {
        boss.signForm(*forms[i]);
        boss.executeForm(*forms[i]);
    }
}

int main()
{
    // Seed randomness for the robotomy test.
    std::srand(std::time(NULL));

    try
    {
        // Run the full validation set for the forms and bureaucrat hierarchy.
        testShrubbery();
        testUnsignedForm();
        testCannotSign();
        // testCanSignButCannotExecute();
        // testRobotomy();
        // testPresidentialPardon();
        testExactGradeBoundary();
        testGradeBelowBoundary();
        testPolymorphism();
    }
    catch (const std::exception &exception)
    {
        std::cerr << "Unexpected exception: " << exception.what() << std::endl;
    }

    return 0;
}