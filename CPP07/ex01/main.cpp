/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:39:17 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/20 19:57:16 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int ft_myltiplier2(int input)
{
	return (input * 2);
}

int main()
{
	int array[5] = {1, 2, 3, 4, 5};
	::iter(array, 5, ft_myltiplier2(*array));
	return 0;
}