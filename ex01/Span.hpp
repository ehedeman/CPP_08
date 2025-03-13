/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:43:50 by ehedeman          #+#    #+#             */
/*   Updated: 2025/03/13 12:21:56 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
	const unsigned int	size;
	std::vector<int>	array;
	bool				full;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	~Span();
	

	unsigned int		getSize()const;
	int					getNumber(int index);
	std::vector<int>	&getArray();
	unsigned int		getAmountNumbers();

	void				addNumber(int number);
	int					shortestSpan();			//finds biggest distance e.g if 0, 2 and 6 are stored, returns 4 (6 - 2)
	int					longestSpan();
	
	void				fillArray(int value, unsigned int amount);
	int					maxInt(int a, int b)const;
	int					minInt(int a, int b)const;

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
	class IndexLargerThanSize : public std::exception
	{
	public:
		const char* what() const throw();
	};
};
