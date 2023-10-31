#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Form {
  private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExec;

  public:
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExec);
    Form(const Form &src);
    ~Form();
    Form &operator=(const Form &rhs);

    // Getters
    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    void beSigned(const Bureaucrat &bureaucrat);
    void signForm(const Bureaucrat &bureaucrat);

    // Exceptions
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Form const &obj);

#endif /* FORM_HPP */
