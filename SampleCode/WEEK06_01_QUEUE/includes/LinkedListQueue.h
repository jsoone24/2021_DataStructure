#pragma once
#include "SingleLinkedList.h"

inline void error( const char* str ) {
    std::cerr << str << "\n";
    exit(1);
};

class LinkedListQueue : public s_linked_list{
    public:
        LinkedListQueue(): s_linked_list(){}
        bool isEmpty(){return Size() == 0;}
        void enqueue(int e){
            push_back(e);
        }
        int dequeue(){
            if(isEmpty()){error ("Queue 공백 에러");}
            return pop_front();
        }    
        int peek(){    
            if(isEmpty()){error ("Queue 공백 에러");}
            return head->data;
        }
        void display(){
            std::cout << "Queue 안에는: ";
            node* ptr = head;
            for(int i = 0; i < Size(); i++){
                std::cout << ptr->data << " ";
                ptr = ptr->next;
            }
            std::cout << "\n";
        }
};