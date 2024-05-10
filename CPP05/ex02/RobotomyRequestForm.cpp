/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:15:36 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/10 15:14:56 by ufitzhug         ###   ########.fr       */
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
    toExecute(executor);
    
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
    std::cout << "RobotomyRequestForm destructor is called." << std::endl;
}

