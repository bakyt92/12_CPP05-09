/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:21 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/25 16:07:17 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename Container>
PmergeMe<Container>::PmergeMe (char **input)
{
	std::cout << "Constructor for instance PmergeMe is called" << std::endl;
	
}

template<typename Container>
PmergeMe<Container>::~PmergeMe ()
{
	std::cout << "Destructor for instance PmergeMe is called" << std::endl;
}