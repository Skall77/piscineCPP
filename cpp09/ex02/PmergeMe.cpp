/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:47:12 by aaudevar          #+#    #+#             */
/*   Updated: 2023/05/01 11:47:12 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <iomanip>
#include <algorithm>

PmergeMe::PmergeMe(): _size(0)
{
}

PmergeMe::PmergeMe(int argc, char **argv): _size(argc - 1)
{
	this->_deque = _ArgsIntoDeque(argc, argv);
	this->_vector = _ArgsIntoVector(argc, argv);
	_CheckDuplicate();
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	this->_size = obj._size;
	this->_vector = obj._vector;
	this->_deque = obj._deque;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::DisplayBefore()
{
	std::cout << "Before :";

	std::vector<int>::iterator it = _vector.begin();
	std::vector<int>::iterator itend = _vector.end();

	while (it != itend)
	{
		std::cout <<  " " << *it ;
		++it;
	}
	std::cout << std::endl;
}

void PmergeMe::DisplayAfter()
{
	/* MergeInsert vector and calculate time */
	double startVector = _getTime();
	_mergeInsertSortVector(this->_vector);
	double timeVector = _getIntervalTime(startVector);
	/* MergeInsert deque and calculate time */
	double startDeque = _getTime();
	_mergeInsertSortDeque(this->_deque);
	double timeDeque = _getIntervalTime(startDeque);
	std::cout << "After :";

	std::vector<int>::iterator it = _vector.begin();
	std::vector<int>::iterator itend = _vector.end();

	while (it != itend)
	{
		std::cout <<  " " << *it ;
		++it;
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_size << " elements with std::vector : " << std::setprecision(6) << timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_size << " elements with std::deque : " << std::setprecision(6) << timeDeque << " us" << std::endl;
}

std::vector<int> PmergeMe::_ArgsIntoVector(int argc, char **argv)
{
	std::vector<int>	ret;
	for (int i = 1; i < argc; i++)
	{
		std::string s = argv[i];
		for(size_t j = 0; j < s.size(); j++)
		{
			if (!isdigit(s.at(j)))
				throw InvalidArgumentException();
		}
		int n = atoi(s.c_str());
		if (n < 0)
			throw InvalidArgumentException();
		ret.push_back(n);
	}
	return (ret);
}

std::deque<int> PmergeMe::_ArgsIntoDeque(int argc, char **argv)
{
	std::deque<int>	ret;
	for (int i = 1; i < argc; i++)
	{
		std::string s = argv[i];
		for(size_t j = 0; j < s.size(); j++)
		{
			if (!isdigit(s.at(j)))
				throw InvalidArgumentException();
		}
		int n = atoi(s.c_str());
		if (n < 0)
			throw InvalidArgumentException();
		ret.push_back(n);
	}
	return (ret);
}

void PmergeMe::_CheckDuplicate()
{
	std::vector<int>::iterator itr;
    std::vector<int>::iterator itr2;
	for (itr = _vector.begin(); itr != _vector.end(); itr++)
	{
		for (itr2 = itr + 1; itr2 != _vector.end(); itr2++)
			if (*itr2 == *itr)
				throw PmergeMe::DuplicateException();
	}
}

double PmergeMe::_getTime()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec * 0.001));
}

double PmergeMe::_getIntervalTime(long long t)
{
		return (_getTime() - t);
}

void PmergeMe::_mergeInsertSortVector(std::vector<int>& container)
{
	/* Insert sort */
	const int size = container.size();
	if (size < 2)
		return ;
	if (size < 16)
	{
		for (std::vector<int>::iterator i = container.begin(); i != container.end(); i++)
		{
			std::vector<int>::iterator j = i;
			while (j != container.begin() && *(j - 1) > *j)
			{
				std::swap(*j, *(j - 1));
				j--;
			}
		}
		return ;
	}
	std::vector<int>::iterator mid = container.begin() + size / 2;
	std::vector<int> left(container.begin(), mid);
	std::vector<int> right(mid, container.end());
	/* Recursive */
	_mergeInsertSortVector(left);
	_mergeInsertSortVector(right);
	/* Merge everything back */
	std::vector<int>::iterator i = left.begin();
	std::vector<int>::iterator j = right.begin();
	std::vector<int>::iterator k = container.begin();
	while (i != left.end() && j != right.end())
	{
		if (*i < *j)
		{
			*k = *i;
			i++;
		}
		else
		{
			*k = *j;
			j++;
		}
		k++;
	}
	while(i != left.end())
	{
		*k = *i;
		i++;
		k++;
	}
	while(j != right.end())
	{
		*k = *j;
		j++;
		k++;
	}
}

void PmergeMe::_mergeInsertSortDeque(std::deque<int>& container)
{
	/* Insert sort */
	const int size = container.size();
	if (size < 2)
		return ;
	if (size < 16)
	{
		for (std::deque<int>::iterator i = container.begin(); i != container.end(); i++)
		{
			std::deque<int>::iterator j = i;
			while (j != container.begin() && *(j - 1) > *j)
			{
				std::swap(*j, *(j - 1));
				j--;
			}
		}
		return ;
	}
	std::deque<int>::iterator mid = container.begin() + size / 2;
	std::deque<int> left(container.begin(), mid);
	std::deque<int> right(mid, container.end());
	/* Recursive */
	_mergeInsertSortDeque(left);
	_mergeInsertSortDeque(right);
	/* Merge everything back */
	std::deque<int>::iterator i = left.begin();
	std::deque<int>::iterator j = right.begin();
	std::deque<int>::iterator k = container.begin();
	while (i != left.end() && j != right.end())
	{
		if (*i < *j)
		{
			*k = *i;
			i++;
		}
		else
		{
			*k = *j;
			j++;
		}
		k++;
	}
	while(i != left.end())
	{
		*k = *i;
		i++;
		k++;
	}
	while(j != right.end())
	{
		*k = *j;
		j++;
		k++;
	}
}

const char* PmergeMe::InvalidArgumentException::what() const throw()
{
	return ("Error: Invalid arguments");
}

const char* PmergeMe::DuplicateException::what() const throw()
{
	return ("Error: Duplicate in argument");
}

const char* PmergeMe::AlreadySortedException::what() const throw()
{
	return ("Value are already sorted");
}