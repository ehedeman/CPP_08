/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:35:16 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/23 15:12:33 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.addNumber(15);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Span s = Span(10000);
	
		s.fillArray(0, s.getSize());
		unsigned int i = 0;
		// while ( i < s.getSize())
		// {
		// 	std::cout << s.getNumber(i) << std::endl;
		// 	i++;
		// }
		// std::cout << i << std::endl;
		// i = 0;
		s.fillArray(2, s.getSize());
		while ( i < s.getSize())
		{
			std::cout << s.getNumber(i) << std::endl;
			i++;
		}
		// std::cout << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}