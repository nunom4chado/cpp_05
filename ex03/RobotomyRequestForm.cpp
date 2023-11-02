#include "RobotomyRequestForm.hpp"
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}

void RobotomyRequestForm::formAction() const {
    std::cout << "(drilling noises) Bzzzz..." << std::endl;

    /* initialize random seed: */
    srand(time(NULL));

    /* generate number between 0 and 1: */
    int success = rand() % 2;

    if (success) {
        std::cout << this->_target << " has been robotomized" << std::endl;
    } else {
        std::cout << "the robotomy failed" << std::endl;
    }
}