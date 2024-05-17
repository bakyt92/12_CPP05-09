/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:11:12 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/05/17 19:20:48 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>

class ScalarConverter
{
private:
	/* data */
public:
	ScalarConverter();
	void Convert(std::string input);
	bool CheckInput(std::string input);
	bool IsPrintableChar(const std::string input);
	bool IsInteger(const std::string input);
	~ScalarConverter();
};


#endif