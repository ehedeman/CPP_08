/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:35:16 by ehedeman          #+#    #+#             */
/*   Updated: 2025/03/13 12:47:04 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			//should give 2 and 14 (3 to 17, 9 to 11)
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
/*-----------------------------------------------------------------------------------------*/
		try
		{
			sp.addNumber(15);	//one too much
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
/*-----------------------------------------------------------------------------------------*/
	}
	std::cout << std::endl;
	try
	{
		Span s(10);

		s.fillArray(5, s.getSize());
		unsigned int i = 0;
		while ( i < s.getSize())
		{
			std::cout << s.getNumber(i) << " ";
			i++;
		}
		std::cout << std::endl << i << std::endl;
		i = 0;
		s.fillArray(2, 5);
		while ( i < s.getSize())
		{
			std::cout << s.getNumber(i) << " ";
			i++;
		}
		std::cout << std::endl << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
/*-----------------------------------------------------------------------------------------*/
	std::cout << std::endl;
	{
		Span s(50);
		try
		{
			s.fillArray(2, 45);
			std::cout << s.getNumber(46) << std::endl;	//number larger than amount of items stored currently
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
/*-----------------------------------------------------------------------------------------*/
		try
		{
			s.fillArray(2, 51);	//number larger than overall size
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
/*-----------------------------------------------------------------------------------------*/
	std::cout << std::endl;
	{
		Span s(3);

		s.addNumber(4);
		//s.addNumber(5);	//without line error, with line ok
		try
		{
			std::cout << s.shortestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
/*-----------------------------------------------------------------------------------------*/
		try
		{
			std::cout << s.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	return (0);
}