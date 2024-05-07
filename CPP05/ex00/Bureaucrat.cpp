/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:43 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/07 17:20:25 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) 
{ 
	std::cout << "Bureaucrat constructor is called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	std::cout << "Bureaucrat copy constructor is called." << std::endl;
	*this = src;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != & rhs)
	{
		this->_name = rhs._name;
		
	}
	
	
}

Bureaucrat::~Bureaucrat
{ 
	std::cout << "Bureaucrat destructor is called." << std::endl;
}