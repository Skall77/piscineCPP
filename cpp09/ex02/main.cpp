/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:04:25 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/24 18:04:25 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) 
{

	if (argc == 1)
		return (0);
	
	try
	{
		PmergeMe PMM(argc, argv);
		PMM.DisplayBefore();
		PMM.DisplayAfter();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	
	return(0);
}