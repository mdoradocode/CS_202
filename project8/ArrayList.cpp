#include <iostream>
#include <cstring>
#include <fstream>
#include "DataType.h"
#include "ArrayList.h"

using namespace std;

/*Constructors*/
    //Default Ctor
    ArrayList :: ArrayList(): m_size(0){
        m_array = NULL;
        m_maxsize = 0;
        m_size = 0;
        cout << "Calling D-Ctor: ArrayList"<< endl;
    }
    //Paramertarized Ctor
    ArrayList :: ArrayList(size_t count, const DataType & value){
        m_maxsize = count;
        m_size = count;
        size_t i = 0;
        m_array = new DataType[m_maxsize];
        while(i < m_maxsize){
            m_array[i] = value;
            i++;
        }

        cout << "Calling P-Ctor: ArrayList" << endl;
    }
    //Copy Ctor
    ArrayList :: ArrayList(const ArrayList & rhs){
        m_size = rhs.m_size;
        m_maxsize = rhs.m_maxsize;
        m_array = new DataType[m_size];
        size_t i = 0;
        while(i < m_maxsize){
            m_array[i] = rhs.m_array[i];
            i++;
        }
        cout << "Calling C-Ctor: ArrayList"<<endl;
    }
    //D-Ctor
    ArrayList :: ~ArrayList(){
        delete[] m_array;
        cout<<"Calling D-Ctor: ArrayList"<<endl;
    }
/*Operator Overload*/
    //Assignment Operator
    ArrayList& ArrayList::operator=(const ArrayList &rhs){
        delete[] this ->m_array;
        this -> m_array = new DataType[rhs.m_maxsize];
        size_t i = 0;
        for(;i < m_maxsize; i++){
            this ->m_array[i] = rhs.m_array[i];
        }
        this -> m_maxsize = rhs.m_maxsize;
        this -> m_size = rhs.m_size;
        return *this;
    }

    //Indexing Operator
    DataType& ArrayList::operator[](size_t position){
        return m_array[position];
    }

    //Insertion Operator
    std::ostream & operator<<(std::ostream &os, const ArrayList &obj){
        os << "All Data Elements in the Array List:" << endl;
        for(int i = 0; i < obj.m_size; i++){
            os << obj.m_array[i] << endl;
        }
        os << "Max array size: " << obj.m_maxsize << endl;
        os << "Actual array size: " <<  obj.m_size << endl;
        return os;
    }

/*Array Manipulation*/
    //Inserts
    DataType* ArrayList::insertAfter(const DataType &target, const DataType &value){
        DataType *temp = m_array;
        for(size_t i = 0; temp != NULL; i++){
            if(*temp == target){
                size_t j = m_size -1;
                for(; j>i; j--){
                    m_array[j] = m_array[j-1];
                   
                }
                m_array[i+1] = value;
                *temp = m_array[i+1];
                return temp;
            }
            temp++;
        }
        return NULL;
    }

    DataType* ArrayList::insertBefore(const DataType &target, const DataType &value){
        DataType *temp = m_array;
        for(size_t i = 0; temp != NULL; i++){
            if(*temp == target){
                for(size_t j = m_size - 1; i < j; j--){
                    m_array[j] = m_array[j-1];
                }
                m_array[i] = value;
                return temp;
            }
            temp++;
        }
        return NULL;
    }

    //Find, Front, Back
    DataType* ArrayList::find(const DataType &target, DataType *& previous){
        DataType *temp;
        temp = m_array;
        size_t i = 0;
        if(temp != NULL){
            while(i < m_size){
                if(*temp == target){
                    if(temp != NULL){
                        previous = temp;
                    }
                    else{
                        previous = NULL;
                    }  
                    temp++;
                    return temp;
                }            
                i++;
                temp++;
            }
        }
        previous = NULL;
        return NULL;
    }
    DataType* ArrayList::front(){
        size_t i = 0;
        if(m_array != NULL){ //Not sure if this one is gonna work champ
            return &m_array[i];
        }
        else{
            cout << "This list empty, YEET" << endl;
            return NULL;
        }
    }

    DataType* ArrayList::back(){
        size_t i  = m_size;
        if(m_array != NULL){
            return &m_array[m_size];
        }
        else{
            cout << "This list empty, YEET" << endl;
            return NULL;
        }
    }
    
    //Empty, Clear, And Size *May need to make an erase function here*  
    bool ArrayList::empty() const{
        if(this ->m_size == 0){
            return true;
        }
        else{
            return false;
        }
    }

    void ArrayList::clear(){ //May need to do more with this function
        if(m_array != NULL){
            delete[] m_array;
            m_array = NULL;
        }
        m_size = 0;
        m_maxsize = 0;
    }

    size_t ArrayList::size() const{
        return m_size;
    }

/*This little monstrosity*/
    //Resize or whatever
    void ArrayList::resize(size_t count){
        delete[] m_array;
        this ->m_array = new DataType[count];
        this ->m_maxsize = count;
        this ->m_size = count;
    }


