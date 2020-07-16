#include <iostream>
#include <string.h>

class Client{
  private:
    char * m_name;
  public:
    Client();
    Client(const char * name){
        strcpy(m_name, name);
    }
    Client(const Client & other){
        strcpy(m_name, other.m_name);
    }
    ~Client();
    Client & operator=(const Client & rhs){
        strcpy(m_name, rhs.m_name);
        return * this;
    }
    char * GetName() const{
        return m_name;
    }
    friend std::ostream & operator<<(std::ostream & os, const Client & obj){
        os << obj.m_name;
        return os;
    }
    friend std::istream & operator>>(std::istream & is, const Client & obj){
        is >> obj.m_name;
        return is;
    }
};