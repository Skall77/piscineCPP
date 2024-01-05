/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:58:30 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/01 10:59:11 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "ScavTrap";
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	this->_max_hit_point = _hit_point;
	std::cout << "default ScavTrap constructed called from ClapTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	this->_max_hit_point = _hit_point;
	std::cout << "ScavTrap " << this->_name << " Created from ClapTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy)
{
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_attack_damage = copy._attack_damage;
	this->_energy_point = copy._energy_point;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " Destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energy_point > 0 && this->_hit_point > 0)
	{
		this->_energy_point--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target;
		std::cout << " with the Bulletnator 9000, causing " << this->_attack_damage << " points of damage !" << std::endl;
	}
	else if (this->_energy_point != 0)
		std::cout << "ScavTrap "<< this->_name << " is dead. :(" << std::endl;
	else
		std::cout << "Scavtrap "<< this->_name << " is out of energy, she's too old and tired for this shit :(" << std::endl;
}

void ScavTrap::guardGate()
{
	if (this->_energy_point > 0 && this->_hit_point > 0)
	{
		this->_energy_point--;
		std::cout << "ScavTrap " << this->_name << " is now in Gatekeeper mode " <<  std::endl;
	}
	else if (this->_energy_point != 0)
		std::cout << "ScavTrap "<< this->_name << " is dead. :(" << std::endl;
	else
		std::cout << "Scavtrap "<< this->_name << " is out of energy, she's too old and tired for this shit :(" << std::endl;
}