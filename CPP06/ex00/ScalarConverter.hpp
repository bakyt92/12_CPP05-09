/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:11:12 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/18 21:33:41 by ufitzhug         ###   ########.fr       */
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
// private:
// 	/* data */
public:
	ScalarConverter();
	void Convert(std::string input);
	bool CheckInput(std::string input);
	bool IsPrintableChar(const std::string &str);
	bool IsInteger(const std::string &str);
	bool IsDouble(const std::string &str);
	bool IsFloat(const std::string &str);
	void ConvertToChar(const std::string &str);
	void ConvertToInt(const std::string &str);
	void ConvertToFloat(const std::string &str);
	void ConvertToDouble(const std::string &str);
	~ScalarConverter();
};


#endif