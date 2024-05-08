/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:53 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/08 13:36:52 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form (std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    std::cout << "Form constructor is called." << std::endl;
    this->_isSigned = 0;
}

Form::Form(const Form &src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Form copy constructor is called." << std::endl;
    *this = src;
}

Form& Form::operator= (const Form &rhs)
{
    if (this != &rhs)
        this->_isSigned = rhs._isSigned;
    return *this;
}


Form::~Form()
{
    std::cout << "Form destructor is called." << std::endl;
}

