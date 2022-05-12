#ifndef DATABASE_HPP_INCLUDED
#define DATABASE_HPP_INCLUDED

#include <iostream>
#include "sports_club.h"
#include "data_handle.hpp"

/**
 Funktor used in print/countWithCondition(...) to compare the given 'constant' date and the date(est) of each element in the Database
 */
class DateFunktor{
    Date d;

public:
    DateFunktor(const Date& d): d(d) {}

    bool operator() (SportsClub* s_ref){
        return s_ref->getEst() == d;
    }
};

/**
 * Database class
 * The heterogeneous collection of the program
 * Stores SportsClub pointers
 * The container has no fixed size, it is dynamic
 */

class Database{
    SportsClub** arr;
    size_t siz;

public:
    /**constructor*/
    Database(): arr(NULL), siz(0) {}

    /**copy constructor*/
    Database(const Database& rhs){
        siz = rhs.siz;

        arr = new SportsClub*[siz];

        for(size_t i = 0; i < siz; i++){
            arr[i] = rhs.arr[i]->clone();
        }
    }

    /**deletes the database / frees up allocated memory*/
    void cleanDatabase(){
        ///deletes the member pointers
        for(size_t i = 0; i < siz; i++){
            delete arr[i];
        }

        delete[] arr;
        siz = 0;
    }

    /**operator= overload, because the container is dynamic*/
    Database& operator=(const Database& rhs){
        if(&rhs != this){
            cleanDatabase();

            siz = rhs.siz;
            arr = new SportsClub*[siz];

            for(size_t i = 0; i < siz; i++){
                arr[i] = rhs.arr[i]->clone();
            }
        }
        return *this;
    }

    /**pre-dec*/
    class iterator;

    iterator begin() {
        return iterator(*this);
    }

    iterator end(){
        return iterator(*this, siz);
    }

    /**iterator class*/
    class iterator {
        Database *obj;	///given obj
		size_t idx;	///actual index
    public:

        /// def ctr
        iterator() :obj(0), idx(0) {}

        /// given obj with given element
        /// @param a - obj
        /// @param ix - value of idx
        iterator(Database& a, size_t ix = 0)
            : obj(&a),
            idx(ix) {}

        /// pre-increment
        iterator& operator++() {
            if (idx != obj->siz) ++idx;
            return *this;
        }

        /// post-increment
        iterator operator++(int){
            iterator tmp = *this;
            operator++();
            return tmp;
        }
        /// != operator
        /// @param i - rhs
        bool operator!=(const iterator &i) const {
            return(idx != i.idx);
        }

        /// == operator
        /// @param i - rhs
		bool operator==(const iterator &i) const {
            return !operator!=(i);
        }

        SportsClub*& operator*() const {
            if (idx != obj->siz) return obj->arr[idx];
            else throw std::runtime_error("Indirection fault");
        }

        SportsClub* operator->() const {
            return operator*();
        }

    };  ///end of iterator class

    size_t size() const { return siz; }

    void printDataBase(std::ostream& os, iterator first, iterator last){
        while(first != last){
            (*first)->print(os);
            ++first;

            std::cout << std::endl;
        }
    }

    /**file handling*/
    void printToFile(std::ostream& os) const {
        for(size_t i = 0; i < siz; i++){
            arr[i]->save(os);
            if(i != siz - 1){
                os << std::endl;
            }
        }
    }
    void readFromFile(std::istream& is){
        DataHandle handle;
        handle.proto_add(new Football(), "Football");
        handle.proto_add(new Basketball(), "Basketball");
        handle.proto_add(new Handball(), "Handball");

        while(!is.eof()){
            SportsClub* new_add = handle.readFrom(is);
            addElement(new_add);
        }
    }

    /**prints elements of the database if they meet the given condition*/
    /**@param F func - A functor that has a data field of the base of the comparison. () operator is overloaded of given functor */
    template<typename F>
    void printWithCondition(std::ostream& os, iterator first, iterator last, F func) const{

        std::cout << "The following teams meet the condition: " << std::endl;

        while(first != last){
            if(func(*first)){
                (*first)->print(os);
                std::cout << std::endl;
            }
            ++first;
        }
    }

    /**counts the number of elements that meet the given condition*/
    /**@param F func - The condition mentioned above. Same type of functor as described above in the previous function 'printWithCondition'*/
    template<typename F>
    int countWithCondition(iterator first, iterator last, F func) const{
        int c = 0;

        while(first != last){
            if(func(*first)){
                c++;
            }
            ++first;
        }

        return c;
    }

    /**adds a new element to the end of the array*/
    /**@param SportsClub* new_element - the new element*/
    void addElement(SportsClub* new_element){
        SportsClub** new_arr = new SportsClub*[siz + 1];

        for(size_t i = 0; i < siz; i++){
            new_arr[i] = arr[i];
        }

        delete[] arr;

        new_arr[siz] = new_element;

        arr = new_arr;
        siz += 1;
    }

    /**deletes an element at the given index*/
    /**changes the size of the array */
    void deleteElement(size_t idx){
        if(idx >= siz) throw std::out_of_range("Index was out of range");

        SportsClub** new_arr = new SportsClub*[siz - 1];

        size_t new_siz = 0;

        for(size_t i = 0; i < siz; i++){
            if(i == idx){
                i++;
            }
            new_arr[new_siz++] = arr[i];
        }

        delete arr[idx];
        delete[] arr;

        arr = new_arr;
        siz -= 1;
    }

    /**calls cleanDatabase() function which deals with memory leak*/
    ~Database() { cleanDatabase(); }
};

#endif // DATABASE_HPP_INCLUDED
