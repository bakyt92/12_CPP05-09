/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:15:21 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/10 18:15:57 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 72, 45),
    _target("unnamed")
{
    std::cout << "PresidentialPardonForm constructor is called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) 
    : AForm("PresidentialPardonForm", 72, 45),
    _target(target)
{
    std::cout << "PresidentialPardonForm constructor with target is called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) 
    : AForm(src), _target(src._target)
{
    *this = src; 
}
   
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
        {
            AForm::operator=(rhs);
            this->_target = rhs._target;
        }
    return (*this);
}

std::string PresidentialPardonForm::getTarget()
{
    return this->_target;
}

void PresidentialPardonForm::execute (const Bureaucrat &executor) const
{
    toExecute(executor);
    
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
    std::cout << "PresidentialPardonForm destructor is called." << std::endl;
}

