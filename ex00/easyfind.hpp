/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:09:19 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/23 13:16:57 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <exception>
#include <iterator>

class ValueNotFoundException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Object not found.";
    }
};


template <typename T> 
typename T::iterator easyfind(T &x, int y)
{
	typename T::iterator i = std::find(x.begin(), x.end(), y);
	if (i == x.end())
		throw ValueNotFoundException();
	else
	{
		std::cout << "Object was found." << std::endl;
		return (i);
	}
}
