#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm {
  private:
    const std::string _target;
    RobotomyRequestForm();

  public:
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &src);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

    virtual void formAction() const;
};

#endif /* ROBOTOMY_REQUEST_FORM_HPP */