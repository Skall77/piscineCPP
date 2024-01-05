/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:35:34 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/30 10:28:28 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie 
{
	public:
		Zombie(std::string	name);
		~Zombie(void);
		void announce(void);

		
	private:
		std::string	_name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );




#endif