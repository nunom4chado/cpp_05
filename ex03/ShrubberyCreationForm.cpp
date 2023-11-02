#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
    : AForm(src) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    if (this != &rhs)
        AForm::operator=(rhs);

    return *this;
}

void ShrubberyCreationForm::formAction() const {
    std::cout << "shrubbery form action" << std::endl;

    std::ofstream ofs;
    ofs.open((this->_target + "_shrubbery").c_str());
    if (ofs.fail()) {
        std::cout << "Failed to open file" << std::endl;
        return;
    }

    ofs << "               ,@@@@@@@," << std::endl;
    ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    ofs << "    ,&%%&%&&%,@@numartin@@@@@@,8888\\88/8o" << std::endl;
    ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    ofs << "       |o|        | |         | |" << std::endl;
    ofs << "       |.|        | |         | |" << std::endl;
    ofs << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

    ofs.close();
}