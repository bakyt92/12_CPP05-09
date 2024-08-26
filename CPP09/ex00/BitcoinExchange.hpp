/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:37 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/26 20:55:54 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DATABASE "./data.csv"

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

class BitcoinExchange
{
private:
	std::string address;
	BitcoinExchange();
	std::map<std::string, float> btc_db;
public:
	BitcoinExchange(std::string input);
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange& operator=(const BitcoinExchange &rhs);
	void exec(std::string address);
	bool read_db(std::string data1);
	~BitcoinExchange();
};

bool validate_date(std::string date);
bool validate_value(std::string value);
std::string ft_decrease_date(const std::string &curDate);
int ft_stoi (const std::string &str);
float ft_stof (const std::string &str);
std::string ft_itos(const int &val);

#endif