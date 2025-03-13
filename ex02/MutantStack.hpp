/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:19:38 by ehedeman          #+#    #+#             */
/*   Updated: 2025/03/13 14:14:07 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iterator>
#include <stack>

template<typename T> class MutantStack : public std::stack<T>
{
private:
	/* data */
public:
	typedef std::stack<T> stack;
	typedef typename stack::container_type container;	//underlying container where values are stored
	typedef typename container::iterator iterator;
	
	MutantStack();
	MutantStack(const MutantStack &copy);
	~MutantStack();
	MutantStack &operator=(const MutantStack &src);
	
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"