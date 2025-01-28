/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:11:14 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/28 13:29:09 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
{
MutantStack<int> mstack;
std::cout << std::endl;
mstack.push(6);
mstack.push(94);
mstack.push(8);
mstack.push(2);
mstack.push(5);
mstack.push(53);

{
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;
}
std::cout << std::endl;
{
	MutantStack<int>::iterator it = mstack.end();
	std::cout << *it << std::endl;		//0 because last object is NULL equivalent
	it--;
	std::cout << *it << std::endl;
}
std::cout << std::endl;
}
{
MutantStack<std::string> mstack;
std::cout << std::endl;

mstack.push("Hello");
mstack.push(" ");
mstack.push("How");
mstack.push(" ");
mstack.push("Are");
mstack.push(" ");
mstack.push("You");
mstack.push("?");

MutantStack<std::string>::iterator it;
{
	it = mstack.begin();
	while (it != mstack.end())
	{
		std::cout << *it;
		it++;
	}
	std::cout << std::endl;
}
std::cout << std::endl;
{
	it = mstack.end();
	while (it != mstack.begin())
	{
		std::cout << *it;
		it--;
	}
	std::cout << *it;
	std::cout << std::endl;
}
std::cout << std::endl;
}
}