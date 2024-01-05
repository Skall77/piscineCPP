/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:11:30 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/01 11:10:11 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlagTrap.hpp"

FlagTrap::FlagTrap() : ClapTrap()
{
	this->_name = "FlagTrap";
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	this->_max_hit_point = _hit_point;
	std::cout << "default FlagTrap constructed called from ClapTrap" << std::endl;
}

FlagTrap::FlagTrap(std::string name) : ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	this->_max_hit_point = _hit_point;
	std::cout << "FlagTrap " << this->_name << " Created from ClapTrap" << std::endl;
}

FlagTrap::FlagTrap(const FlagTrap& copy)
{
	*this = copy;
}

FlagTrap& FlagTrap::operator=(const FlagTrap& copy)
{
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_attack_damage = copy._attack_damage;
	this->_energy_point = copy._energy_point;
	return (*this);
}

FlagTrap::~FlagTrap()
{
	std::cout << "FlagTrap " << this->_name << " Destroyed" << std::endl;
}

void FlagTrap::highFivesGuys(void)
{
	if (this->_energy_point > 0 && this->_hit_point > 0)
	{
		this->_energy_point--;
		std::cout << "FlagTrap " << this->_name << " give you a high five! ヘ( ^o^)ノ＼(^_^ )" <<  std::endl;
	}
	else if (this->_energy_point != 0)
		std::cout << "FlagTrap "<< this->_name << " have been dismantled" << std::endl;
	else
		std::cout << "FlagTrap "<< this->_name << " is exhausted :(" << std::endl;
}
