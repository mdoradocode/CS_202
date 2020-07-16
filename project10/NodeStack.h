#pragma once 
#include <iostream>
#include <cstring>

using namespace std;

template <typename t> class NodeStack;
template <typename t> std :: ostream & operator<<(std::ostream &os, const NodeStack<t> &obj);

template <typename t>
class Node{
  friend class NodeStack<t>;  

  public:
    Node() :
	  m_next( NULL ){;}
	  Node(const t & data, Node * next = NULL): m_next( next ), m_data( data ){;}
	  Node(const Node & other): m_next( other.m_next ),m_data( other.m_data ){;}
	
    t & data(){  return m_data;}
    const t & data() const{  return m_data;}

  private:
    Node * m_next; 						
    t m_data;
};

template<typename t>
class NodeStack{
    friend std::ostream &operator<< <>(std::ostream & os, 
    const NodeStack & NodeStack);
    public:
        NodeStack(): m_top(NULL), m_bot(NULL){
            cout << "Calling Default Ctor: NodeStack" << endl;
        }
        NodeStack(size_t size, const t & value){
            cout << "Calling Parameterized Ctor: NodeStack" << endl;
            size_t i = 0;
            m_top = NULL;
            while(i != size){
                push(value);
                i++;
            }
        }
        NodeStack(const NodeStack<t> & other){
            cout << "Calling Copy Ctor: NodeStack" << endl;
            m_top = new Node<t>(other.m_top -> data(), NULL);
            Node<t> *otherCpy = other.m_top;
            Node<t> *newCpy = m_top;
            while(otherCpy != NULL){
                newCpy ->m_next = new Node<t>(otherCpy -> data(), NULL);
                newCpy = newCpy ->m_next;
                otherCpy = otherCpy->m_next;
            }
        }
        ~NodeStack(){
            cout << "Calling Deconstructor: NodeStack" << endl;
            clear();
        }

        NodeStack<t> & operator= (const NodeStack<t> & rhs){
            m_top = new Node<t>(rhs.m_top -> data(), NULL);
            Node<t> *otherCpy = rhs.m_top;
            Node<t> *newCpy = m_top;
            while(otherCpy != NULL){
                newCpy ->m_next = new Node<t>(otherCpy -> data(), NULL);
                newCpy = newCpy ->m_next;
                otherCpy = otherCpy ->m_next;
            }
        }


        t & top(){
          return m_top->data();
        }
        const t & top() const{
          return m_top ->data();
        }

        void push(const t & value){
          if(!empty()){
            Node<t> * temp = new Node<t>(value, NULL);
            temp->m_next = m_top;
            m_top = temp;
          }
          else{
            m_top = new Node<t>(value, NULL);
          }
        }

        void pop(){
            Node<t> *topNode = m_top;
            m_top = m_top ->m_next;
            delete topNode;
            topNode = NULL;
        }
        size_t size() const{
            size_t i = 0; 
            Node<t> *temp = m_bot;
            while(temp != NULL){
                i++;
                temp = temp ->m_next;
            }
        }
        bool empty() const{
            if(m_top == NULL){
                return true;
            }
            else{
                return false;
            }
        }
        bool full() const{
            return false;
        }
        void clear(){
            while(!empty()){
                pop();
            }
        }
        void serialize(std::ostream & os) const{ 
            size_t i = 0;
            Node<t> *temp = m_top;
            while(temp != NULL){
                os << "#" << i << " " << temp ->data() << endl;
                temp = temp ->m_next;
            }
        }
    private:
        Node<t> * m_top;
        Node<t> * m_bot; 
};
template<typename t>
std :: ostream & operator<<(std::ostream &os, const NodeStack<t> &obj){
    obj.serialize(os);
    return os;
}

