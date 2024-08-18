/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 22:58:34 by ufitzhug          #+#    #+#             */
/*   Updated: 2024/08/19 00:08:06 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string ft_itos(int val)
{
	std::stringstream str_stream;
	str_stream << val;
	return (str_stream.str());
}


std::string ft_decrease_date(const std::string &curDate)
{
	size_t delim1 = curDate.find('-');
	size_t delim2 = curDate.find('-', delim1 + 1);
	int year = std::stoi(curDate.substr(0, delim1));
	int month = std::stoi(curDate.substr(delim1 + 1, delim2 - delim1 + 1));
	int day = std::stoi(curDate.substr(delim2 + 1));
	int day_q[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0)
		int day_q[1] = {28};
	if (day == 1 && month == 1)
	{
		year--;
		month = 12;
		day = 31;
	}
	else if (day == 1)
	{
		--month;
		day = day_q[month];
	}
	else 
		--day;
	return (ft_itos(year) + '-' + ft_itos(month) + '-' + ft_itos(day));
}

bool validate_date(std::string date)
{
	if (date.length() != 10)
		return false;
	size_t delim1 = date.find('-');
	int year = std::stoi(date.substr(0, delim1 + 1));
	if (year < 2009 || year > 2022 || delim1 == std::string::npos)
	{
		std::cerr << "Error. Wrong year" << std::endl;
		return false;
	}
	size_t delim2 = date.find('-', delim1 + 1);
	int month = std::stoi(date.substr(delim1 + 1, delim2 - delim1 - 1));
	if (month < 1 || month > 12 || delim1 == std::string::npos)
	{
		std::cerr << "Error. Wrong month" << std::endl;
		return false;
	}
	if (year == 2022 && month > 3)
	{
		std::cerr << "Provided date in 2022 is later than last available date" << std::endl;
		return false;
	}
	int day = std::stoi(date.substr(delim2 + 1));
	int day_q[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year % 4 == 0)
		int day_q[1] = {28};
	if (day > day_q[month-1] || day < 1)
	{
		std::cerr << "Error. Wrong quantity of days in month" << std::endl;
		return false;
	}
	if (date.length() != delim2 + 1 + std::to_string(day).length()) { // verify that is works with cstd98
        std::cerr << "Error. Invalid date format" << std::endl;
        return false;
    }
	return true;
}

bool validate_value(std::string value)
{
	try {
		size_t position;
		double val = std::stod(value,&position);
		if (position != value.length())
		{
			throw std::invalid_argument("Invalid input");
		}
		if (val < 0)
		{
			throw std::invalid_argument("Invalid input:Negative number");
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error" << e.what() << std::endl;
		return false;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error: out of range"  << std::endl;
		return false;
	}
	return true;
}


bool BitcoinExchange::read_db(std::string data1)
{
	std::fstream db_data(data1, std::fstream::in);
	if (db_data.is_open())
	{
		std::cout << "Database is opened successfully" << std::endl;
		std::string line;
		size_t divider;
		std::getline(db_data, line);
		while (std::getline(db_data, line))
		{
			divider = line.find(',');
			std::string rate = line.substr(divider + 1);
			this->btc_db[line.substr(0, divider)] = std::stof(rate);
		}
		db_data.close();
	}
	else
	{
		std::cerr << "Error with opening file" << std::endl;
		return 1;
	}
	return 0;
}

BitcoinExchange::BitcoinExchange(std::string input): address(input)
{
	std::cout << "BitcoinExchange constructor is called" << std::endl;
	exec(address);
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor is called" << std::endl;
}

void BitcoinExchange::exec(std::string address)
{
	if (read_db(DATABASE) == false)
	{
		std::cerr << "Error with opening Database" << std::endl;
		return;
	}
	std::fstream file1(address, std::fstream::in);
	if (file1.is_open())
	{
		std::cout << "File of input is opened successfully" << std::endl;
		std::string line;
		std::getline(file1, line);
		while (std::getline(file1, line))
		{
			size_t delim = line.find('|');
			if  (delim == std::string::npos || (delim + 2) < line.size())
				std::cerr << "Error. Wrong data " << "in line: " << line << std::endl;
			std::string date = line.substr(0, delim);
			std::string val = line.substr(delim + 1);
			if (validate_date(date) == false || validate_value(val) == false)
				return;
			std::map<std::string, float>::iterator iter;
			std::string previousDate = date;
			iter = this->btc_db.find(date);
			while (iter == this->btc_db.end())
			{
				std::string currentDate = previousDate;
				previousDate = ft_decrease_date(currentDate);
				iter = this->btc_db.find(previousDate);
			}
			std::cout << date << " =>>> " << val << " " << std::stof(val) * iter->second << std::endl;
			file1.close();
		}
	}
	else
	{
		std::cerr << "Error with opening file" << std::endl;
		return;
	}
}
