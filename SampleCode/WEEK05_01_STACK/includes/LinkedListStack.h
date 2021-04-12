#pragma once
#include "SingleLinkedList.h"

inline void error( const char* str ) { // 교과서 예제 코드에서 char* str 로 되어있습니다. 
    //C++ ISO 표준이 바뀌어서 이제 변수<->상수 암시적 변환이 안됩니다. 문자열 상수는 cosnt char*로 쓰세요.
    std::cerr << str << "\n"; // 에러의 경우는 std::cerr로 출력합니다.
    exit(1);
};

class LinkedListStack : public s_linked_list{
    public:
        LinkedListStack(): s_linked_list(){}
        bool isEmpty(){return Size() == 0;}
        void push(int e){
            push_front(e);
        }
        int pop(){
            if(isEmpty()) error ("스택 공백 에러");            
            return pop_front();
        }    
        int peek(){    
            if(isEmpty()) error ("스택 공백 에러");    
            return head->data;
        }        
        void display(){
            node* ptr = head;
            std::cout << "[전체 스택의 수 = " << Size() << "] ";
            for(int i = 0; i < Size(); i++){
                std::cout << "<" << ptr->data << ">";
                ptr = ptr->next;
            }
            std::cout << "\n";
        }
};