#include <iostream>
#include <cstring>
#include "DataType.h"
#include "ArrayQueue.h"

using namespace std;

const size_t AMax = 1000;
/*Constructors*/
    //Default C-tor
    ArrayQueue :: ArrayQueue(): m_back(0), m_front(0), m_size(0){
        cout << "Testing Default C-tor: Array Queue" << endl;
    }
    //Parameterized C-Tor
    ArrayQueue :: ArrayQueue(size_t count, const DataType & value): m_size(count){
        cout << "Testing Paramertarized C-tor: Array Queue" << endl;
        m_front = 0;
        size_t i = 0;
        while(i < count){
            m_array[i] = value;
            m_back = i;
            i++;
        }
    }
    //Copy C-tor
    ArrayQueue :: ArrayQueue(const ArrayQueue &obj):m_size(obj.m_size){
        cout << "Testing Copy C-tor: Array Queue" << endl;
        m_front = 0;
        size_t i = 0;
        while(i < obj.m_size){
            m_array[i] = obj.m_array[i];
            m_back = i;
            i++;
        }
    }
    //Dtor
    ArrayQueue :: ~ArrayQueue(){
    }

/*Operator Overload*/
    //Assignment Operator 
    ArrayQueue &ArrayQueue :: operator=(const ArrayQueue &rhs){
        cout << "Testing Assignment Operator: Array Queue" << endl;
        size_t i = 0;
        while(i < rhs.m_size){
            m_array[i] = rhs.m_array[i];
            i++;
        }
        m_size = rhs.m_size;
        m_front = 0;
        m_back =  rhs.m_back;
    }
    //Insertion Operator 
    std :: ostream &operator<< (std :: ostream &os, const ArrayQueue obj){
        size_t i = 0;
        os << "Testing Insertion Operator: Array Queue" << endl;
        os << "The size of the array is: " << obj.size() << endl;
        os << "The content of the array is: " << endl;
        obj.serialize(os);
        return os;
    }

/*Front and Back*/
    //Front
    DataType &ArrayQueue :: front(){
        if(!empty()){
            return m_array[m_front];
        }
        exit(0);
    }
    const DataType &ArrayQueue :: front()const{
        if(!empty()){
            return m_array[m_front];  
        }
        exit(0);
    }

    //Back
    DataType & ArrayQueue ::back(){
        if(!empty()){
            return m_array[m_back];
        }
        exit(0);
    }
    const DataType & ArrayQueue :: back()const{
        if(!empty()){
            return m_array[m_back];
        }
        exit(0);     
    }
/*All Others*/
    //Push(at back of queue)
    void ArrayQueue :: push(const DataType & value){
        size_t i = m_back + 1;
        m_array[i] = value;
        cout << "Testing Push Function: Array Queue" << endl;
    }
    //Take 1 element out
    void ArrayQueue :: pop(){
        for(size_t i = 0; i < m_size; i++){
            m_array[i] = m_array[i+1];
        }
        m_size--;
        m_back = m_size;
        m_front = 0;
        cout << "Testing Pop Function: Array Queue" << endl;
    }
    //return the size of the queue(not max size)
    size_t ArrayQueue :: size() const{
        return m_size;
    }
    //check to see if array empty
    bool ArrayQueue :: empty() const{
        return m_size == 0;
    }
    //check to see if the array is full
    bool ArrayQueue :: full() const{
        if(m_size == AMax){
            return true;
        }
        else{
            return false;
        }
    }
    //Clear the Queue **Double check this function for sure**
    void ArrayQueue :: clear(){
        ArrayQueue empty;
        *this = empty;
    }
    // Prints out the Queue **think lab 11 i think**
    void ArrayQueue :: serialize(std::ostream & os) const{
        size_t i = 0;
        while(i < m_size){
            os << m_array[i] << endl;
        }
    }
