#ifndef  AForm_HPP
# define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _sign_grade;
		const int _exe_grade;
	
	public:

		AForm();
		AForm(const std::string name, int sign_grade, int exe_grade);
		AForm &operator=(const AForm &src);
		AForm(AForm const &src);
		virtual ~AForm();

		void beSigned(Bureaucrat &src);
		virtual void	execute(Bureaucrat  const & executor)const = 0;
		
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
		class FormNotSignedException : public std::exception{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &o, const AForm& AForm);

#endif