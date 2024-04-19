#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): _tar("not specified"), AForm("RobotomyRequestFormForm", 72, 45)
{
    std::cout << "RobotomyRequestForm Constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): _tar(target), AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm Constructed and targeting " << this->getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{
    operator=(src);
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
        return *this;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructed with the target " << this->getTarget() << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_tar;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (this->getExeGrade() < executor.getGrade())
		throw (AForm::GradeTooLowException());
    std::cout << this->getTarget() << ": *DRILLING NOISES*" << std::endl;
	srand(time(nullptr));
	if (rand() % 2)
		std::cout << this->getTarget() << " HAS BEEN ROBOTOMIZED" << std::endl;
	else
		std::cout << this->getTarget() << " STB'D and failed robotomy" << std::endl;
}