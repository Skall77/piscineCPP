/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:35:34 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/28 08:47:55 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie 
{
	public:
		Zombie(void);
		~Zombie(void);
		void announce(void);
		void setName(std::string name);

		
	private:
		std::string	_name;
};

Zombie* ZombieHorde( int N, std::string name );




#endif