/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schuah <schuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 10:53:29 by schuah            #+#    #+#             */
/*   Updated: 2022/08/19 12:46:26 by schuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

/* Sample main function to show how the classes work */
int	main(void)
{
	Zombie fooZombie;
	Zombie	*zombie;

	fooZombie.set_name("Foo");
	fooZombie.announce();
	zombie = newZombie("New Zombo");
	zombie->announce();
	randomChump("Random");
	delete zombie;
	return (0);
}
