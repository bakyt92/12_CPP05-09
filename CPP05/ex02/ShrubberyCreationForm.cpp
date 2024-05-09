/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 18:15:31 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/09 19:14:35 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137),
    _target("unnamed")
{
    std::cout << "ShrubberyCreationForm constructor is called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("ShrubberyCreationForm", 145, 137),
    _target(target)
{
    std::cout << "ShrubberyCreationForm constructor with target is called." << std::endl;
}

ShrubberyCreationForm(const ShrubberyCreationForm &src) 
    : AForm(src), _target(src._target)
{
    *this = src; 
}
   
ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
        {
            AForm::operator=(rhs);
            this->_target = rhs._target;
        }
    return (*this);
}

std::string ShrubberyCreationForm::getTarget()
{
    return this->_target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
    std::cout << "ShrubberyCreationForm destructor is called." << std::endl;
}

