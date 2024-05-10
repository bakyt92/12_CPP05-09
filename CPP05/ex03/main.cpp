/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:49 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/10 20:57:54 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat Premiere("First_b", 5);

	Intern RndIntern;
	AForm* rrf = NULL;
	rrf = &RndIntern.makeForm("Robotomy request", "Bender");
	if (rrf != NULL)
	{
		std::cout << "Intern created a form" << std::endl;
	}
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
		Premiere.signForm(*rrf);
		rrf->execute(Premiere);
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete rrf;
	return 0;
}