#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

class Intern {
  private:
  public:
    Intern();
    Intern(const Intern &src);
    ~Intern();
    Intern &operator=(const Intern &rhs);

    AForm *makeForm(const std::string &formName, const std::string &formTarget);

    AForm *pardonForm(const std::string &target);
    AForm *robotomyForm(const std::string &target);
    AForm *shrubberyForm(const std::string &target);
};

#endif /* INTERN_HPP */
