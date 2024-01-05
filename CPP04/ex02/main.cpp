/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/05/15 11:01:18 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define HORDE 6

int main(void)
{
	// const AAnimal* meta = new AAnimal(); (You can't do that because AAnimal is abstract !)
	AAnimal* animalsHord[HORDE];
	
	for(int i = 0; i < HORDE; i++)
	{
		if (i % 2)
			animalsHord[i] = new Dog();
		else
			animalsHord[i] = new Cat();
	}
	std::cout << "/////////////" << std::endl;
	
	std::cout << "the first animal is a : " << animalsHord[0]->getType() << std::endl;
	std::cout << "the last animal is a  : " << animalsHord[HORDE - 1]->getType() << std::endl;
	Brain *brain;
	brain = &animalsHord[0]->getBrain();
	brain->setIdea("I like mouse", 0);
	brain->setIdea("I like fish", 1);
	brain->setIdea("I don't like dog", 2);
	std::cout << "The first animal think : ";
	std::cout << animalsHord[0]->getBrain().getIdea(0) << " and ";
	std::cout << animalsHord[0]->getBrain().getIdea(1) << " and ";
	std::cout << animalsHord[0]->getBrain().getIdea(2) << std::endl;
	std::cout << "And he say : ";
	animalsHord[0]->makeSound();
	std::cout << "/////////////" << std::endl;
	for (int i = 0; i < HORDE; i++)
		delete animalsHord[i];
	std::cout << std::endl;
	std::cout << "///////////////////////////////////////////////////" << std::endl;
	std::cout << std::endl;
	Dog *dogA = new Dog();
	Dog *dogB = new Dog();
	std::cout << "/////////////" << std::endl;
	dogA->getBrain().setIdea("I'm having a Ruff day", 0);
	dogA->getBrain().setIdea("But i'm trying to keep my Paws-itivity", 1);
	dogA->getBrain().setIdea("Let's be friends fur-ever", 2);
	dogA->getBrain().setIdea("Trust me, i'm a dog-tor", 3);
	std::cout << "Dog A ideas are :" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << dogA->getBrain().getIdea(i) << std::endl;
	std::cout << std::endl;
	Dog *dogC = new Dog(*dogA);
	std::cout << std::endl;
	std::cout << "Dog C, who is a copy of A, ideas are :" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << dogC->getBrain().getIdea(i) << std::endl;
	*dogB = *dogA;
	std::cout << std::endl;
	std::cout << "Dog B, who is a copy by assignement of A, ideas are :" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << dogB->getBrain().getIdea(i) << std::endl;
	std::cout << "/////////////" << std::endl;
	delete dogA;
	std::cout << std::endl;
	std::cout << "Dog B, who is a copy by assignement of destroyed A, ideas are :" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << dogB->getBrain().getIdea(i) << std::endl;
	std::cout << std::endl;
	delete dogB;
	std::cout << std::endl;
	std::cout << "Dog C, who is a copy of destroyed A, ideas are :" << std::endl;
	for (int i = 0; i < 4; i++)
		std::cout << dogC->getBrain().getIdea(i) << std::endl;
	std::cout << std::endl;
	delete dogC;
}
