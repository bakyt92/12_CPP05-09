/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:11:10 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/17 19:31:23 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverver constructor is called" << std::endl;
	
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverver destructor is called" << std::endl;
}

void ScalarConverter::Convert(std::string input)
{
	std::cout << "ScalarConverver constructor is called" << std::endl;
	
}

/* CheckInput verifies that input is either char / int / double or float */
bool ScalarConverter::CheckInput(std::string input)
{
	if (IsPrintableChar(input) == true)
		return true;
	else if (IsInteger(input) == true)
		return true;
}

bool IsInteger(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

bool IsPrintableChar(const std::string &str)
{
	if (str.size() == 1)
	{
		if (std::isprint(str[0]) != 0)
			return true;
	}
	else 
		return false;
}