/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:17:18 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/20 19:31:21 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T> 
void swap(T &x, T &y)
{
    T temp;
	temp = y;
	y = x;
	x = temp;
	return ;
}

template <typename T> 
T max(T &x, T &y)
{
	if (x > y)
		return x;
	else if (y > x)
		return y;
	else 
		return y;
}

template <typename T> 
T min(T &x, T &y)
{
	if (x > y)
		return y;
	else if (y > x)
		return x;
	else 
		return y;
}

#endif