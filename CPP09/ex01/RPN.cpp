/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:57 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/23 00:20:08 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::string ft_ctos(char *input)
{
	std::stringstream ss;
	ss<< input;
	std::string s1 = ss.str();
	return s1;
}

int ft_stoi(std::string input)
{
	std::stringstream ss(input);
	int i; 
	ss >> i;
	return i;
}


RPN::RPN(char* input)
{
	std::cout << "RPN constructor is called" << std::endl;
	this->line = ft_ctos(input);
	if (ft_readline(this->line) == false)
		return;
	if (this->ops.size() < 1 || this->digits.size() < 2)
	{
		std::cerr << "Wrong number of agruments" << std::endl;
		return;
	}
	if (this->digits.size() == (this->ops.size() - 1))
		std::cout << "Correct number of digits and ops" << std::endl;
	else 
	{
		std::cerr << "Wrong number of digits and operations" << std::endl;
		return;
	}
	
}

RPN::~RPN()
{
	std::cout << "RPN destructor is called" << std::endl;
}

bool RPN::ft_readline(std::string input_line)
{
	if (input_line.find_first_not_of(" */-+0123456789") != std::string::npos)
	{
		std::cerr << "Wrong symbols in the line" << std::endl;
		return false;
	}
	int i = 0;
	std::string digs;
	while (i <= input_line.size())
	{
		if (input_line[i] == ' ')
			i++;
		if (isdigit(input_line[i]))
		{
			while (isdigit(input_line[i]))
			{
				digs.push_back(input_line[i]);
				i++;
			}
			this->digits.push(ft_stoi(digs));
			digs.clear();
		}
		if (input_line[i] == '*' || input_line[i] == '/' || input_line[i] == '+' || input_line[i] == '-')
		{
			this->ops.push(input_line[i]);
			i++;	
		}
	}
	return true;
}