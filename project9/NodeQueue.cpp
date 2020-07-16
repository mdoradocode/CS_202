#include <iostream>
#include <cstring>
#include "DataType.h"
#include "NodeQueue.h"

using namespace std;

/*Constructors*/
    //Default C-tor
    NodeQueue :: NodeQueue(): m_front(NULL), m_back(NULL){
        cout << "Testing Default C-tor: NodeQueue" << endl;
    }
    //Parameterized C-tor
    NodeQueue :: NodeQueue(size_t size, const DataType & value){
        cout << "Testing Parameterized C-tor: Node Queue" << endl;
        Node *temp = new Node(value, NULL);
        m_front = temp;
        m_back = temp;
        size_t i = 0;
        while(i < size-1){
            temp ->m_next = new Node(value, NULL);
            temp = temp ->m_next;
            i++;
        }
        m_back = temp;
    }
    //Copy C-tor
    NodeQueue ::NodeQueue(const NodeQueue & other){
        cout << "Testing Copy C-tor: Node Queue" << endl;
        m_front = new Node(other.m_front ->data());
        Node *HeadCpy = m_front;
        Node *BodyCpy = other.m_front;
        while(BodyCpy->m_next != NULL){
            BodyCpy = BodyCpy ->m_next;
            HeadCpy ->m_next = new Node(BodyCpy->data());
            HeadCpy = HeadCpy ->m_next;
        }
        HeadCpy ->m_next = NULL;
    }
    //Deconstructor
    NodeQueue :: ~NodeQueue(){
        cout << "Testing Deconstructor: Node Queue" << endl;
        clear();
    }
/*Overloads*/
    //Assignment Operator
    NodeQueue &NodeQueue :: operator= (const NodeQueue & rhs){
        cout << "Testing Assignment Operator: Node Queue"  << endl;
        clear();
        m_front = new Node(rhs.m_front ->data());
        Node *HeadCpy = m_front;
        Node *BodyCpy = rhs.m_front;
        while(BodyCpy->m_next != NULL){
            BodyCpy = BodyCpy ->m_next;
            HeadCpy -> m_next = new Node(BodyCpy->data());
            HeadCpy = HeadCpy ->m_next;
        }
        m_back = HeadCpy;
        HeadCpy ->m_next = NULL;
        return *this;
    }
    //Insertion Operator
    std :: ostream &operator<< (std::ostream &os, const NodeQueue obj){
        os << "Testing Insertion Operator: " << endl;
        obj.serialize(os);
        return os;
    }
/*Front and Back*/
    //Front 
    DataType & NodeQueue :: front(){
        if(!empty()){
            return m_front ->data();
        }
        exit(0);
    }
    const DataType & NodeQueue :: front() const{
        if(!empty()){
            return m_front ->data();
        }
        exit(0);
    }
    //Back
    DataType & NodeQueue :: back(){
        if(!empty()){
            return m_back ->data();
        }
        exit(0);
    }
    const DataType & NodeQueue :: back() const{
        if(!empty()){
            return m_back ->data();
        }
        exit(0);
    }
/*All other methods*/
    //Inserts node at the back of the queue
    void NodeQueue :: push(const DataType & value){
        Node *temp = new Node(value);
        m_back ->m_next = temp;
        m_back = temp;
        cout << "Testing push function: Node Queue" << endl;
    }
    //Removes the front element 
    void NodeQueue :: pop(){
        if(!empty()){
            Node *temp = m_front ->m_next;
            delete m_front;
            m_front = temp;
            cout << "Testing Pop function: Node Queue" << endl;
        }
    }
    //return the current size of the queue
    size_t NodeQueue :: size() const{
        size_t i = 0;
        Node *temp = m_front;
        while(temp ->m_next != NULL ){ //Maybe no work
            temp = temp ->m_next;
            i++;
        }
        return i;
    }
    //returns bool on if empty or not
    bool NodeQueue :: empty() const{
        return m_front==NULL;
    }
    //returns a true bool if full
    bool NodeQueue :: full() const{
        return false;
    }
    //Clears the entire queue
    void NodeQueue :: clear(){
            Node *kill = m_front;
            Node *track = m_front;
            while(track != NULL){
                track = track ->m_next;
                delete kill; 
                kill = track;
            }
            cout << "here" << endl;
            m_front = NULL;
            m_back = NULL;
    }
    //prints out Queue
    void NodeQueue :: serialize(std::ostream & os) const{
        Node *temp = m_front;
        while(temp ->m_next != NULL){
            os << temp ->data() << endl;
        }
    }