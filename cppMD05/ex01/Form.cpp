#include "Form.hpp"

Form::Form(): _name("unnamed"), _sign_grade(150), _exe_grade(150), _signed(false)
{
	std::cout << "Form " << this->getName() << " Constructed" << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exe_grade): _name(name), 
_sign_grade(sign_grade), _exe_grade(exe_grade), _signed(false)
{
	if (sign_grade > 150 || exe_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 1 || exe_grade < 1)
		throw GradeTooHighException();
	else
		std::cout << "Form " << this->getName() << " Constructed" << std::endl;
}

Form& Form::operator=(const Form &src)
{
	//cant copy cause everythings const and not initalised
	return *this;
}

Form::Form(const Form &src): _name(src.getName()), _signed(false), 
_sign_grade(src.getSignGrade()), _exe_grade(src.getExeGrade())
{
	*this = src;
}

Form::~Form()
{
	std::cout << "Form " << this->getName() << " Destructed" << std::endl;
}

void Form::beSigned(Bureaucrat &src)
{
	try{
		if (src.getGrade() <= this->getSignGrade())
		{
			this->_signed = true;
			std::cout << src.getName() << " signed form: " << this->getName() << std::endl;
		}
		else
			throw(Bureaucrat::GradeTooLowException());
	}
	catch (std::exception &e){
				std::cout << src.getName() << " couldn't sign " << this->getName() 
		<< " because :" << e.what() << std::endl;
	}

}

std::string const Form::getName() const
{
	return this->_name;
}

// void Form::getSignedPrint() const
// {
// 	if (this->_signed == true)
// 		std::cout << this.getName() << " is signed" << std::endl;
// 	else if (this->_signed == false)
// 		std::cout << this.getName() << " is not currently signed" std::endl;
// }

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getSignGrade() const
{
	return this->_sign_grade;
}

int Form::getExeGrade() const
{
	return this->_exe_grade;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream &o, const Form& Form)
{
	o << "\033[1;32m" << Form.getName() << "\033[0m\nSign_grade: " << Form.getSignGrade() << "\nExe_grade: " 
	<< Form.getExeGrade() << "\nIs signed: " << Form.getSigned() << std::endl;
	return o;
}