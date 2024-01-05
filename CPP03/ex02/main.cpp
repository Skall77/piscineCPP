/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/01 11:05:35 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FlagTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap Bob("Bob");
	ScavTrap Serena("Serena");
	FlagTrap Flaggy("Flaggy");
	
	std::cout << "//////" << std::endl;
	Bob.attack("Serena");
	Serena.takeDamage(0);
	Bob.attack("Flaggy");
	Flaggy.takeDamage(0);
	Flaggy.highFivesGuys();
	//Bob.highFivesGuys();
	//Serena.highFivesGuys();
	std::cout << "//////" << std::endl;
	Serena.guardGate();
	//Bob.guardGate();
	//Flaggy.guardGate();
	Serena.attack("Bob");
	Bob.takeDamage(20);
	Bob.beRepaired(7);
	for (int i = 0; i < 3; i++)
	{
		Flaggy.attack("Serena");
		Serena.takeDamage(30);
		Serena.attack("Flaggy");
		Flaggy.takeDamage(20);
	}
	Flaggy.attack("Serena");
	Serena.takeDamage(30);
	Serena.attack("Flaggy");
	for (int i = 0; i < 96; i++)
		Flaggy.highFivesGuys();
	std::cout << "//////" << std::endl;
	return 0;
}