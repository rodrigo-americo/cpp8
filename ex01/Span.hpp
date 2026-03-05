#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <climits>
#include <algorithm>

class Span {
    private:
        unsigned int    _maxSize;
        std::vector<int> _numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void    addNumber(int n);
        int     shortestSpan();
        int     longestSpan();
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
    		if (_numbers.size() + std::distance(begin, end) > _maxSize)
        		throw std::runtime_error("Range excede o limite");
    		_numbers.insert(_numbers.end(), begin, end);
		}
};

#endif
