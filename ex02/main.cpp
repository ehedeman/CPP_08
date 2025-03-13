/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:11:14 by ehedeman          #+#    #+#             */
/*   Updated: 2025/03/13 13:49:58 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// int main()
// {
// {
// MutantStack<int> mstack;
// std::cout << std::endl;
// mstack.push(6);
// mstack.push(94);
// mstack.push(8);
// mstack.push(2);
// mstack.push(5);
// mstack.push(53);

// {
// 	MutantStack<int>::iterator it = mstack.begin();
// 	std::cout << *it << std::endl;
// 	it++;
// 	std::cout << *it << std::endl;
// }
// std::cout << std::endl;
// {
// 	MutantStack<int>::iterator it = mstack.end();
// 	std::cout << *it << std::endl;		//0 because last object is NULL equivalent
// 	it--;
// 	std::cout << *it << std::endl;
// }
// std::cout << std::endl;
// }
// {
// MutantStack<std::string> mstack;
// std::cout << std::endl;

// mstack.push("Hello");
// mstack.push(" ");
// mstack.push("How");
// mstack.push(" ");
// mstack.push("Are");
// mstack.push(" ");
// mstack.push("You");
// mstack.push("?");

// MutantStack<std::string>::iterator it;
// {
// 	it = mstack.begin();
// 	while (it != mstack.end())
// 	{
// 		std::cout << *it;
// 		it++;
// 	}
// 	std::cout << std::endl;
// }
// std::cout << std::endl;
// {
// 	it = mstack.end();
// 	while (it != mstack.begin())
// 	{
// 		std::cout << *it;
// 		it--;
// 	}
// 	std::cout << *it;
// 	std::cout << std::endl;
// }
// std::cout << std::endl;
// }
// }


#include <list>
int main()
{
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;	//17 5
	mstack.pop();
	std::cout << mstack.size() << std::endl;//5
	mstack.push(3);							//3 5 
	mstack.push(5);							//5 3 5
	mstack.push(737);						//737 5 3 5
	//[...]
	mstack.push(0);							// top-> 0 737 5 3 5 <-bootom in theory

	std::cout << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "mstack begin: " << *it << std::endl;
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}
std::cout << std::endl;
{
	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl;
	mlist.pop_back();
	std::cout << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	//[...]
	mlist.push_back(0);

	std::cout << std::endl;
	std::list<int>::iterator it = mlist.begin();
	std::cout << "list begin: " << *it << std::endl;
	std::list<int>::iterator ite = mlist.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mlist);
}
return 0;
}