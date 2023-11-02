#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {
  private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExec;

  public:
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExec);
    AForm(const AForm &src);
    virtual ~AForm();
    AForm &operator=(const AForm &rhs);

    // Getters
    std::string getName() const;
    bool getSigned() const;
    int getGradeToSign() const;
    int getGradeToExec() const;

    void beSigned(const Bureaucrat &bureaucrat);
    void signForm(const Bureaucrat &bureaucrat);

    void execute(Bureaucrat const &executor) const;
    virtual void formAction() const = 0;

    // Exceptions
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class UnsignedFormException : public std::exception {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, AForm const &obj);

#endif /* AFORM_HPP */
