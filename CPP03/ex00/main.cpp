/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/01 10:29:45 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap Bob("Bob");
	ClapTrap Bobby("Bobby");
	
	Bob.attack("Bill");
	Bob.takeDamage(5);
	Bob.beRepaired(7);
	Bob.takeDamage(12);
	Bob.attack("Bill");
	Bob.takeDamage(5);
	Bob.beRepaired(7);
	std::cout << "///////" << std::endl;
	Bobby.attack("Bill");
	Bobby.attack("Bill");
	Bobby.attack("Bill");
	Bobby.attack("Bill");
	Bobby.takeDamage(2);
	Bobby.beRepaired(1);
	Bobby.beRepaired(1);
	Bobby.attack("Bill");
	Bobby.attack("Bill");
	Bobby.attack("Bill");
	Bobby.takeDamage(2);
	Bobby.attack("Bill");
	Bobby.attack("Bill");
		
	return 0;
}