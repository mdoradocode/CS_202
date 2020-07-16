#include <iostream>
#include <cstring>
#include <fstream>
#include "DataType.h"
#include "NodeList.h"

using namespace std;

/*C-tors*/
    //Default Ctor
    NodeList :: NodeList(){
        m_head = NULL;
        cout << "Calling D-Ctor: NodeList"<<endl;
    }

    //Parameratized Ctor
    NodeList :: NodeList(size_t count, const DataType &value){
        if(count <= 0){
            m_head = NULL;
        }
        else{
            m_head = new Node(value, NULL);
            Node *newnode = m_head;
            size_t i = 0;
            while(i < count){
                newnode ->m_next = new Node(value, NULL);
                newnode = newnode ->m_next;
                i++;
            }
            newnode ->m_next = NULL;
        }
        cout<<"Calling P-Ctor: NodeList" << endl;
    }

    //Copy Ctor 
    NodeList :: NodeList(const NodeList & obj){
        if(obj.m_head ->m_next != NULL){
            m_head = new Node(obj.m_head ->data());
            Node *headcpy = m_head;
            Node *bodycpy = obj.m_head;
            while(bodycpy ->m_next != NULL){
                bodycpy = bodycpy ->m_next;
                headcpy ->m_next = new Node(bodycpy ->data());
                headcpy = headcpy ->m_next;
            }
            headcpy -> m_next = NULL;
        }
        cout << "Calling C-Ctor: NodeList" << endl;
    }

    //D Ctor
    NodeList :: ~NodeList(){
        clear();
        cout << "Calling D-Ctor: NodeList" << endl;
    }
/*Operator Overload*/
    //Assignment Operator
    NodeList & NodeList::operator=(const NodeList &rhs){
        if(this != &rhs){
            Node *Headcpy = m_head;
            Node *Bodycpy = rhs.m_head;
            if(this ->size() < rhs.size()){
                clear();
                DataType newData(0, 0.0);
                NodeList newNode(rhs.size(), newData);
                Headcpy = newNode.m_head;
            }
            while(Bodycpy -> m_next != NULL){
                Headcpy ->m_data = Bodycpy ->data();
                Headcpy = Headcpy ->m_next;
                Bodycpy = Bodycpy ->m_next;
            }
        }
        return *this;
    }

    //Indexing Operator
    DataType &NodeList::operator[](size_t position){
        size_t i = 0;
        Node *obj = m_head;
        while(i < position){
            obj = obj ->m_next;
            i++;
        }
        return obj ->data();
    }

    const DataType & NodeList::operator[](size_t position) const{
        size_t i = 0;
        Node *obj = m_head;
        while(i < position){
            obj = obj ->m_next;
            i++;
        }
        return obj ->data();
    }

    //Insertion Operator
    std::ostream & operator<<(std::ostream & os, const NodeList &obj){
        size_t i = 0;
        while(i < obj.size()){
            os << "Node #" << i << ": " << obj[i] << endl;
            i++;
        }
        return os;
    }
/*List manipulation*/
    //Insertion: Run into issues when there is no matching target variable
    Node* NodeList::insertAfter(const DataType &target, const DataType &value){
        Node *temp = m_head;
        while(temp != NULL){
            if(temp ->data() == target && temp != NULL){
                temp -> m_next= new Node(value,temp ->m_next);
                return temp ->m_next;
            }
            temp = temp ->m_next;
        }
        if(empty()){
            m_head = new Node(value, NULL);
            return m_head;
        }
        return NULL;
    }

    Node* NodeList::insertBefore(const DataType &target, const DataType &value){
        if(empty()){
            m_head = new Node(value, NULL);
            return m_head;
        }
        else if(m_head ->data() == target){
            Node *tempHead = new Node(value, NULL);
            tempHead ->m_next = m_head;
            return tempHead;
        }
        
        Node *temp1 = NULL;
        Node *temp2 = m_head;
        while(temp2 != NULL){
            if(temp2 ->data() == target && temp2 != NULL){
                temp1 ->m_next = new Node(value, temp2);
                return temp1 ->m_next;
            }
            temp1 = temp2;
            temp2 = temp2 ->m_next;
        }
        return NULL;
    }

    //Front and Back
    Node* NodeList::front(){
        return m_head;
    }

    Node* NodeList::back(){
        Node *temp = m_head;
        while(temp ->m_next != NULL){
                temp = temp ->m_next;
        }
        return temp;
    }

    //Find
    Node* NodeList::find(const DataType &target, Node *& previous){
        Node *temp = m_head;
        while(temp ->m_next != NULL && temp != NULL){
            if(temp -> m_next ->data() == target){
                if(temp != NULL){
                    previous = temp;
                }
                else{
                previous = NULL;
                }
                return temp ->m_next;
            }
            temp = temp ->m_next;
        }
        previous = NULL;
        return previous;
    }

    //Erase and Clear
    void NodeList::clear(){
        Node *track = m_head;
        Node *kill = m_head;
        while(track != NULL){
            track = track ->m_next;
            delete kill;
            kill = track;
        }
        m_head = NULL;
    }

    Node* NodeList::erase(const DataType &target){
        Node *temp = m_head;
        Node *pre = m_head;
        if(m_head ->m_next == NULL){
            m_head = m_head ->m_next;
            return m_head;
        }
        if(empty()){
            return NULL;
        }
        pre = find(target, temp);
        if(pre != NULL){
            temp ->m_next = pre ->m_next;
            delete pre;
            return temp;
        }
        return NULL;
    }

    //Empty and Size
    size_t NodeList::size() const{
        Node *temp = m_head;
        size_t i = 0;
        while(temp ->m_next != NULL){
            temp = temp ->m_next;
            ++i;
        }
        return i-1;
    }

    bool NodeList::empty() const{
        if(m_head == NULL){
            return true;
        }
        return false;
    }