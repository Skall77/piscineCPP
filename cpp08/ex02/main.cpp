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

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	/*MutantStack tests */
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	std::cout << std::endl;
	mstack.pop();

	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << std::endl;
	/*list tests */

	std::cout << "Now let's do the same test with a container who already have an iterator like std::list" << std::endl;
	std::cout << std::endl;
	std::list<int> l;

	l.push_back(5);
	l.push_back(17);

	std::cout << l.back() << std::endl;
	std::cout << std::endl;
	l.pop_back();

	std::cout << l.size() <<std::endl;
	std::cout << std::endl;
	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	//[...]
	l.push_back(0);

	std::list<int>::iterator itl = l.begin();
	std::list<int>::iterator itel = l.end();

	++itl;
	--itl;

	while (itl != itel)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	std::list<int> li(l);
	std::cout << std::endl;
	std::cout << li.size() << std::endl;
	return 0;
}
