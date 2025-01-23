/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:43:50 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/23 15:05:13 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

class Span
{
private:
	const unsigned int	size;
	int					*array;
	bool				full;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	~Span();
	

	unsigned int	getSize()const;
	int				getNumber(int index)const;
	int				*getArray()const;
	bool			getFull()const;
	unsigned int	getAmountNumbers()const;

	void			addNumber(int number);
	int				shortestSpan();			//finds biggest distance e.g if 0, 2 and 6 are stored, returns 4 (6 - 2)
	int				longestSpan();
	
	void			fillArray(int value, unsigned int amount);
	int				maxInt(int a, int b)const;
	int				minInt(int a, int b)const;

	class EmptyArrayException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class FullArrayException : public std::exception
	{
	public:
		const char* what() const throw();
	};
		class AmountLargerThanSize : public std::exception
	{
	public:
		const char* what() const throw();
	};
};
