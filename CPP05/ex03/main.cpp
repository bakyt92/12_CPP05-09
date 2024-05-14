/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:49 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/14 20:01:40 by ufitzhug         ###   ########.fr       */
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
	AForm* rrf;
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
}Why don't some Atom commands work?
This is because VS Code has not implemented those features. Head on over to this GitHub issue and let the VS Code team know what you'd like to see.

Additionally, you can install an extension for many of these features:

FontSize Shortcuts
change case
transpose
How do I contribute a keyboard shortcut?
We may have missed a keyboard shortcut. If we did please help us out! It is very easy to make a PR.

