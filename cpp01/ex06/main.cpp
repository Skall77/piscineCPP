/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/30 17:10:14 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl Karen;
	
	if (argc != 2)
	{
		std::cout << "Exactly 1 argument" << std::endl;
		return 1;
	}
	Karen.complain(argv[1]);
	
	return 0;
}