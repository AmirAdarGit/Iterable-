#pragma once

#include <iterator>
#include <iostream>

using namespace std;

namespace itertools{

  template <typename first_container,typename second_container>
  class chain{

  first_container A1; // iterator for first type
  second_container A2; // iterator for second type

  public:

    chain(first_container a,second_container b) : A1(a),A2(b){}


    template<typename E1,typename E2>
    class iterator{
    public :

    E1 A; // first iterator
    E2 B; // second iterator

    int position; // 0 for the first range and 1 for the second

    iterator(E1 val1,E2 val2) : A(val1),B(val2),position(0){}

    iterator& operator++() // advaced value
    {
        if(position == 0)
          ++A;
        else
          ++B;
        return *this;
    }

        auto operator*() const
     {
             if(position == 0)
                 return *A;
             else
                 return *B;
    }

    bool operator!= (const iterator& temp)
    {
      if (position == 0 && (*A == *(temp.A))) // continue to the next range
           position = 1;
      if(position == 0)
      return A != temp.A;
      else
      return B != temp.B;
     }

    };

    auto begin() const{
       return iterator<decltype(A1.begin()),decltype(A2.begin())>(A1.begin(), A2.begin()); // iteratable object
    }
    auto end() const{
       return iterator<decltype(A1.end()),decltype(A2.end())>(A1.end(), A2.end()); // iteratable object
    }

  };
};