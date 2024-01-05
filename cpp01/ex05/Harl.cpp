/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:03:46 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/28 10:08:21 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Constructor of Harl called" << std::endl;
}

Harl::~Harl()
{
	std::cout << "Destructor of Harl called" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;
	
	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*f[i])();
			break;
		}
	}
	if (i == 4)
		std::cout << "\033[1;35m[random gibberish]\033[0m" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "\033[1;32m[ DEBUG ]\033[0m" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "\033[1;34m[ INFO ]\033[0m" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "\033[1;33m[ WARNING ]\033[0m" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "\033[1;31m[ ERROR ]\033[0m" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}
