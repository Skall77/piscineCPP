/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:11:34 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/05 16:48:00 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
public:

	FlagTrap();
	FlagTrap(std::string name);
	FlagTrap(const FlagTrap& copy);
	FlagTrap& operator=(const FlagTrap& copy);
	
	~FlagTrap();

	void highFivesGuys(void);

};

#endif