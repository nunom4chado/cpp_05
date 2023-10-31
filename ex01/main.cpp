#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colors.hpp"
#include <iostream>

int main() {

    std::cout << "Tests with (*) at the begining should print an exception"
              << std::endl
              << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 1) Valid Form and signable" << std::endl;
    try {
        Bureaucrat bur("John", 10);
        Form form("TC39", 10, 10);
        form.signForm(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "TEST 2) Valid Form and signable but not executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 10);
        Form form("TC39", 50, 5);
        form.signForm(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 3) Valid Form bureaucrat grade to low to sign"
              << std::endl;
    try {
        Bureaucrat bur("John", 70);
        Form form("TC39", 50, 5);
        form.signForm(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 4) invalid form, gradeToSign too low" << std::endl;
    try {
        Bureaucrat bur("John", 70);
        Form form("TC39", 200, 5);
        form.signForm(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 5) invalid form, gradeToSign too high" << std::endl;
    try {
        Bureaucrat bur("John", 70);
        Form form("TC39", 0, 5);
        form.signForm(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 6) invalid form, gradeToExec too low" << std::endl;
    try {
        Bureaucrat bur("John", 70);
        Form form("TC39", 10, 200);
        form.signForm(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    /* ------------------------------------ */

    std::cout << "* TEST 7) invalid form, gradeToExec too high" << std::endl;
    try {
        Bureaucrat bur("John", 70);
        Form form("TC39", 10, -2);
        form.signForm(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    return 0;
}