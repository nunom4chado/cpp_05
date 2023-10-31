#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> // std::ofstream
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {
  private:
    const std::string _target;
    ShrubberyCreationForm();

  public:
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &src);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

    virtual void formAction() const;
};

#endif /* SHRUBBERY_CREATION_FORM_HPP */