#pragma once
#include <iostream>

// 다른 식으로 singly linked list를 구현해봅시다.

class node {
    private:
        int data;
        node* next;

    public:
        node(int val = 0){
            data = val;
            next = nullptr;
        }

        node* getLink(){ return next; }
        int getData(){ return data; }
        void setLink(node* target){ next = target; }
       
        void insertNext(node *newnode){
            if(newnode != nullptr) {
                newnode->next = next;
                next = newnode;
            }
        } // 노드의 다음 자리에 새 노드를 넣는 연산

        node* removeNext( ) {
            node* removed = next;
            if(removed != nullptr)
                next = removed->next;
            return removed;
        } // 노드의 다음 자리 노드를 지우는 연산
}; //node class의 연산을 몇가지 더 정의해줍니다

class hn_s_linked_list{
    protected:
        node origin;
        
    public:
        hn_s_linked_list(): origin(0){} //생성자
        ~hn_s_linked_list(){ clear(); } //소멸자

        void clear(); // 리스트를 지우는 연산
        node* getHead(); // 첫 노드를 부르는 연산
        bool isEmpty(); // 공백 확인

        node* getEntry(int pos); // 조회연산
        void insert(int pos, node *n); // 삽입연산
        void remove(int pos); // 삭제연산
        node* find(int value); // 검색연산 (value와 같은 값을 찾음)
        void replace(int pos, node *n); // 치환연산
        size_t size(); // 사이즈 구하기
        void display(); // Linked List의 전체 내용 출력
};

void hn_s_linked_list::clear(){
    while(!isEmpty()){
        remove(0);
    }
} // 리스트를 지우는 연산

node* hn_s_linked_list::getHead(){
    return origin.getLink();
} // 첫 노드를 부르는 연산

bool hn_s_linked_list::isEmpty(){
    return getHead() == nullptr;
} // 공백 확인

node* hn_s_linked_list::getEntry(int pos){
    node* n = &origin;
    for(int i = -1; i < pos; i++, n = n->getLink()){
        if(n == nullptr){ break; }
    }
    return n;
} // 조회연산

void hn_s_linked_list::insert(int pos, node *n){
    node* prev = getEntry(pos - 1);
    if(prev != nullptr){
        prev->insertNext(n);
    }
} // 삽입연산

void hn_s_linked_list::remove(int pos){
    node* prev = getEntry(pos - 1);
    delete prev->removeNext();
} // 삭제연산

node* hn_s_linked_list::find(int value){
    for(node *p = getHead() ; p != nullptr ; p = p->getLink()){
        if(p->getData() == value){ return p; }
    }
    return nullptr;
} // 검색연산 (value와 같은 값을 찾음). 가장 먼저 나오는 노드를 리턴
    
void hn_s_linked_list::replace(int pos, node *n){
    node* prev = getEntry(pos - 1);
    if(prev != nullptr){
        delete prev->removeNext();
        prev->insertNext(n);
    }        
} // 치환연산

size_t hn_s_linked_list::size(){
    int count = 0;
    for(node *p = getHead(); p != nullptr ; p = p->getLink()){
        count++;
    }
    return count;
} // 사이즈 구하기

void hn_s_linked_list::display(){
    std::cout << "전체 항목의 수: " << size() << ", ";
    for(node *p = getHead(); p != nullptr ; p = p->getLink()){
        std::cout << p->getData() << " ";
    }
} // Linked List의 전체 내용 출력