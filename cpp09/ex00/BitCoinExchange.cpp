/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:52:06 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/30 09:52:06 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"
#include <sstream>
#include <fstream>


BitCoinExchange::BitCoinExchange()
{
}

BitCoinExchange::BitCoinExchange(std::ifstream& db)
{
	MakeDB(db);
}

BitCoinExchange::BitCoinExchange(const BitCoinExchange& copy)
{
	*this = copy;
}

BitCoinExchange& BitCoinExchange::operator=(const BitCoinExchange& obj)
{
	this->_DB = obj._DB;
	return (*this);
}

BitCoinExchange::~BitCoinExchange()
{
}

float stringToFloat(const std::string& s)
{
	float n;

	std::stringstream ss(s);

	ss >> n;
	return (n);
}

void BitCoinExchange::MakeDB(std::ifstream& db)
{
	std::string line;
	size_t		delimiter;

	std::getline(db, line);
	while (std::getline(db, line))
	{
		delimiter = line.find(',');
		this->_DB[line.substr(0, delimiter)] = stringToFloat(line.substr(delimiter + 1));
	}
}

float BitCoinExchange::getExchangeRate(const std::string& date)
{
	if (this->_DB.count(date) > 0)
		return (this->_DB.at(date));
	else
		return ((--this->_DB.lower_bound(date))->second);
}

bool BitCoinExchange::checkDateFormat(const std::string& date)
{
	if (date.empty())
		return (false);
	if (date.find('-') == std::string::npos 
		|| date.find('-', date.find('-') + 1) == std::string::npos
		|| date.find_first_not_of("-.0123456789 \t\n\r\f\v") != std::string::npos)
	{
		std::cerr << "Error: Bad date format, try 'Year-Month-Day' => " << date << std::endl;
		return (false);
	}
	return (true);		
}

int stringToInt(const std::string& s)
{
	int n;

	std::stringstream ss(s);

	ss >> n;
	return (n);
}

bool BitCoinExchange::checkValidDate(const std::string& date)
{
	std::string line;
	std::istringstream ss(date);
	int month;
	int i = 0;

	while (std::getline(ss, line, '-'))
	{
		if (i == 0)
		{
			if (stringToInt(line) < 2009 || stringToInt(line) > 2023)
			{
				std::cerr << "Error: Year isn't valid => " << date << std::endl;
				return (false);
			}
		}
		if (i == 1)
		{
			month = stringToInt(line);
			if (month < 1 || month > 12)
			{
				std::cerr << "Error: Month isn't valid => " << date << std::endl;
				return (false);
			}
		}
		if (i == 2)
		{
			if ((stringToInt(line) < 1 || stringToInt(line) > 31)
				|| (stringToInt(line) == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
				|| (stringToInt(line) > 28 && month == 2))
			{
				std::cerr << "Error: Day isn't valid => " << date << std::endl;
				return (false);
			}
		}
		i++;
	}
	if (i != 3)
	{
		std::cerr << "Error: date isn't valid => " << date << std::endl;
				return (false);
	}
	return (true);
}

bool BitCoinExchange::checkExchangeRate(const std::string& eRate)
{
	if (eRate.empty()
		|| eRate.find_first_not_of(".-0123456789 \t\n\r\f\v") != std::string::npos
		|| eRate.at(0) == '.'
		|| eRate.find('.', eRate.find('.') + 1) != std::string::npos)
		std::cerr << "Error: Rate isn't valid => " << eRate << std::endl;
	else if (eRate.at(0) == '-')
		std::cerr << "Error:  not a positive number." << std::endl;
	else if (stringToInt(eRate) > 1000)
		std::cerr << "Error: too large a number." << std::endl;
	else
		return (true);
	return (false);
}
