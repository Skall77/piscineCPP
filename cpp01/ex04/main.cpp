/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/30 15:44:05 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int error_handler(int exit_code, std::string error_msg);

int main(int argc, char *argv[])
{
	std::ifstream file;
	std::ofstream new_file;
	std::string str;
	char c;
	int index;
	
	if (argc != 4)
		return (error_handler(1,"Wrong numbers of arguments. Usage : ./replace <filename> <s1> <s2>"));
	file.open(argv[1]);
	if (!file)
		return (error_handler(1,"Error, can't open file."));
	while(!file.eof() && file >> std::noskipws >> c)
		str += c;
	file.close();
	new_file.open((std::string(argv[1]) + ".replace"));
	if(!new_file)
		return (error_handler(1,"Fatal error, can't open the file.replace."));
	for (int i = 0; i < str.size(); i++)
	{
		index = str.find(argv[2], i);
		if (index != std::string::npos && index == i)
		{
			new_file << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			new_file << str[i];
	}
	new_file.close();
	return (0);
}

int error_handler(int exit_code, std::string error_msg)
{
	std::cout << error_msg << std::endl;
	return (exit_code);
}
