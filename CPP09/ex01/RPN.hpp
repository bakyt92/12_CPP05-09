/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:59:02 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/28 21:59:12 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPH_HPP
#define RPH_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <climits>
#include <limits.h>
#include <stdlib.h>

std::string ft_ctos(char *input);
int ft_stoi(std::string input);

class RPN
{
private:
	std::string line;
	std::stack<int> digits;
	int res;
public:
	RPN(char* input);
	~RPN();
	int ft_execute(char c);
	bool ft_readline(std::string input_line);
	bool ft_validation(std::string input_line);
};

#endif