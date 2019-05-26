#pragma once

#include <iterator>
#include<iostream>

namespace itertools
{
template <class T>
class range
{

    T a; // _aing point
    T b;   // stopping point.
   
    class iterator
    {

    public:
        T value;

        //constructor
        iterator(T v) : value(v){}

        // operators
        bool operator!=(range::iterator const &other) const
        { 
            return value != (other.value);
        }

    bool operator== (range::iterator const &other) const
    {
       return value == other.value;

     }
        const T operator*() const
        {
            return value;
        }

        iterator &operator++()
        {

            ++value;
            return *this;
        }

    };

public:

    range(T from, T to) : a(from), b(to) {}  




		iterator begin() const {
			return iterator(a);
		}

		iterator end() const {
			return iterator(b);
		} 
}; // class



} // namespace itertools