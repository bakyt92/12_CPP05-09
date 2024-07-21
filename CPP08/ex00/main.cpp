/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:41:42 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/07/21 23:33:26 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main ()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
	}
	std::cout << "vec: ";
	for (std::vector<int>::iterator iter = vec.begin(), end = vec.end(); iter != end; iter++)
	{
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	try {
		easyfind(vec, 2);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try {
		easyfind(vec, 22);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}