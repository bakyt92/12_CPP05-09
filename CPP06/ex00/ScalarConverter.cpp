/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:11:10 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/18 02:36:29 by ufitzhug         ###   ########.fr       */
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
	else if (IsDouble(input) == true)
		return true;

}

bool ScalarConverter::IsInteger(const std::string &str)
{
    return str.find_first_not_of("-+0123456789") == std::string::npos;
}

bool ScalarConverter::IsPrintableChar(const std::string &str)
{
	if (str.size() == 1)
	{
		if (std::isprint(str[0]) != 0)
			return true;
	}
	else 
		return false;
}

bool ScalarConverter::IsDouble(const std::string &str)
{
	if (str == "-inf" || str == "+inf" || str == "nan")
		return true;
	size_t iter = str.find(".");
	if (iter == std::string::npos)
		return false;
	int i = 0;
	int counter = 0;
	int n = str.size();
	while (i < n)
	{
		if (str[i] == '.')
			counter++;
	}
	if (counter != 1)
		return false;
	else if (str.find_first_not_of("-+0123456789.") == std::string::npos)
		return true;
}


bool ScalarConverter::IsFloat(const std::string &str)
{
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	size_t iter = str.find(".");
	if (iter == std::string::npos)
		return false;
	int i = 0;
	int counter_point = 0;
	int counter_f = 0;
	int n = str.size();
	if (str[n - 1] != 'f')
		return false;
	while (i < n)
	{
		if (str[i] == '.')
			counter_point++;
		if (str[i] == 'f')
			counter_f++;
	}
	if (counter_point != 1 || counter_f != 1)
		return false;
	else if (str.find_first_not_of("-+0123456789.f") == std::string::npos)
		return true;
}