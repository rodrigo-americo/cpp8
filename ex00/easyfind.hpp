#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &a, int target)
{
    typename T::iterator result;

    result = std::find(a.begin(), a.end(), target);
    if (result == a.end())
        throw std::runtime_error("element not found");
    return result;
}

#endif
