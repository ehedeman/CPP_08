/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:51:41 by ehedeman          #+#    #+#             */
/*   Updated: 2025/03/13 14:14:26 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


template <typename T> MutantStack<T>::MutantStack(void)
{
	std::cout <<	"Default constructor called."	<<std::endl;
}
template <typename T> MutantStack<T>::MutantStack(const MutantStack &copy): stack(copy)
{
	std::cout <<	"Copy constructor called."		<<std::endl;
}
template <typename T> MutantStack<T>::~MutantStack()
{
	std::cout <<	"Destructor called."			<<std::endl;
}
template <typename T> MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &copy)
{
	if(*this != copy)
		*this = copy;
	return(*this);
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}