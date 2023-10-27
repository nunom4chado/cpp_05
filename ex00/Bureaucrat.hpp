#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
  private:
    const std::string _name;
    int _grade;

  public:
    Bureaucrat();
    ~Bureaucrat();
};

#endif /* BUREAUCRAT_HPP */
