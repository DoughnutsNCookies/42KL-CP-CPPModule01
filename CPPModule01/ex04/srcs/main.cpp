/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:49:51 by schuah            #+#    #+#             */
/*   Updated: 2022/09/14 19:13:41 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/* Prints error message and exits */
static int	print_error(std::string error)
{
	std::cerr << error << std::endl;
	return (1);
}

/* Using a while loop to loop through each line in the file, using find to get
** the pos of the found string, erasing the found word and inserts the replace
** word then it is output into <filename>.replace */
static int	replace_text(std::string file_name, std::string find, std::string replace)
{
	std::ifstream 			in_file(file_name);
	std::ofstream			out_file(file_name + ".replace");
	std::string				buf;
	std::string::size_type	pos;
	std::string::size_type	start_pos;
	int						stop;

	if (!out_file)
		return (print_error(file_name + ".replace cannot be created"));
	if (!in_file)
	{
		remove((file_name + ".replace").c_str());
		return (print_error(file_name + " cannot be opened"));
	}
	while (1)
	{
		start_pos = 0;
		stop = getline(in_file, buf).eof();
		pos = buf.find(find, start_pos);
		while (pos != std::string::npos)
		{
			buf.erase(pos, find.length());
			buf.insert(pos, replace);
			start_pos = pos + replace.length();
			pos = buf.find(find, start_pos);
		}
		out_file << buf;
		if (stop)
			break;
		out_file << std::endl;
	}
	return (0);
}

/* Checks for erorr in input */
int	main(int ac, char **av)
{
	std::string		file_name;
	
	if (ac != 4)
		return (print_error("Invalid number of input"));
	if (av[2][0] == '\0')
		return (print_error("Input find strings are empty"));
	file_name = av[1];
	return (replace_text(file_name, std::string(av[2]), std::string(av[3])));
}
