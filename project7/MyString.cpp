#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace std;

//Constructors//
MyString :: MyString(){buffer_allocate(0);}

MyString :: MyString(const char *str){
    m_size = strlen(str)+1;
    m_buffer = new char [m_size];
    strcpy(m_buffer, str);

}

MyString :: MyString(const MyString &copy){
    buffer_allocate(m_size);
    strcpy(m_buffer, copy.m_buffer);
}

MyString :: ~MyString(){
    this -> buffer_deallocate();
}


//Data Allocation-Deallocation//
void MyString :: buffer_deallocate(){
    delete[] m_buffer;
    m_buffer = NULL;
    m_size = 0;
}

void MyString :: buffer_allocate(size_t size){
    try{
    m_size = size;
    m_buffer = new char[size];
    }
    catch(const std::exception& e){
        std::cerr  << e.what() << endl;
        this -> buffer_deallocate();
    }
}


//Getters//
size_t MyString :: size()const{
    return m_size;
}

size_t MyString :: length()const{
    return m_size-1;
}

const char *MyString :: c_str()const{
    return m_buffer;
}


//Overloads//
bool MyString :: operator==(const MyString &other)const{
    if(strcmp(m_buffer,other.m_buffer)==0){
        return true;
    }
    else{
        return false;
    }
}

MyString & MyString ::  operator=(const MyString &obj){
    this -> buffer_deallocate();

    try{
       this -> buffer_allocate(obj.size());
       for(size_t i = 0; i < obj.size(); i++){
           (*this)[i] = obj[i];
       }
    }
    catch(std :: bad_alloc & e){
        std :: cerr << e.what() << endl;
        this -> buffer_deallocate();
    }
    return *this;
}

MyString MyString:: operator+(const MyString &otherObj)const{
    char *concat = m_buffer;
    strcat(concat, otherObj.c_str()); 
    MyString string(concat);
    return string;
}

char & MyString :: operator[](size_t index){
    return m_buffer[index];
}

const char & MyString :: operator[](size_t index) const{
    return m_buffer[index];
}

std :: ostream &operator<<(std::ostream &os, const MyString &myStr){
    os << myStr.m_buffer;
    return os;
}   




