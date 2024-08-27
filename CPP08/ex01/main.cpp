/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 17:53:25 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/27 21:45:03 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(6);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(14);
		sp.addNumber(5);
	}
	catch (const QuantityException& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	/* TEST */
	std::cout << "*-----NEW TEST---------*" << std::endl;
	Span S2 = Span(10000);
	try {
		S2.addPlenty(9999);
	}
	catch (const QuantityException&e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << S2.shortestSpan() << std::endl;
	std::cout << S2.longestSpan() << std::endl;
	return 0;
}