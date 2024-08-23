/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:57 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/23 22:17:14 by ufitzhug         ###   ########.fr       */
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
	if (this->digits.size() == (this->ops.size() + 1))
		std::cout << "Correct number of digits and ops" << std::endl;
	else 
	{
		std::cerr << "Wrong number of digits and operations" << std::endl;
		return;
	}
	std::cout << ft_execute() << std::endl;
	return;
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
	std::size_t i = 0;
	std::string digs;
	while (i < input_line.size())
	{
		std::cout << "size T === " << i << std::endl;
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
			std::cout << "PUSH int " << this->digits.top() << std::endl;
			digs.clear();
		}
		if (input_line[i] == '*' || input_line[i] == '/' || input_line[i] == '+' || input_line[i] == '-')
		{
			this->ops.push(input_line[i]);
			std::cout << "PUSH char to OPS: " << this->ops.top() << std::endl;
			i++;	
		}
	}
	return true;
}

int RPN::ft_execute(void)
{
	int tmp_res = this->digits.top();
	std::cout << "First oper. Res is " << tmp_res << std::endl;
	this->digits.pop();
	while (this->digits.size() > 0)
	{
		switch (this->ops.top())
		{
		case '*':
			tmp_res = tmp_res * this->digits.top();
			std::cout << "operation *. Res is " << tmp_res << std::endl;
			this->digits.pop();
			this->ops.pop();
			break;
		case '+':
			tmp_res = tmp_res + this->digits.top();
			std::cout << "operation +. Res is " << tmp_res << std::endl;
			this->digits.pop();
			this->ops.pop();
			break;
		case '-':
			tmp_res = tmp_res - this->digits.top();
			std::cout << "operation -. Res is " << tmp_res << std::endl;
			this->digits.pop();
			this->ops.pop();
			break;
		case '/':
			if (this->digits.top() == 0)
				{
					std::cerr << "Error. Division by 0 is impossible. Current res will be returned" << std::endl;
					return (tmp_res);
				}
			else 
				tmp_res = tmp_res / this->digits.top();
			std::cout << "operation /. Res is " << tmp_res << std::endl;
			this->digits.pop();
			this->ops.pop();
			break;
		}
	}
	return (tmp_res);
}