/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:39:13 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/20 19:56:01 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

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