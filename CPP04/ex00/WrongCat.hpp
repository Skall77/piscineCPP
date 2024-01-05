/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:45:47 by aaudevar          #+#    #+#             */
/*   Updated: 2023/02/06 17:50:21 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public :
	WrongCat();
	WrongCat(const WrongCat& copy);
	WrongCat& operator=(const WrongCat&);
	
	~WrongCat();

	void makeSound() const;
	std::string getType() const;
	
protected:
	std::string _type;
};

#endif