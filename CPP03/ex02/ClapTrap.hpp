/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:42:18 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/05 16:58:50 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ClapTrap_H
#define ClapTrap_H

#include <string>
#include <iostream>

class ClapTrap 
{
public:

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& copy);
	ClapTrap& operator=(const ClapTrap& copy);

	virtual ~ClapTrap();

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

protected:
	std::string		_name;
	unsigned int	_hit_point;
	unsigned int	_energy_point;
	unsigned int	_attack_damage;
	unsigned int	_max_hit_point;
	
};

#endif // ClapTrap_H