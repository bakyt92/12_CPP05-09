/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:11:10 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/08 22:19:59 by ufitzhug         ###   ########.fr       */
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

static bool IsInteger(const std::string &str)
{
    return str.find_first_not_of("-+0123456789") == std::string::npos;
}

static bool IsPrintableChar(const std::string &str)
{
	if (str.size() == 1)
	{
		if (std::isprint(str[0]) != 0)
			return true;
	}
	return false;
}

static bool IsDouble(const std::string &str)
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
	else
		return false;
}


static bool IsFloat(const std::string &str)
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
	return false; 	
}

static void ConvertToChar(const std::string &str)
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
		if ((errno == ERANGE && (res == HUGE_VAL || res == -HUGE_VAL)) || res > 255 || res < 0)
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
	
static void ConvertToInt(const std::string &str)
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
		if ((errno == ERANGE && (res == HUGE_VAL || res == -HUGE_VAL)) || res > INT_MAX || res < INT_MIN)
			std::cout << "Int: impossible" << std::endl;
		else
			std::cout << "Int: " << static_cast<int>(res) << std::endl;
	}
}
	
static void ConvertToFloat(const std::string &str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
			std::cout << "Float: " << str << "f" << std::endl;
	else if (str == "nanf" || str == "+inff" || str == "-inff")
			std::cout << "Float: " << str << std::endl;
	else if (str.length() == 1 && !isdigit(str[0]))
		std::cout << "Float: " << std::setprecision(1) << static_cast<float>(str[0]) << "f" << std::endl;
	else
	{
		char *Ptr1 = NULL;
		double res = strtod(str.c_str(), &Ptr1);
		std::cout << res << " " << errno << std::endl;
		std::cout << "MAX: " <<  FLT_MAX  << " MIN: " <<  FLT_MIN << std::endl;
		if (((errno == ERANGE && (res == HUGE_VAL || res == -HUGE_VAL))) || res > FLT_MAX || res < -FLT_MAX ) // СПРОСИТЬ почему ошибка возникает.
			std::cout << "Float: impossible" << std::endl;
		else
			std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(res) << "f" << std::endl;
	}
	return ;
}
	
static void ConvertToDouble(const std::string &str)
{
	if (str == "nan" || str == "+inf" || str == "-inf")
			std::cout << "Double: " << str << std::endl;
	else if (str == "nanf" || str == "+inff" || str == "-inff")
	{
		std::cout << "Double: " << str.substr(0, str.length() - 1) << std::endl;
	}
			
	else if (str.length() == 1 && !isdigit(str[0]))
		std::cout << "Double: " << std::setprecision(1) << static_cast<double>(str[0]) << std::endl;
	else
	{
		char *Ptr1 = NULL;
		double res = strtod(str.c_str(), &Ptr1);
		if (errno == ERANGE && (res == HUGE_VAL || res == -HUGE_VAL))
			std::cout << "Double: impossible" << std::endl;
		else
			std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(res) << std::endl;
	}
	return ;
}

/* CheckInput verifies that input is either char / int / double or float */
static bool CheckInput(std::string input)
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

void ScalarConverter::Convert(std::string input)
{
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
