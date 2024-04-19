#ifndef  FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exe_grade;
	
	public:

		Form();
		Form(const std::string name, int sign_grade, int exe_grade);
		Form &operator=(const Form &src);
		Form(Form const &src);
		~Form();

		void beSigned(Bureaucrat &src);

		const std::string getName() const;
		//void	getSignedPrint() const;
		bool	getSigned() const;
		int		getSignGrade() const;
		int		getExeGrade() const;

		class GradeTooLowException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &o, const Form& form);

#endif