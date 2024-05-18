/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:11:10 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/18 20:18:06 by ufitzhug         ###   ########.fr       */
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
	if (CheckInput(input) == false)
		{
			std::cout << "Please input correct type of data (Char, Int, Float, Double)" << std::endl;
		}
	else 
	{
		ConvertToChar(input);
		ConvertToInt(input);
		ConvertToFloat(input);
		ConvertToDouble(input);
	}
	return ;
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
	else if (IsFloat(input) == true)
		return true;
	else 
		return false;
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
		i++;
	}
	if (counter != 1)
		return false;
	else if (str.find_first_not_of("-+0123456789.") == std::string::npos)
		return true;
	else if (str.find_first_not_of("-+0123456789.") != std::string::npos)
		return false;
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
		i++;
	}
	if (counter_point != 1 || counter_f != 1)
		return false;
	else if (str.find_first_not_of("-+0123456789.f") == std::string::npos)
		return true;
	else if (str.find_first_not_of("-+0123456789.f") != std::string::npos)
		return false; 	
}

void ScalarConverter::ConvertToChar(const std::string &str)
{
	if (str == "+inff" || str == "-inff" || str == "nanf" \
		|| str == "+inf" || str == "-inf" || str == "nan")
	{
		std::cout << "Char: impossible" << std::endl;
		return ;
	}
	else if (str.length() == 1 && !isdigit(str[0]))
	{
		if (isprint(str[0]) != 0)
		{
			std::cout << "Char: " << static_cast<char>(str[0]) << std::endl;
			return ;
		}
		else
		{
			std::cout << "Char: Non-displayable" << std::endl;
			return ;
		}
	}
	else 
	{
		char *Ptr1 = NULL;
		double res = strtod(str.c_str(), &Ptr1);
		if (errno == ERANGE && (res == HUGE_VAL || res == -HUGE_VAL) || res > 255 || res < 0)
		{
			std::cout << "Char: impossible" << std::endl;
		}
		else if (isprint(res) == 0)
		{
			std::cout << "Char: Non-displayable" << std::endl;
		}
		else 
		{
			std::cout << "Char: " << static_cast<char>(res) << std::endl;
		}
		return;
	}
}
	
void ScalarConverter::ConvertToInt(const std::string &str)
{
	if (str == "+inff" || str == "-inff" || str == "nanf" \
		|| str == "+inf" || str == "-inf" || str == "nan")
	{
		std::cout << "Int: impossible" << std::endl;
		return ;
	}
	else if (str.length() == 1 && !isdigit(str[0]))
	{
		std::cout << "Int: " << static_cast<int>(str[0]) << std::endl;
		return ;
	}
	else
	{
		char *Ptr1 = NULL;
		double res = strtod(str.c_str(), &Ptr1);
		if (errno == ERANGE && (res == HUGE_VAL || res == -HUGE_VAL) || res > INT_MAX || res < INT_MIN)
			std::cout << "Int: impossible" << std::endl;
		else
			std::cout << "Int: " << static_cast<int>(res) << std::endl;
	}
}
	
void ScalarConverter::ConvertToFloat(const std::string &str)
{

}
	
void ScalarConverter::ConvertToDouble(const std::string &str)
{

}