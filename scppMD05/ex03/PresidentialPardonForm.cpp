#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): _tar("not specified"), AForm("PresidentialPardonForm", 25, 5)
{
    std::cout << "PresidentialPardonForm Constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): _tar(target), AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm Constructed and targeting " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
    operator=(src);
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
        return *this;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructed with the target " << this->getTarget() << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->_tar;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (this->getExeGrade() < executor.getGrade())
		throw (AForm::GradeTooLowException());
    std::cout << this->getTarget() << " was pardoned by Zaphod Beeblebrox" << std::endl;
}