/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:49:51 by schuah            #+#    #+#             */
/*   Updated: 2022/08/20 11:32:13 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/* Prints error message and exits */
static void	print_error(std::string error)
{
	std::cerr << error << std::endl;
	exit(1);
}

/* Using a while loop to loop through each line in the file, compares the string
** and replaces it if it is found with the replacement word and outputs into the
** output file <filename>.replace */
static void	replace_text(std::string file_name, std::string find, std::string replace)
{
	std::ifstream 	in_file(file_name);
	std::ofstream	out_file(file_name + ".replace");
	std::string		buf;
	int				stop;

	if (!out_file)
		print_error(file_name + ".replace cannot be created");
	if (!in_file)
	{
		remove((file_name + ".replace").c_str());
		print_error(file_name + " cannot be opened");
	}
	while (1)
	{
		stop = getline(in_file, buf).eof();
		for (int i = 0; i < (int)buf.length(); i++)
		{
			if (buf.compare(i, find.length(), find) == 0)
			{
				out_file << replace;
				i += find.length() - 1;
			}
			else
				out_file << buf[i];
		}
		if (stop)
			break;
		out_file << std::endl;
	}
}

/* Checks for erorr in input */
int	main(int ac, char **av)
{
	std::string		file_name;
	
	if (ac != 4)
		print_error("Invalid number of input");
	if (av[2][0] == '\0')
		print_error("Input find strings are empty");
	file_name = av[1];
	replace_text(file_name, std::string(av[2]), std::string(av[3]));
	return (0);
}
