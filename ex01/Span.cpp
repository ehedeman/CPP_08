/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:44:05 by ehedeman          #+#    #+#             */
/*   Updated: 2025/01/23 15:11:02 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():size(10)
{
	this->array = new int[size];
	this->full = false;
}
Span::Span(unsigned int N):size(N)
{
	this->array = new int[size];
	this->full = false;
}
Span::Span(const Span &copy):size(copy.getSize())
{
	this->array = new int[size];
	this->full = copy.getFull();
	for (unsigned int i = 0; i < size; i++)
		this->array[i] = copy.getNumber(i);
}
Span::~Span()
{
	delete[](array);
}


unsigned int	Span::getSize()const{return (this->size);}
int				Span::getNumber(int index)const{return (this->array[index]);}
int				*Span::getArray()const{return (this->array);}
bool			Span::getFull()const{return (this->full);}

unsigned int	Span::getAmountNumbers()const
{
	unsigned int count = 0;

	for (unsigned int i = 0; i < this->size; i++)
	{
		if (this->array[i])
			count++;
	}
	return (count);
}

void			Span::addNumber(int number)
{
	int i = 0;

	if (this->getAmountNumbers() != this->size)
	{
		while (this->array[i])
			i++;
		this->array[i] = number;
	}
	else
		throw FullArrayException();
}

int				Span::maxInt(int a, int b)const{return (a >= b ? a : b);}
int				Span::minInt(int a, int b)const{return (a <= b ? a : b);}

void			Span::fillArray(int value, unsigned int amount)
{
	if (amount > this->size)
		throw AmountLargerThanSize();
	else
	{
		if (!value)
		{
			for (unsigned int i = 0; i < amount; i++)
			{
				if (!this->array[i])
					this->array[i] = value++;
			}
		}
		else
		{
			for (unsigned int i = 0; i < amount; i++)
			{
				if (!this->array[i])
					this->array[i] = value;
			}
		}
	}
}


//finds biggest distance e.g if 0, 2 and 6 are stored, returns 4 (6 - 2)
int				Span::shortestSpan()
{
	int	distance = longestSpan();

	if (this->getAmountNumbers() >= 2)
	{
		for (unsigned int i = 0; i < this->size; i++)
		{
			for (unsigned int j = 0; j < this->size; j++)
			{
				if (i != j && this->array[i] && this->array[j])
				{
					if ((maxInt(this->array[j], this->array[i]) - minInt(this->array[j], this->array[i])) < distance)
						distance = maxInt(this->array[j], this->array[i]) - minInt(this->array[j], this->array[i]);
				}
			}
		}
	}
	else
		throw EmptyArrayException();
	return (distance);
}

int				Span::longestSpan()
{
	int	distance = 0;
	
	if (this->getAmountNumbers() >= 2)
	{
		for (unsigned int i = 0; i < this->size; i++)
		{
			for (unsigned int j = 0; j < this->size; j++)
			{
				if (this->array[i] && this->array[j])
				{
					if ((maxInt(this->array[j], this->array[i]) - minInt(this->array[j], this->array[i])) > distance)
						distance = maxInt(this->array[j], this->array[i]) - minInt(this->array[j], this->array[i]);
				}
			}
		}
	}
	else
		throw EmptyArrayException();
	return (distance);
}

const char* Span::EmptyArrayException::what() const throw()
{
	return "Array does not have enough objects.";
}

const char* Span::FullArrayException::what() const throw()
{
	return "Full Array.";
}

const char* Span::AmountLargerThanSize::what() const throw()
{
	return "Amount is larger than array size.";
}