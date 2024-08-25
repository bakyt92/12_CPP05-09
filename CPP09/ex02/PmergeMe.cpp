/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:21 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/25 17:59:17 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename Container>
int PmergeMe<Container>::ft_stoi(char *input)
{
	std::istringstream ss(input);
	int num;
	ss >> num;
	return (num);
}

template<typename Container>
void PmergeMe<Container>::ft_print_all(void) 
{
	size_t i = 0;
	while (i < _data.size())
	{
		std::cout << _data[i] << " _";
	}
	std::cout << std::endl;
}


template<typename Container>
PmergeMe<Container>::PmergeMe (char **input)
{
	std::cout << "Constructor for instance PmergeMe is called" << std::endl;
	_time = 0;
	_last = -1;
	size_t	i = 0;
	while (input[i])
	{
		if (!isdigit(input[i]) || input[i] == '-')
			{
				std::cerr << "Error. Wrong input" << std::endl;
				return;
			}
		_data.push_back(ft_stoi(input[i]));
		i++;
	}
}



template<typename Container>
PmergeMe<Container>::~PmergeMe ()
{
	std::cout << "Destructor for instance PmergeMe is called" << std::endl;
}