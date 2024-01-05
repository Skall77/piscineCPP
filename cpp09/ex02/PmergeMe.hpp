/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:47:07 by aaudevar          #+#    #+#             */
/*   Updated: 2023/05/01 11:47:07 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& copy);
		PmergeMe& operator=(const PmergeMe& obj);

		~PmergeMe();

		void DisplayBefore();
		void DisplayAfter();

		class InvalidArgumentException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };

		class DuplicateException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };

		class AlreadySortedException : public std::exception {
            public:
                virtual const char* what() const throw();  
        };

	private:
			int					_size;
			std::deque<int>		_deque;
			std::vector<int>	_vector;

			std::vector<int>	_ArgsIntoVector(int argc, char **argv);
			std::deque<int>		_ArgsIntoDeque(int argc, char **argv);
			void				_CheckDuplicate();
			double				_getTime();
			double				_getIntervalTime(long long t);
			void				_mergeInsertSortVector(std::vector<int>& container);
			void				_mergeInsertSortDeque(std::deque<int>& container);
		

};

#endif