#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
  private:
    const std::string _name;
    int _grade;

  public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &rhs);

    // Getters
    std::string getName() const;
    int getGrade() const;

    void increment();
    void decrement();

    // Exceptions
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &obj);

#endif /* BUREAUCRAT_HPP */
