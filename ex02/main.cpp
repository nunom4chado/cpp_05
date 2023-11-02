#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"
#include <iostream>

int main() {

    std::cout << "Tests with (*) at the begining should print an exception"
              << std::endl
              << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 1) Shrubbery Form, signable and executable" << std::endl;
    try {
        Bureaucrat bur("John", 10);
        ShrubberyCreationForm form("Home");
        form.signForm(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 2) Shrubbery Form, signable but not executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 140);
        ShrubberyCreationForm form("Home");
        form.signForm(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 3) Robotomy Form, signable and executable" << std::endl;
    try {
        Bureaucrat bur("John", 40);
        RobotomyRequestForm form("Chicken");
        form.signForm(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 4) Robotomy Form, signable but not executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 50);
        RobotomyRequestForm form("Chicken");
        form.signForm(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 5) Presidential Pardon Form, signable and executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 4);
        PresidentialPardonForm form("Marvin");
        form.signForm(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout
        << "* TEST 6) Presidential Pardon Form, signable but not executable"
        << std::endl;
    try {
        Bureaucrat bur("John", 20);
        PresidentialPardonForm form("Marvin");
        form.signForm(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 7) Shrubbery Form, signable and executable" << std::endl;
    try {
        Bureaucrat bur("John", 10);
        ShrubberyCreationForm form("Home");
        form.signForm(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 8) Shrubbery Form, signable but not executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 140);
        ShrubberyCreationForm form("Home");
        form.signForm(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 9) Robotomy Form, signable and executable" << std::endl;
    try {
        Bureaucrat bur("John", 40);
        RobotomyRequestForm form("Chicken");
        form.signForm(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 10) Robotomy Form, signable but not executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 50);
        RobotomyRequestForm form("Chicken");
        form.signForm(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 11) Presidential Pardon Form, signable and executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 4);
        PresidentialPardonForm form("Marvin");
        form.signForm(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout
        << "* TEST 12) Presidential Pardon Form, signable but not executable"
        << std::endl;
    try {
        Bureaucrat bur("John", 20);
        PresidentialPardonForm form("Marvin");
        form.signForm(bur);
        bur.executeForm(form);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    return 0;
}