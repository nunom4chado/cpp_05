#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &src)
    : AForm(src) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}

void PresidentialPardonForm::formAction() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
}