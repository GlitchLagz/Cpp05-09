#include "AForm.hpp"

AForm::AForm(): _name("unnamed"), _sign_grade(150), _exe_grade(150), _signed(false)
{
	std::cout << "AForm " << this->getName() << " Constructed" << std::endl;
}

AForm::AForm(const std::string name, int sign_grade, int exe_grade): _name(name), 
_sign_grade(sign_grade), _exe_grade(exe_grade), _signed(false)
{
	if (sign_grade > 150 || exe_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 1 || exe_grade < 1)
		throw GradeTooHighException();
	else
		std::cout << "AForm " << this->getName() << " Constructed" << std::endl;
}

AForm& AForm::operator=(const AForm &src)
{
	//cant copy cause everythings const and not initalised
	return *this;
}

AForm::AForm(const AForm &src): _name(src.getName()), _signed(false), 
_sign_grade(src.getSignGrade()), _exe_grade(src.getExeGrade())
{
	*this = src;
}

AForm::~AForm()
{
	std::cout << "AForm " << this->getName() << " Destructed" << std::endl;
}

void AForm::beSigned(Bureaucrat &src)
{
	try{
		if (src.getGrade() <= this->getSignGrade())
		{
			this->_signed = true;
			std::cout << src.getName() << " signed AForm: " << this->getName() << std::endl;
		}
		else
			throw(Bureaucrat::GradeTooLowException());
	}
	catch (std::exception &e){
				std::cout << src.getName() << " couldn't sign " << this->getName() 
		<< " because :" << e.what() << std::endl;
	}

}

std::string const AForm::getName() const
{
	return this->_name;
}

// void AForm::getSignedPrint() const
// {
// 	if (this->_signed == true)
// 		std::cout << this.getName() << " is signed" << std::endl;
// 	else if (this->_signed == false)
// 		std::cout << this.getName() << " is not currently signed" std::endl;
// }

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getSignGrade() const
{
	return this->_sign_grade;
}

int AForm::getExeGrade() const
{
	return this->_exe_grade;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}
const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form can't be executed without being signed first");
}

std::ostream& operator<<(std::ostream &o, const AForm& AForm)
{
	o << "\033[1;32m" << AForm.getName() << "\033[0m\nSign_grade: " << AForm.getSignGrade() << "\nExe_grade: " 
	<< AForm.getExeGrade() << "\nIs signed: " << AForm.getSigned() << std::endl;
	return o;
}