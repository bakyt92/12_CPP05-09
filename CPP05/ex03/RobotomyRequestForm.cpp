/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:15:36 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/10 18:53:46 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("RobotomyRequestForm", 72, 45),
    _target("unnamed")
{
    std::cout << "RobotomyRequestForm constructor is called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("RobotomyRequestForm", 72, 45),
    _target(target)
{
    std::cout << "RobotomyRequestForm constructor with target is called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) 
    : AForm(src), _target(src._target)
{
    *this = src; 
}
   
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
        {
            AForm::operator=(rhs);
            this->_target = rhs._target;
        }
    return (*this);
}

std::string RobotomyRequestForm::getTarget()
{
    return this->_target;
}

void RobotomyRequestForm::execute (const Bureaucrat &executor) const
{
    std::cout << "1_Execute Robotomy is called" << std::endl;
    toExecute(executor);
    std::cout << "Makes drilling noises ... BZZzzz" << std::endl;
	std::srand(std::time(NULL));
	int random_val = std::rand();
	if (random_val % 2 == 0)
	{
		std::cout << this->_target << "has been robotomized..." << std::endl;
	}
	else
	{
		std::cout << "Robotomy of " << this->_target << " has been failed." << std::endl;
	}
    return ;
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
    std::cout << "RobotomyRequestForm destructor is called." << std::endl;
}

