#include "Form.hpp"
#include "colors.hpp"

Form::Form() : _gradeToSign(1), _gradeToExec(1) {
    throw Form::GradeTooLowException();
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &src)
    : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign),
      _gradeToExec(src._gradeToExec) {}

Form::~Form() {}

Form &Form::operator=(const Form &rhs) {
    if (this != &rhs)
        this->_signed = rhs._signed;

    return *this;
}

/* --------------------------------- Getters -------------------------------- */
std::string Form::getName() const { return this->_name; }
bool Form::getSigned() const { return this->_signed; }
int Form::getGradeToSign() const { return this->_gradeToSign; }
int Form::getGradeToExec() const { return this->_gradeToExec; }

/* --------------------------------- Others --------------------------------- */
void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

void Form::signForm(const Bureaucrat &bureaucrat) {
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

/* ------------------------------- Exceptions
 * ------------------------------- */
const char *Form::GradeTooHighException::what() const throw() {
    return ("grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("grade too low");
}

std::ostream &operator<<(std::ostream &o, Form const &obj) {
    o << "Form " << obj.getName() << ", signed: " << obj.getSigned()
      << ", grade to sign: " << obj.getGradeToSign()
      << ", grade to execute: " << obj.getGradeToExec() << std::endl;

    return o;
}