#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int n)
{
	_maxSize = n;
}
Span::Span(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;	
	}
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}
Span::~Span(){}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
	{
		throw std::runtime_error("Já esta cheio");
	}
	_numbers.push_back(n);
}

int Span::shortestSpan()
{
	if (_numbers.size() <= 1)
	{
		throw std::runtime_error("O sapn tem poucos elementos");
	}
	int result = INT_MAX;
	std::sort(_numbers.begin(), _numbers.end());
	for (size_t i = 0; i < _numbers.size() - 1; i++)
	{
		if (_numbers[i + 1] - _numbers[i] < result)
		{
			result = _numbers[i + 1] - _numbers[i];
		}
	}
	return (result);
}

int Span::longestSpan()
{
	if (_numbers.size() <= 1)
	{
		throw std::runtime_error("O sapn tem poucos elementos");
	}
	std::sort(_numbers.begin(), _numbers.end());
	return (_numbers.back() - _numbers.front());
}
