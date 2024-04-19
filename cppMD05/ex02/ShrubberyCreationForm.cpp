#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): _tar("not specified"), AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "ShrubberyCreationForm Constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): _tar(target), AForm("ShrubberyCreationForm", 145, 137)
{
	std::cout << "ShrubberyCreationForm Constructed and targeting " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{
    operator=(src);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this == &src)
        return *this;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructed with the target " << this->getTarget() << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return this->_tar;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::fstream file;

	if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (this->getExeGrade() < executor.getGrade())
		throw (AForm::GradeTooLowException());

	file.open(this->getTarget() + "_shrubbery", std::fstream::out | std::fstream::trunc);
	if (!file.good())
		std::cerr << "Failed to open shrubbery target file: " << this->getTarget() << std::endl;
	file <<
	"_-_       \n"
	"    /~~   ~~\    \n"
	" /~~         ~~\ \n"
	"{               }\n"
	" \\  _-     -_ // \n"
	"   ~  \\  //  ~   \n"
	"_- -   | | _- _  \n"
	"  _ -  | |   -_  \n"
	"      // \\      \n"
	"-----------------\n";
	file.close();
}