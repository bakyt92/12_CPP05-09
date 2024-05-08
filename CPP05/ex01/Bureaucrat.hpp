/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:47 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/08 17:05:49 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	Bureaucrat();
	Form *src;
	const std::string _name;
	int _grade;
public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat & operator= (const Bureaucrat &rhs);
	const std::string getName() const;
	void setGrade(int g);
	int getGrade() const;
	void upGrade(void);
	void downGrade(void);
	void signForm(Form &src);
	~Bureaucrat();

	class GradeTooHighException : public std::exception {
		public:
			virtual const char * what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char * what() const throw();
	};

};

std::ostream& operator<< (std::ostream &os, const Bureaucrat &src);

#endif