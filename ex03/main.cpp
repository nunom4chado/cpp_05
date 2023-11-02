#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"
#include <iostream>

int main() {

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            Bureaucrat bur("John", 2);
            rrf->signForm(bur);
            bur.executeForm(*rrf);
            delete rrf;
        }
    }

    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;

    /* ------------------------------------ */

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("pardon request", "Bender");
        if (rrf) {
            Bureaucrat bur("John", 2);
            rrf->signForm(bur);
            bur.executeForm(*rrf);
            delete rrf;
        }
    }

    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;

    /* ------------------------------------ */

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
        if (rrf) {
            Bureaucrat bur("John", 2);
            rrf->signForm(bur);
            bur.executeForm(*rrf);
            delete rrf;
        }
    }

    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;

    /* ------------------------------------ */

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("another request", "Bender");
        if (rrf) {
            Bureaucrat bur("John", 2);
            rrf->signForm(bur);
            bur.executeForm(*rrf);
            delete rrf;
        }
    }

    return 0;
}