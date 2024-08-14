/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:37 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/14 22:23:25 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DATABASE "./data.csv"

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::string address;
	BitcoinExchange();
	std::map<std::string, float> btc_db;
public:
	BitcoinExchange(std::string input);
	void exec(std::string address);
	bool read_db(std::string data1);
	~BitcoinExchange();
};

void validate_date(std::string date);
void validate_value(std::string value);

#endif