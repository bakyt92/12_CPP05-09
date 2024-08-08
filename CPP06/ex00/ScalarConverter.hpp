/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:11:12 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/08 22:27:32 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <stdlib.h>
#include <cmath>
#include <limits.h>
#include <limits>
#include <iomanip>
#include <errno.h>
#include <cfloat>

class ScalarConverter
{
public:
	ScalarConverter();
	static void Convert(std::string input);
	~ScalarConverter();
};

#endif