/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:47 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/07 19:01:03 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat
{
private:
	Bureaucrat();
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
	~Bureaucrat();

	class GradeTooHighException {
		public:
			virtual const char * what() const throw();
	};
	class GradeTooLowException {
		public:
			virtual const char * what() const throw();
	};

};

#endif