#include <iostream>
#include "Client.h"
#include "Cover.h"
#include <string.h>
#pragma once

using namespace std;

class Book{
    protected:
        char *m_title;
        Cover m_cover;
        static size_t count;

    private:
        const Client *m_client;
        const size_t m_serial;
    
    public:
        Book():m_serial(count){count++;}
        Book(char *title, Cover cover, const Client *client, size_t serial):m_serial(count++){
            count++;
            strcpy(m_title, title);
            m_cover = cover;
            if(!client){
                m_client = NULL;
            }
            else{
                m_client = client;
            }
        }
        Book(Book &copy):m_serial(count){
            count++;
            strcpy(m_title, copy.getTitle());
            this ->setCover(copy.getCover());
            this ->setClient(copy.getClient());
        }
        
        Book & operator=(Book &rhs){
            strcpy(m_title, rhs.getTitle());
            this ->setClient(rhs.getClient());
            this ->setCover(rhs.getCover());
        }
            
        

        void setCover(Cover cover){
            m_cover = cover;
        }
        void setClient(const Client *client){
            m_client = client;
        }

        const Client *getClient(){
            return m_client;
        }
        const Cover getCover(){
            return m_cover;
        }
        const char *getTitle(){
            return m_title;
        }
        const size_t getCount(){
            return count;
        }

        void serialize(std:: ostream &os){
            os << this ->m_title << endl << this ->m_cover << endl << this ->m_client << endl << this ->m_serial << endl;
        }

        friend std :: ostream & operator<<(std:: ostream &os, Book &obj){
            obj.serialize(os);
            return os;
        }
};


