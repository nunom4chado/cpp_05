#include "AForm.hpp"
#include "colors.hpp"

AForm::AForm() : _gradeToSign(1), _gradeToExec(1) {
    throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExec)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src)
    : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign),
      _gradeToExec(src._gradeToExec) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &rhs) {
    if (this != &rhs)
        this->_signed = rhs._signed;

    return *this;
}

/* --------------------------------- Getters -------------------------------- */
std::string AForm::getName() const { return this->_name; }
bool AForm::getSigned() const { return this->_signed; }
int AForm::getGradeToSign() const { return this->_gradeToSign; }
int AForm::getGradeToExec() const { return this->_gradeToExec; }

/* --------------------------------- Others --------------------------------- */
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

void AForm::signForm(const Bureaucrat &bureaucrat) {
    try {
        this->beSigned(bureaucrat);
        std::cout << bureaucrat.getName() << " signed " << this->getName()
                  << std::endl;
    } catch (std::exception &e) {
        std::cout << RED << bureaucrat.getName() << " couldn't sign "
                  << this->getName() << " because " << e.what() << "." << RESET
                  << std::endl;
    }
}

void AForm::execute(Bureaucrat const &executor) const {
    if (!this->_signed)
        throw AForm::UnsignedFormException();

    if (executor.getGrade() > this->_gradeToExec)
        throw AForm::GradeTooLowException();

    this->formAction();
}

/* ------------------------------- Exceptions ------------------------------- */
const char *AForm::GradeTooHighException::what() const throw() {
    return ("grade too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("grade too low");
}

const char *AForm::UnsignedFormException::what() const throw() {
    return ("unsigned form");
}

std::ostream &operator<<(std::ostream &o, AForm const &obj) {
    o << "Form " << obj.getName() << ", signed: " << obj.getSigned()
      << ", grade to sign: " << obj.getGradeToSign()
      << ", grade to execute: " << obj.getGradeToExec() << std::endl;

    return o;
}