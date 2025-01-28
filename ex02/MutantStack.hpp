/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:19:38 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/28 13:16:24 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iterator>
#include <stack>

template<class T>class MutantStack : public std::stack<T>
{
private:
	/* data */
public:
	typedef std::stack<T> stack;
	typedef typename stack::container_type container;
	typedef typename container::iterator iterator;
	
	MutantStack(void)
	{
		std::cout <<	"Default constructor called."	<<std::endl;
	}
	MutantStack(const MutantStack &copy): stack(copy)
	{
		std::cout <<	"Copy constructor called."		<<std::endl;
	}
	~MutantStack()
	{
		std::cout <<	"Destructor called."			<<std::endl;
	}
	stack	&operator=(const MutantStack &copy)
	{
		if(*this != copy)
			*this = copy;
		return(*this);
	}
	iterator begin()
	{
		return (stack::c.begin());
	}
	iterator end()
	{
		return(stack::c.end());
	}
};
