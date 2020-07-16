#include <iostream>
#include <cstring>
#include "NodeStack.h"
using namespace std;

//Default Constructor
template<typename t>
NodeStack<t> :: NodeStack(): m_top(NULL), m_bot(NULL){
    cout << "Calling Default Ctor: NodeStack" << endl;
}

//Parameterized Constructor
template<typename t>
NodeStack<t> :: NodeStack(size_t size, const t & value){
    cout << "Calling Parameterized Ctor: NodeStack" << endl;
    size_t i = 0;
    m_top = NULL;
    while(i < size){
        push(value);
        i++;
    }
}

//Copy Constructor
template<typename t>
NodeStack<t> :: NodeStack(const NodeStack<t> & other){
    cout << "Calling Copy Ctor: NodeStack" << endl;
    m_top = new Node<t>(other.m_top -> data(), NULL);
    Node<t> *otherCpy = other.m_top;
    Node<t> *newCpy = m_top;
    while(otherCpy != NULL){
        newCpy ->m_next = new Node<t>(otherCpy -> data(), NULL);
        newCpy = newCpy ->m_next;
        otherCpy = otherCpy.m_next;
    }
}

//Deconstructor
template<typename t>
NodeStack<t> :: ~NodeStack<t>(){
    cout << "Calling Deconstructor: NodeStack" << endl;
    clear();
}

//Assignment Operator
template<typename t>
NodeStack<t> &NodeStack<t> :: operator=(const NodeStack<t> & rhs){
    m_top = new Node<t>(rhs.m_top -> data(), NULL);
    Node<t> *otherCpy = rhs.m_top;
    Node<t> *newCpy = m_top;
    while(otherCpy != NULL){
        newCpy ->m_next = new Node<t>(otherCpy -> data(), NULL);
        newCpy = newCpy ->m_next;
        otherCpy = otherCpy.m_next;
    }
}

//Insertion Operator
template<typename t>
std :: ostream & operator<<(std::ostream &os, const NodeStack<t> &obj){
    obj.serialize(os);
    return os;
}

//Top functions
template<typename t>
t &NodeStack<t> :: top(){
    if(m_top != NULL){
        return m_top;
    }
    else{
        return NULL; // May not like
    }
}

template<typename t>
const t &NodeStack<t> :: top() const{
    return m_top ->data();

}

//Push and Pop functionss
template<typename t>
void NodeStack<t> :: push(const t & value){
    m_top ->m_next = new Node<t>(value, NULL);
    m_top = m_top -> m_next;
}

template<typename t>
void NodeStack<t> :: pop(){
    Node<t> *topNode = m_top;
    m_top = m_top ->m_next;
    delete topNode;
    topNode = NULL;
}

//Everything Else
template<typename t>
size_t NodeStack<t> :: size() const{
    size_t i = 0; 
    Node<t> *temp = m_bot;
    while(temp != NULL){
        i++;
        temp = temp ->m_next;
    }
}

template<typename t>
bool NodeStack<t> :: empty() const{
    if(m_top == NULL){
        return true;
    }
    else{
        return false;
    }
}

template<typename t>
bool NodeStack<t> :: full() const{
    return false;
}

template<typename t>
void NodeStack<t> :: clear(){
    while(!empty()){
        pop();
    }
}

template<typename t>
void NodeStack<t> :: serialize(std::ostream & os) const{ 
    size_t i = 0;
    Node<t> *temp = m_top;
    while(temp != NULL){
        os << "#" << i << " " << temp ->data() << endl;
    }
}