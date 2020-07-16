#pragma once
#include <iostream>
#include <cstring>
using namespace std;

const size_t ARRAY_MAX= 1000;
template <typename t> class ArrayStack;
template <typename t> std::ostream & operator<<(std::ostream &os, const ArrayStack<t> & obj);

template<typename t>
class ArrayStack{
    friend std::ostream & operator<< <>(std::ostream & os, const ArrayStack<t> & obj);

    public:
        ArrayStack(): m_top(0){
            cout << "Calling Default Ctor: ArrayStack"<< endl; 
        }
        ArrayStack(size_t count, const t & value){
            cout << "Calling Parameterized Ctor: ArrayStack" << endl;
            size_t i = 0;
            while(i < count){
                m_container[i] = value;
                i++;
                m_top = i;
            }
        }
        ArrayStack(const ArrayStack<t> & other){
            cout << "Calling Copy Ctor: ArrayStack" << endl;
            size_t i = 0;
            while(i < other.size()){
                m_container[i] = other.m_container[i];
                i++;
            }
            m_top = other.m_top;
        }
        ~ArrayStack(){}


        ArrayStack<t> & operator= (const ArrayStack<t> & rhs){
            size_t i = 0;
            while(i < rhs.size()){
                m_container[i] = rhs.m_container[i];
                i++;
            }
            m_top = rhs.m_top;
        }


        t & top(){
            return m_container[m_top];
        }
        const t & top() const{
            return m_container[m_top];
        }


        void push(const t & value){
            size_t i = 1000;
            if(size()< i){
                m_container[m_top+1] = value;
                m_top = m_container[m_top+1];
            }
        }
        void pop(){
            m_top = m_container[m_top-1];
        }
        size_t size() const{
            size_t i = 0;
            while(i != m_top){
                i++;
            }
            return i;
        }

        bool empty() const{
            if(m_top == 0){
                return true;
            }
            else{
                return false;
            }
        }
        bool full() const{
            if(m_top == 1000){
                return true;
            }
            else{
                return false;
            }
        }
        void clear(){
            m_top = 0;
            m_container[m_top] = 0;
        }
        void serialize(std::ostream & os) const{
            size_t i = 0; 
            while(i < size()){
                cout << "#"  << i << " " << m_container[i] << endl;
                i++;
            }
        }

    private:
        t m_container[ARRAY_MAX];
        size_t m_top;
};

template<typename t>
std::ostream & operator<<(std::ostream & os, const ArrayStack<t> & obj){
    obj.serialize(os);
    return os;
}



