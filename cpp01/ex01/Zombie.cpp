/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:51:14 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/30 11:31:34 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->_name = "anonymous";
	std::cout << "The zombie : " << this->_name << " is alive (undead technically)" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "The zombie : " << this->_name << " is dead (Like really dead, not zombie dead)" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << Zombie::_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}