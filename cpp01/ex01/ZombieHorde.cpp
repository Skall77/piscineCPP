/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:44:38 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/28 08:47:28 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* ZombieHorde( int N, std::string name )
{
	if (N > 0)
	{
		Zombie *horde = new Zombie[N];
		for(int i = 0; i < N; i++)
			horde[i].setName(name);
		return (horde);
	}
	return (NULL);
}
	
	