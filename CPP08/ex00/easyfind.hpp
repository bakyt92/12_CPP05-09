/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:41:38 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/07/22 00:11:13 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND
#define EASYFIND

#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <exception>
#include <sstream>

class EasyException : public std::exception {
	public:
		const char* what() const throw() {
        	return "easyfind: exception: element not found in container";
    }
};

template <typename T> bool easyfind (T& container, int x)
{
	if (std::find (container.begin(), container.end(), x) == container.end())
	{
		throw EasyException();
	}
	else 
		return true;
}

#endif

