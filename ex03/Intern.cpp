#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) { *this = src; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs) {
    (void)rhs;
    return *this;
}

/* --------------------------------- Static --------------------------------- */

AForm *Intern::pardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::robotomyForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::shrubberyForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

/* --------------------------------- Others --------------------------------- */

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &formTarget) {

    AForm *(Intern::*memberFuncs[])(const std::string &target) = {
        &Intern::pardonForm, &Intern::robotomyForm, &Intern::shrubberyForm};

    std::string formTypes[] = {"pardon request", "robotomy request",
                               "shrubbery request"};

    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            std::cout << "Intern creates " << formName << " form" << std::endl;
            return ((this->*memberFuncs[i])(formTarget));
        }
    }

    std::cout << "Form not found!" << std::endl;
    return (NULL);
}
