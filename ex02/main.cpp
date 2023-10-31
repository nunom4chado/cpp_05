#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
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
        ShrubberyCreationForm form("Home");
        form.signForm(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    return 0;
}