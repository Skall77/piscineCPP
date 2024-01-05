/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/04/03 15:57:20 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


int main(void)
{
	IMateriaSource* src = new MateriaSource();
	std::cout << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;
	src->learnMateria(new Cure());
	std::cout << std::endl;
	Character* cloud = new Character("Cloud");
	std::cout << std::endl;
	AMateria* tmp;
	tmp = src->createMateria("ice");
	cloud->equip(tmp);
	tmp = src->createMateria("cure");
	std::cout << std::endl;
	cloud->equip(tmp);
	std::cout << std::endl;
	ICharacter* seph = new Character("Sephiroth");
	std::cout << std::endl;
	cloud->use(0, *seph);
	cloud->use(1, *seph);
	std::cout << std::endl;
	ICharacter* clone = new Character(*cloud);
	std::cout << std::endl;
	delete cloud;
	std::cout << std::endl;
	clone->use(0, *seph);
	clone->use(1, *seph);
	std::cout << std::endl;
	delete seph;
	std::cout << std::endl;
	delete clone;
	std::cout << std::endl;
	delete src;
	std::cout << std::endl;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Test: create more than 4 materia in MateriaSource" << std::endl;
	IMateriaSource* src1 = new MateriaSource();
	std::cout << std::endl;
	src1->learnMateria(new Ice());
	src1->learnMateria(new Ice());
	src1->learnMateria(new Cure());
	src1->learnMateria(new Cure());
	src1->learnMateria(new Ice());

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Test: try to equip false materia" << std::endl;
	AMateria* tmp1;
	ICharacter *tifa = new Character("Tifa");
	tmp1 = src1->createMateria("ice");
	tifa->equip(tmp1);
	tmp1 = src1->createMateria("cure");
	tifa->equip(tmp1);
	tmp1 = src1->createMateria("bolt");
	tifa->equip(tmp1);
	delete src1;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Test: try to equip more than 4 materia, and usage of unequip()" << std::endl;

	AMateria *cure = new Cure();
	AMateria *ice = new Ice();
	tifa->equip(cure);
	tifa->equip(cure);
	tifa->equip(ice);
	tifa->unequip(4);
	tifa->unequip(2);
	tifa->unequip(2);
	delete cure;

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Test: use materia" << std::endl;
	ICharacter* cid = new Character("Cid");
	tifa->use(0, *cid);
	tifa->use(1, *cid);
	tifa->use(2, *cid);
	tifa->use(3, *cid);
	tifa->use(4, *cid);
	delete tifa;
	delete cid;
	return 0;
}
