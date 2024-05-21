/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:39:13 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/21 03:16:25 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void ft_myltiplier2(T& input)
{
	input = input * 2;
	return;
}

template <typename T>
void ft_addition1(T& input)
{
	input = input + 1;
	return;
}

template <typename T, typename F> 
void iter(T* array, int length, F ft_func)
{
    int i = 0;
	while (i < length)
	{
		ft_func(array[i]);
		std::cout << array[i] << std::endl;
		i++;
	}
	return ;
}

#endif