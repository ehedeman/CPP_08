/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:44:05 by ehedeman          #+#    #+#             */
/*   Updated: 2025/02/03 11:37:07 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():_size(10)
{
	this->full = false;
}
Span::Span(unsigned int N):_size(N)
{
	this->full = false;
}
Span::Span(const Span &copy):_size(copy.getSize())
{
	*this = copy;
}
Span::~Span()
{
}

Span	&Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);
	
	std::vector<int>::iterator it = src.getVector().begin();
	this->_size = src.getSize();
	this->full = src.getFull();
	while (it != src.getVector().end())
	{
		this->_vector.push_back(*it);
		it++;
	}
	return *this;
}

unsigned int	Span::getSize()const{return (this->_size);}
int				Span::getNumber(unsigned int index)const
{
	if (index < _vector.size())
		return (this->_vector[index]);
	else
		throw IndexTooLarge();
}
std::vector<int>Span::getVector()const{return (this->_vector);}
bool			Span::getFull()const{return (this->full);}

void			Span::addNumber(int number)
{
	if (this->_vector.size() < this->_size)
		this->_vector.push_back(number);
	else
		throw FullVectorException();
}

int				Span::maxInt(int a, int b)const{return (a >= b ? a : b);}
int				Span::minInt(int a, int b)const{return (a <= b ? a : b);}

void			Span::fillVector(int value, unsigned int amount)
{
	if (amount > this->_size)
		throw AmountLargerThanSize();
	else
	{
		if (!value)
		{
			while (this->_vector.size() < amount)
				_vector.push_back(value);
		}
		else
		{
			while (this->_vector.size() < amount)
				_vector.push_back(value);
		}
	}
}


//finds biggest distance e.g if 0, 2 and 6 are stored, returns 4 (6 - 2)
int				Span::shortestSpan()
{
	std::vector<int>::iterator it_i = _vector.begin();
	std::vector<int>::iterator it_j;
	int	distance = longestSpan();
	
	if (this->_vector.size() >= 2)
	{
		while (it_i != _vector.end())
		{
			it_j = _vector.begin();
			while (it_j != _vector.end())
			{
				if (it_i != it_j)
				{
					if ((maxInt(*it_j, *it_i) - minInt(*it_j, *it_i)) < distance)
						distance = maxInt(*it_j, *it_i) - minInt(*it_j, *it_i);
				}
				it_j++;
			}
			it_i++;
		}
	}
	else
		throw EmptyVectorException();
	return (distance);
}

int				Span::longestSpan()
{
	std::vector<int>::iterator it_i = _vector.begin();
	std::vector<int>::iterator it_j;
	int	distance = 0;
	
	if (this->_vector.size() >= 2)
	{
		while (it_i != _vector.end())
		{
			it_j = _vector.begin();
			while (it_j != _vector.end())
			{
				if (it_i != it_j)
				{
					if ((maxInt(*it_j, *it_i) - minInt(*it_j, *it_i)) > distance)
						distance = maxInt(*it_j, *it_i) - minInt(*it_j, *it_i);
				}
				it_j++;
			}
			it_i++;
		}
	}
	else
		throw EmptyVectorException();
	return (distance);
}

const char* Span::EmptyVectorException::what() const throw()
{
	return "Array does not have enough objects.";
}

const char* Span::FullVectorException::what() const throw()
{
	return "Full Array.";
}

const char* Span::AmountLargerThanSize::what() const throw()
{
	return "Amount is larger than Array Size.";
}

const char* Span::IndexTooLarge::what() const throw()
{
	return "Amount is larger than Array Size.";
}