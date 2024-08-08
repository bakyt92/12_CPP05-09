/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:41 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/08 23:14:55 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error. Quantity of arguments is wrong" << std::endl;
	}
	else
	{
		BitcoinExchange instance1;
		instance1(argv[1])
	}
	return 0;
}