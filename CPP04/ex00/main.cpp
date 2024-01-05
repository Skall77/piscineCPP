/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/05/15 10:50:48 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "///////" << std::endl;
	std::cout << "The Animal meta is of type : " << meta->getType() << std::endl;
	std::cout << "The Animal j is of type : " << i->getType() << std::endl;
	std::cout << "The Animal i is of type : " << j->getType() << std::endl;
	std::cout << "///////" << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << "///////" << std::endl;
	delete j;
	delete i;
	delete meta;
	std::cout << "///////" << std::endl;
	const WrongAnimal* WrongA = new WrongAnimal();
	const WrongAnimal* WrongC = new WrongCat();
	std::cout << "///////" << std::endl;
	std::cout << "The Animal is of type : " << WrongA->getType() << std::endl;
	std::cout << "The Animal is of type : " << WrongC->getType() << std::endl;
	std::cout << "///////" << std::endl;
	WrongA->makeSound();
	WrongC->makeSound();
	std::cout << "///////" << std::endl;
	delete WrongC;
	delete WrongA;
	std::cout << "///////" << std::endl;
	return 0;
}