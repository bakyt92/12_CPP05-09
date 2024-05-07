/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:43:49 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/07 18:33:49 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat Premiere("First_b", 20);
		Bureaucrat Deuxieme("Second_b", 0);
		Bureaucrat Troisieme("Third_b", 155);
	}
	catch (const std::exception &e) {
		
	}
}