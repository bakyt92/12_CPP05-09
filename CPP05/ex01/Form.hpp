/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:14:57 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/08 14:24:59 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#ifndef FORM_HPP
#define FORM_HPP

class Form
{
private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;
    Form();
public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    ~Form();
    Form(const Form &src);
    Form& operator= (const Form &rhs);
    int getGradeToSign();
    int getGradeToExecute();
    std::string getName();
    bool getIsSigned();
    void beSigned(const Bureaucrat &rhs);
    
};

std::ostream& operator<< (std::ostream &os, const Form &src);

#endif