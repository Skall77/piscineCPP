/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:03:14 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/30 16:08:18 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __Harl_H__
#define __Harl_H__

#include <iostream>
#include <string>

class Harl 
{
public:

	Harl();
	~Harl();
	void complain(std::string level);

private:
	
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

};

#endif // __Harl_H__