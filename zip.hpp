#include <iostream>
#include <utility>

//NameSpace for a Tasks
namespace itertools {
    
    template <typename T, typename E> 
    class zip {
    
    private: // private variables and functions
        T iterable_A;
        E iterable_B;

    public:
        zip(T start, E end) :  iterable_A(start), iterable_B(end) {}
        
   auto begin() const{
          return iterator <decltype(iterable_A.begin()),decltype(iterable_B.begin())>(iterable_A.begin(), iterable_B.begin());
        }
        auto end() const{
          return iterator <decltype(iterable_A.end()),decltype(iterable_B.end())>(iterable_A.end(), iterable_B.end());
         }
    template <typename C_1, typename C_2>
        class iterator {

        private:
            C_1 iter_A; // iterator A
            C_2 iter_B; // iterator B

        public:
            iterator(C_1 itA , C_2 itB): iter_A(itA) , iter_B(itB)  {}

           iterator<C_1,C_2>& operator++() {
               ++iter_A;
               ++iter_B;
               return *this;
 
            }


            auto operator*() const
          {
           return pair< decltype(*iter_A),decltype(*iter_B)> (*iter_A,*iter_B);
          }


            bool operator!= (const iterator& other)
          {
            return (iter_A != other.iter_A) && (iter_B != other.iter_B);
           }


         
        }; // END OF CLASS ITERATOR


    };
    template <typename T,typename E>
    std::ostream &operator<<(std::ostream &os, const std::pair<T,E> &c){
    os << c.first << ',' << c.second;

    return os;
}


}