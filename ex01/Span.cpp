/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehedeman <ehedeman@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:44:05 by ehedeman          #+#    #+#             */
/*   Updated: 2025/03/13 12:53:00 by ehedeman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*------------------------------De/-Constructors------------------------------*/
Span::Span():size(10)
{
}
Span::Span(unsigned int N):size(N)
{
}
Span::Span(const Span &copy):size(copy.getSize())
{
	Span src = copy;
	for (size_t i = 0; i < src.getArray().size(); i++)
		this->array.push_back(src.getNumber(i));
}
Span::~Span()
{
}

/*----------------------------------Accessors---------------------------------*/

unsigned int		Span::getSize()const{return (this->size);}
int					Span::getNumber(int index)
{
	if (index >= (int)array.size())
		throw IndexLargerThanSize();
	return (this->array[index]);
}
std::vector<int>	&Span::getArray(){return (this->array);}

unsigned int		Span::getAmountNumbers()
{
	unsigned int count = 0;
	std::vector<int>::iterator it = this->array.begin();
	while (it != array.end())
	{	
		it++;
		count++;
	}
	return (count);
}
/*------------------------------Member Functions------------------------------*/

void			Span::addNumber(int number)
{
	if (this->getAmountNumbers() != this->size)
		this->array.push_back(number);
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
		unsigned int i = this->getAmountNumbers();
		while (i < amount && array.size() <= this->size)
		{
			array.push_back(0);
			i++;	
		}
		std::vector<int>::iterator it = array.begin() + amount;
		std::fill(array.begin(), it, value);
	}
}


//finds biggest distance e.g if 0, 2 and 6 are stored, returns 4 (6 - 2)
int				Span::shortestSpan()
{
	int	distance = longestSpan();

	if (this->getAmountNumbers() >= 2)
	{
		for (size_t i= 0; i < this->array.size(); i++)
		{
			for (size_t j = 0; j < this->array.size(); j++)
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
		for (unsigned int i = 0; i < this->array.size(); i++)
		{
			for (unsigned int j = 0; j < this->array.size(); j++)
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

/*------------------------------Custom Exceptions-----------------------------*/

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

const char* Span::IndexLargerThanSize::what() const throw()
{
	return "No item stored at Index.";
}