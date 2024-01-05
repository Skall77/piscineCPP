/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/01 10:48:31 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap Bob("Bob");
	ScavTrap Serena("Serena");
	std::cout << "///////" << std::endl;
	Bob.attack("Serena");
	Serena.takeDamage(0);
	Serena.attack("Bob");
	Bob.takeDamage(20);
	Bob.beRepaired(7);
	Serena.guardGate();
	std::cout << "///////" << std::endl;
	for(int i = 0; i < 50; i++)
		Serena.attack("Bob");
	std::cout << "///////" << std::endl;
	ScavTrap Selena("Selena");
	Selena.takeDamage(10);
	Selena.beRepaired(20);
	Selena.takeDamage(200);
	Selena.attack("Bob");
	std::cout << "///////" << std::endl;
	return 0;
}