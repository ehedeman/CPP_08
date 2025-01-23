/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:05:46 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/23 13:42:47 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <queue>
#include <vector>


int main()
{
	std::deque<int> _deque;
	std::vector<int> _vector;
	int index;

	_deque.push_front(1);		//index 7 because push.front
	_deque.push_front(0);		//index 6
	_deque.push_front(9);		//index 5
	_deque.push_front(5);		//index 4
	_deque.push_front(2);		//index 3
	_deque.push_front(6);		//index 2
	_deque.push_front(4);		//index 1
	_deque.push_front(7);		//index 0

	_vector.push_back(1);		//index 0 because push.back
	_vector.push_back(0);		//index 1
	_vector.push_back(9);		//index 2
	_vector.push_back(5);		//index 3
	_vector.push_back(2);		//index 4
	_vector.push_back(6);		//index 5
	_vector.push_back(4);		//index 6
	_vector.push_back(7);		//index 7
	
	std::cout << std::endl << "Deque correct case: " << std::endl;
	try
	{
		std::deque<int>::iterator i = easyfind(_deque, 9);
		index = i - _deque.begin();
		std::cout << "Object found at index: " << index << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "Deque false case: " << std::endl;
	try
	{
		std::deque<int>::iterator i = easyfind(_deque, 21);
		index = i - _deque.begin();
		std::cout << "Object found at index: " << index << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "Vector corrcet case: " << std::endl;
	try
	{
		std::vector<int>::iterator i = easyfind(_vector, 9);
		index = i - _vector.begin();
		std::cout << "Object found at index: " << index << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl << "Vector false case: " << std::endl;
	try
	{
		std::vector<int>::iterator i = easyfind(_vector, 21);
		index = i - _vector.begin();
		std::cout << "Object found at index: " << index << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}