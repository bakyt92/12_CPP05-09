/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:49 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/10 18:52:50 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat Premiere("First_b", 5);
	try {
		// Bureaucrat Deuxieme("Second_b", 0);
	 	// Bureaucrat Troisieme("Third_b", 155);
		Premiere.upGrade();
		Premiere.upGrade();
		Premiere.upGrade();
		ShrubberyCreationForm form1 ("Melanin");
		Premiere.signForm(form1);
		RobotomyRequestForm form2("Robloxxx");
		Premiere.signForm(form2);
		PresidentialPardonForm form3("Atreides");
		Premiere.signForm(form3);
		form1.execute(Premiere);
		form2.execute(Premiere);
		form3.execute(Premiere);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}