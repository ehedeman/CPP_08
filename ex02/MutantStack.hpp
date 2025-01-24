/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:19:38 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/24 16:02:05 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iterator>
#include <stack>

template<typename T>class MutantStack : public std::stack
{
private:
	/* data */
public:
				MutantStack(void);
				MutantStack();
				MutantStack(const MutantStack &copy);
				~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator	find(iterator begin, iterator end, T value); //??

	iterator	begin();
	iterator	end();
	
	const_iterator	begin()const;
	const_iterator	end()const;
	
	reverse_iterator	begin();
	reverse_iterator	end();
	
	const_reverse_iterator	begin()const;
	const_reverse_iterator	end()const;
};

template<typename T>MutantStack<T>::MutantStack(void)
{
}

template<typename T>MutantStack<T>::MutantStack(void)
{
}

template<typename T>MutantStack<T>::MutantStack(const MutantStack &copy)
{
}

template<typename T>MutantStack<T>::~MutantStack(/* args */)
{
}
