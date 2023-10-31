#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() { throw Bureaucrat::GradeTooLowException(); }

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
    if (this != &rhs)
        this->_grade = rhs._grade;

    return *this;
}

/* --------------------------------- Getters -------------------------------- */
std::string Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }

/* --------------------------------- Others --------------------------------- */
void Bureaucrat::increment() {
    if (this->_grade == 1)
        throw Bureaucrat::GradeTooHighException();

    this->_grade--;
}
void Bureaucrat::decrement() {
    if (this->_grade == 150)
        throw Bureaucrat::GradeTooLowException();

    this->_grade++;
}

/* ------------------------------- Exceptions ------------------------------- */
const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("grade too low");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj) {
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade();

    return o;
}