/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:39:13 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/20 20:51:08 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void ft_myltiplier2(T&)
{
	T = T * 2;
	return;
}

template <typename T>
void ft_addition1(T&)
{
	T = T + 1;
	return;
}

template <typename T> 
void iter(T &array, int length, void (*ft_func)(T&))
{
    int i = 0;
	while (i < length)
	{
		std::cout << ft_func(array[i]) << std::endl;
		i++;
	}
	return ;
}

#endif