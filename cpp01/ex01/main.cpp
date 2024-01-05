/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/03/28 08:47:45 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define HORDE_SIZE 25

int main(void)
{
	Zombie *horde = ZombieHorde(HORDE_SIZE,"Alexis");
	for (int i = 0; i < HORDE_SIZE; i++)
		horde[i].announce();
	if (horde)
		delete [] horde;
}