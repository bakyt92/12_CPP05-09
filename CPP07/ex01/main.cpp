/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:39:17 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/21 16:42:51 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	int array[6] = {1, 2, 3, 4, 11, 15};
	// ::iter(array, 5, ft_myltiplier2);
	::iter<int>(array, 6, ft_myltiplier2);
	::iter<int>(array, 6, ft_addition1);
	return 0;
}