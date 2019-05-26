#pragma once

#include <utility>
#include <assert.h>
#include <iostream>

//NameSpace for a Tasks
namespace itertools {

    bool flag = false;
    template <typename T, typename E> 
    class product {
    
    private: // private variables and functions
        T iterable_A;
        E iterable_B;

    public:
        product(T start, E end) :  iterable_A(start), iterable_B(end) {
              flag = false;
              if(!(end.begin() != end.end())) 
              flag = true;
            }
        
        
   auto begin() const {
              return iterator<decltype(iterable_A.begin()),decltype(iterable_B.begin())>(iterable_A.begin(), iterable_B.begin());
             }
            auto end() const {
              return iterator<decltype(iterable_A.end()),decltype(iterable_B.end())>(iterable_A.end(), iterable_B.end());
             }
    flaglate <typename C_1, typename C_2>
        class iterator {

        private:
            C_1 iter_A; // iterator A
            C_2 iter_B; // iterator B
            C_2 save_position_B;
              bool sauv_index;

        public:
            iterator(C_1 itA , C_2 itB): iter_A(itA) , iter_B(itB) , save_position_B(iter_B),sauv_index(false) {}

         
              iterator& operator++() {
              if(!sauv_index)
              ++iter_B;
              return *this;
              }

             auto operator*() const
              {
               return pair<decltype(*iter_A),decltype(*iter_B)> (*iter_A,*iter_B);
              }

      
              bool operator!= (iterator const & other)
              {
                if ((iter_A != other.iter_A) && !(iter_B != other.iter_B)){
                    sauv_index = true;
                  }
                if(sauv_index){
                  iter_B = save_position_B;
                  ++iter_A;
                  sauv_index = false;
                }
                return (iter_A != other.iter_A && !flag);
              }


         
        }; // END OF CLASS ITERATOR


    };

}