#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm {
  private:
    const std::string _target;
    PresidentialPardonForm();

  public:
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &src);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

    virtual void formAction() const;
};

#endif /* PRESIDENTIAL_PARDON_FORM_HPP */