#include <iostream>
#include <cstring>
#include "ArrayStack.h"

//Default Constructor
template<typename t>
ArrayStack<t> :: ArrayStack(): m_top(0){
    cout << "Calling Default Ctor: ArrayStack"<< endl;
}

//Parameterized Constructor
template<typename t>
ArrayStack<t> :: ArrayStack(size_t count, const t & value){
    cout << "Calling Parameterized Ctor: ArrayStack" << endl;
    size_t i = 0;
    while(i < count){
        m_container[i] = value;
        i++;
        m_top = i;
    }
}

//Copy Construtor
template<typename t>
ArrayStack<t> :: ArrayStack(const ArrayStack<t> & other){
    cout << "Calling Copy Ctor: ArrayStack" << endl;
    size_t i = 0;
    while(i < other.size()){
        m_container[i] = other.m_container[i];
        i++;
    }
    m_top = other.m_top;
}

//Deconstructor
template<typename t>
ArrayStack<t> :: ~ArrayStack(){}

//Assignement Operator
template<typename t>
ArrayStack<t> &ArrayStack<t>:: operator=(const ArrayStack<t> & rhs){
    size_t i = 0;
    while(i < rhs.size()){
        m_container[i] = rhs.m_container[i];
        i++;
    }
    m_top = rhs.m_top;
}

//Insertion Operator
template<typename t>
std::ostream & operator<<(std::ostream & os, const ArrayStack<t> & obj){
    obj.serialize(os);
    return os;
}

//Top functions
template<typename t>
t &ArrayStack<t> :: top(){
    return m_container[m_top];
}

template<typename t>
const t &ArrayStack<t>:: top()const{
    return m_container[m_top];
}

//Push and Pop functions
template<typename t>
void ArrayStack<t> ::  push(const t & value){
    if(m_container.size() < 1000){
        m_container[m_top+1] = value;
        m_top = m_container[m_top+1];
    }
}

template<typename t>
void ArrayStack<t> :: pop(){
    m_top = m_container[m_top-1];
}

// Everything Else im tired
template<typename t>
size_t ArrayStack<t> :: size() const{
    size_t i = 0;
    while(i != m_top){
        i++;
    }
    return i;
}

template<typename t>
bool ArrayStack<t> :: empty() const{
    if(m_top == 0){
        return true;
    }
    else{
        return false;
    }
}

template<typename t>
bool ArrayStack<t> :: full() const{
    if(m_top == 1000){
        return true;
    }
    else{
        return false;
    }
}

template<typename t>
void ArrayStack<t> :: clear(){
    m_top = 0;
    m_container[m_top] = 0;
}

template<typename t>
void ArrayStack<t> :: serialize(std::ostream & os) const{
    size_t i = 0; 
    while(i < size()){
        cout << "#"  << i << " " << m_container[i] << endl;
    }
}