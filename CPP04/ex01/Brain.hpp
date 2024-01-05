/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:41:12 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/08 15:55:17 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
public :
	Brain();
	Brain(const Brain& copy);
	Brain& operator=(const Brain&copy);
	
	 ~Brain();

	std::string const &getIdea( int const &n) const;
	void setIdea(std::string const &idea, int const &n);
	
protected:
	std::string _ideas[100];
};

#endif