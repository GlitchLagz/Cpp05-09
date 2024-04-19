#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include "AForm.hpp"
# include <random>

class	AForm;
class	Bureaucrat;

class RobotomyRequestForm: public AForm
{
	private:
		const std::string _tar;
		RobotomyRequestForm();
	
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm();

		std::string getTarget() const;

		void execute(Bureaucrat const &executor)const;
};

//std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *src);

#endif