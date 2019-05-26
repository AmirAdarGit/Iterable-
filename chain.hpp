#pragma once

#include <iterator>
#include<iostream>

//NameSpace for a Tasks
namespace itertools {
    
    template <typename T, typename E> 
    class chain {
    
    private: // private variables and functions
        T iterable_A;
        E iterable_B;

    public:
        chain(T start, E end) :  iterable_A(start), iterable_B(end) {}
        
    auto begin()const{ 
        return  iterator<decltype(iterable_A.begin()),decltype(iterable_B.begin())>(iterable_A.begin(), iterable_B.begin()); }  // iteratable object

    auto end() const{
        return iterator<decltype(iterable_A.end()),decltype(iterable_B.end())>(iterable_A.end(), iterable_B.end()); }  // iteratable object  
 
    template <typename C_1, typename C_2>
        class iterator {

        private:
            C_1 iter_A; // iterator A
            C_2 iter_B; // iterator B
         bool checkKind;

        public:
            iterator(C_1 itA , C_2 itB): iter_A(itA) , iter_B(itB), checkKind(true)  {}

           iterator<C_1,C_2>& operator++() {
                if(checkKind){
                    ++iter_A;
                }else {
                    ++iter_B;
                }
                return *this;
            }


            decltype(*iter_A) operator*() const {

                if(checkKind){
                    return *iter_A;
                }else {
                    return *iter_B;
                }
            }

            bool operator!=(iterator<C_1,C_2>  it){
                if(checkKind && !(iter_A != it.iter_A)){
                    checkKind = false;
                }
                if(checkKind){
                    return iter_A != it.iter_A;
                }else{
                    return iter_B != it.iter_B;
                }
            }

         
        }; // END OF CLASS ITERATOR

	};

}