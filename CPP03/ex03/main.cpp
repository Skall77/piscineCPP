/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/01 11:27:41 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap Bob("Bob");
	ScavTrap Serena("Serena");
	FlagTrap Flaggy("Flaggy");
	DiamondTrap Gigabob("Gigabob");

	std::cout << "//////" << std::endl;

	Gigabob.whoAmI();

	std::cout << "//////" << std::endl;

	Gigabob.status();

	std::cout << "//////" << std::endl;

	Gigabob.attack("Serena");
	Serena.takeDamage(30);
	Bob.attack("Gigabob");
	Gigabob.takeDamage(0);
	Gigabob.highFivesGuys();
	Gigabob.guardGate();
	Flaggy.attack("Gigabob");
	Gigabob.takeDamage(30);

	std::cout << "//////" << std::endl;

	Gigabob.status();

	std::cout << "//////" << std::endl;

	Serena.attack("Gigabob");
	Gigabob.takeDamage(20);
	Gigabob.attack("Serena");
	Serena.takeDamage(30);
	Flaggy.attack("Gigabob");
	Gigabob.takeDamage(30);
	Gigabob.attack("Flaggy");
	Serena.takeDamage(30);
	Serena.attack("Gigabob");
	Gigabob.takeDamage(20);
	Gigabob.beRepaired(10);
	
	std::cout << "//////" << std::endl;
	return 0;
}