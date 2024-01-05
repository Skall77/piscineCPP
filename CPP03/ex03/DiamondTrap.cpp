/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:20:36 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/05 18:04:29 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): _name(ClapTrap::_name)
{
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "default DiamondTrap constructed called from ClapTrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name)
{
	this->_attack_damage = 30;
	this->_name = name;
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "DiamondTrap " << this->_name << " Created from ClapTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	*this = copy;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy)
{
	this->_name = copy._name;
	this->_hit_point = copy._hit_point;
	this->_attack_damage = copy._attack_damage;
	this->_energy_point = copy._energy_point;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " Destroyed" << std::endl;
}


void DiamondTrap::whoAmI()
{
	std::cout << "Hi, my DiamondTrap name is " << this->_name;
	std::cout << " And my ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::status(void)
{
	std::cout << "This DiamondTrap name is " << this->_name << "\n";
	std::cout << "HitPoint is " << _hit_point << "\n" << "EnergyPoint is " << _energy_point << "\n";
	std:: cout << "AttackDamage is " << _attack_damage << std::endl;
}
