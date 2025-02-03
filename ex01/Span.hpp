/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:43:50 by ehedeman          #+#    #+#             */
/*   Updated: 2025/02/03 11:33:00 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
	unsigned int		_size;
	std::vector<int>	_vector;
	bool				full;
public:
	Span();
	Span(unsigned int N);
	Span(const Span &copy);
	~Span();
	Span	&operator=(const Span &src);

	unsigned int		getSize()const;
	int					getNumber(unsigned int index)const;
	std::vector<int>	getVector()const;
	bool				getFull()const;

	void				addNumber(int number);
	int					shortestSpan();			//finds biggest distance e.g if 0, 2 and 6 are stored, returns 4 (6 - 2)
	int					longestSpan();
	
	void				fillVector(int value, unsigned int amount);
	int					maxInt(int a, int b)const;
	int					minInt(int a, int b)const;

	class EmptyVectorException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class FullVectorException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class AmountLargerThanSize : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class IndexTooLarge : public std::exception
	{
	public:
		const char* what() const throw();
	};
};
