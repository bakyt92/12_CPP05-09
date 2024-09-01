/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:57 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/09/01 21:42:58 by ufitzhug         ###   ########.fr       */
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
	this->res = INT_MIN;
	try {
		if (ft_readline(this->line) == false)
			return;
	}
	catch (const std::overflow_error &e)
	{
		std::cerr << "Overflow error: " << e.what() << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Caught " << e.what() << std::endl;
		return;
	}
	std::cout << "Result is: " << this->digits.top() << std::endl;
	return;
}

RPN::RPN(const RPN &src)
{
	std::cout << "Copy constructor is called" << std::endl;
	this->line = src.line;
	this->res = src.res;
	this->digits = src.digits;
}

RPN& RPN::operator=(const RPN &rhs)
{
	std::cout << "Copy assignment operator is called" << std::endl;
	if (this != &rhs)
	{
		this->line = rhs.line;
		this->res = rhs.res;
		this->digits = rhs.digits;
	}
	return (*this);
}

RPN::~RPN()
{
	std::cout << "RPN destructor is called" << std::endl;
}

bool	RPN::ft_validation(std::string input_line)
{
	if (input_line.find_first_not_of(" */-+0123456789") != std::string::npos)
	{
		std::cerr << "Wrong symbols in the line" << std::endl;
		return false;
	}
	std::size_t i = 0;
	std::size_t digits = 0;
	std::size_t ops = 0;
	while (i < input_line.size())
	{
		if (isdigit(input_line[i]))
		{
			if (input_line[i + 1] != ' ' && input_line[i + 1] != '\n')
			{
				std::cerr << "Error. Next symbol to " << input_line[i] << " should be spase or endline" << std::endl;
				return false;
			}
			digits++;
			i++;
		}
		if (input_line[i] == '*' || input_line[i] == '/' || input_line[i] == '+' || input_line[i] == '-')
		{
			if (input_line[i + 1] != ' ' && (i + 1) < input_line.size())
			{
				std::cerr << "Error. Next symbol to " << input_line[i] << " should be space or endline" << std::endl;
				return false;
			}
			ops++;
			i++;
		}
		if (input_line[i] == ' ')
			i++;
	}
	if (digits < 2)
		{
			std::cerr << "Error. Less than 2 digits. Please add digits in input" << std::endl;
			return false;
		}
	if (digits != (ops + 1))
		{
			std::cerr << "Error. Wrong number of operators and digits" << std::endl;
			return false;
		}
	return true;
}

bool RPN::ft_readline(std::string input_line)
{
	if (ft_validation(input_line) == false)
		return false;
	std::size_t i = 0;
	std::string digs;
	while (i < input_line.size())
	{
		std::cout << "size T == " << i << std::endl;
		if (input_line[i] == ' ')
			i++;
		if (isdigit(input_line[i]))
		{
			digs.push_back(input_line[i]);
			i++;
			this->digits.push(ft_stoi(digs));
			std::cout << "PUSH int " << this->digits.top() << std::endl;
			digs.clear();
		}
		if (input_line[i] == '*' || input_line[i] == '/' || input_line[i] == '+' || input_line[i] == '-')
		{
			if (ft_execute(input_line[i]) == false)
				return false;
			i++;
		}
	}
	return true;
}

bool RPN::ft_execute(char c)
{
	long long oper1 = 0;
	long long oper2 = 0;
	long long res = 0;
	if (this->digits.size() < 2)
	{
		std::cerr << "Size of stack<int> is below 2 (trying to execute with empty stack)" << std::endl;
		throw std::exception();
		return false;
	}
	oper1 = this->digits.top();
	this->digits.pop();
	oper2 = this->digits.top();
	this->digits.pop();
	switch (c)
	{
		case '*':
			res = oper1 * oper2;
			if (res >= INT_MAX || res <= INT_MIN)
			{
				throw std::overflow_error("Calculated value is out of int range");
				return (1);
			}
			std::cout << "operation *. Res is " << res << std::endl;
			this->digits.push(static_cast<int>(res));
			break;
		case '+':
			res = oper1 + oper2;
			std::cout << "operation +. Res is " << res << std::endl;
			this->digits.push(static_cast<int>(res));
			break;
		case '-':
			res = oper2 - oper1;
			std::cout << "operation -. Res is " << res << std::endl;
			this->digits.push(static_cast<int>(res));
			break;
		case '/':
			if (oper1 == 0)
				{
					std::cerr << "Error. Division by 0 is impossible" << std::endl;
					return (false);
				}
			else 
				res = oper2 / oper1;
			std::cout << "operation /. Res is " << res << std::endl;
			this->digits.push(static_cast<int>(res));
			break;
	}
	if (res >= INT_MAX || res <= INT_MIN)
		{
			throw std::overflow_error("Value out of int range");
			return (1);
		}
	return(true);
}