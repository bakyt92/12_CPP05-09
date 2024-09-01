/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:57 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/09/01 18:37:35 by ufitzhug         ###   ########.fr       */
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
	std::cout << "Result is: " << this->res << std::endl;
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
	int tmp = INT_MIN;
	int tmp1 = INT_MIN;
	std::size_t numbers = 0;
	std::string digs;
	while (i < input_line.size())
	{
		// std::cout << "size T == " << i << std::endl;
		if (input_line[i] == ' ')
			i++;
		if (isdigit(input_line[i]))
		{
			if (i > 3 && this->res != INT_MIN && isdigit(input_line[i - 2]))
			{
				numbers++;
				if (numbers == 2)
				{
					numbers = 0;
					tmp = this->digits.top();
					this->digits.pop();
					tmp1 = this->digits.top();
					this->digits.pop();
					this->digits.push(this->res);
					// std::cout << "PUSH int (res) " << this->digits.top() << std::endl;
					this->digits.push(tmp1);
					// std::cout << "PUSH int (tmp1) " << this->digits.top() << std::endl;
					this->digits.push(tmp);
					// std::cout << "PUSH int (tmp) " << this->digits.top() << std::endl;
					this->res = INT_MIN;
					tmp = INT_MIN;
					tmp1 = INT_MIN;
				}
			}
			digs.push_back(input_line[i]);
			i++;
			this->digits.push(ft_stoi(digs));
			// std::cout << "PUSH int " << this->digits.top() << std::endl;
			digs.clear();
		}
		if (input_line[i] == '*' || input_line[i] == '/' || input_line[i] == '+' || input_line[i] == '-')
		{
			this->res = ft_execute(input_line[i]);
			i++;
		}
	}
	return true;
}

int RPN::ft_execute(char c)
{
	long long tmp_res = 0;		
	if (this->res == INT_MIN)
	{
		tmp_res = this->digits.top();
		// std::cout << "First oper. Res is " << tmp_res << std::endl;
		this->digits.pop();	
	}
	else 
	{
		tmp_res = this->res;
	}
	if (this->digits.size() < 1)
	{
		std::cerr << "Size of stack<int> is below 1 (trying to execute with empty stack)" << std::endl;
		throw std::exception();
		return 1;
	}
	switch (c)
	{
		case '*':
			tmp_res = tmp_res * this->digits.top();
			if (tmp_res >= INT_MAX || tmp_res <= INT_MIN)
			{
				throw std::overflow_error("Calculated value is out of int range");
				return (1);
			}
			// std::cout << "operation *. Res is " << tmp_res << std::endl;
			this->digits.pop();
			this->res = tmp_res;
			break;
		case '+':
			tmp_res = tmp_res + this->digits.top();
			// std::cout << "operation +. Res is " << tmp_res << std::endl;
			this->digits.pop();
			this->res = tmp_res;
			break;
		case '-':
			tmp_res = tmp_res - this->digits.top();
			// std::cout << "operation -. Res is " << tmp_res << std::endl;
			this->digits.pop();
			this->res = tmp_res;
			break;
		case '/':
			if (this->digits.top() == 0)
				{
					std::cerr << "Error. Division by 0 is impossible. Current res will be returned" << std::endl;
					return (tmp_res);
				}
			else 
				tmp_res = tmp_res / this->digits.top();
			// std::cout << "operation /. Res is " << tmp_res << std::endl;
			this->digits.pop();
			this->res = tmp_res;
			break;
	}
	if (tmp_res >= INT_MAX || tmp_res <= INT_MIN)
		{
			throw std::overflow_error("Value out of int range");
			return (1);
		}
	return (static_cast<int>(tmp_res));
}