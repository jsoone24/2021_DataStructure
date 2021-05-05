// 맨윗줄 주석 테스트
#pragma once
#include <iostream>
#include <vector>
#include <chrono>

template<typename T>
struct node{
    T data;
    node<T> *next = nullptr;
    node<T> *prev = nullptr; // 일단 이렇게 노드 포인터 2개를 만들어 줍니다
};

template<typename T>
class d_linked_list{
    protected:
        node<T> *head, *tail; // head: first node, tail: last node
        int length = 0; // private로 만들고 getHead(), setHead(), getTail(), setTail 이런 methods를 만들어서 쓰는게 사실 더 좋습니다.
    public:
        d_linked_list(){
            head = nullptr;
            tail = nullptr;
        }
        ~d_linked_list() {
            delete_list();
        } //소멸자

        // 삽입연산들
        void push_front(T n); // 노드를 맨 앞에 한 개 추가합니다.
        void push_back(T n); // 노드를 끝에 한 개 추가합니다.
        void insert_node_at(int idx, T n); // 정해진 위치에 추가합니다.
        
        // 삭제연산들	
        T pop_front(); // 맨 앞 노드를 지웁니다.
        T pop_back(); // 끝 노드를 지웁니다. 
        T pop_node_at(int i); // i번째 노드를 지웁니다. 
        void delete_list(); // linked list 전체를 지웁니다.
        
        // 조회연산들
        T front();
        T back();
        int size();
        void display_contents(); // linked list의 내용을 보여줍니다.
};

// 삽입연산들
template<typename T>
void d_linked_list<T>::push_front(T n){ // 리스트의 맨 앞에 노드를 추가합니다.
    node<T> *ptr = new node<T>; // 새 노드의 메모리를 할당해주고
    ptr->data = n; 
    ptr->next = head; // 기존의 head는 ptr의 다음 노드가 되고
    //ptr->prev = nullptr; // ptr이 가장 첫 노드이니 그 앞은 nullptr로 두고
    if(head == nullptr){// head가 없다면 당연히 tail도 없겠죠. 
        head = ptr;
        tail = ptr; // 그러니 head = tail = ptr
    }
    else{
        head->prev = ptr; // 이전 head의 이전 노드로 ptr을 연결해주고
        head = head->prev; // ptr을 새 head로 정해줍니다.
    }
    length++; // 길이를 하나 늘려줍니다.
}

template<typename T>
void d_linked_list<T>::push_back(T n){ // 리스트의 맨 끝에 노드를 추가합니다.
    node<T> *ptr = new node<T>; // 새 노드의 메모리를 할당해주고
    ptr->data = n;
    //ptr->next = nullptr; // ptr이 가장 마지막 노드이니 그 뒤는 nullptr이 됩니다
    ptr->prev = tail; // 기존의 tail은 ptr의 이전 노드가 되고
    if(head ==nullptr){// head가 없다면 당연히 tail도 없겠죠. 
        head = ptr; 
        tail = ptr; // 그러니 head = tail = ptr
    }
    else{
        tail->next = ptr; // 이전 tail의 다음 노드로 
        tail = tail->next; // ptr을 새 tail로 정해줍니다.
    }
    length++; // 길이를 하나 늘려줍니다.
}

// 삭제연산
template<typename T>
T d_linked_list<T>::pop_front(){ // 리스트의 맨 앞 노드를 지웁니다.
    if(length <= 0 ){
        std::cout << "Linked List가 비어있습니다.\n";
    }
    else{
        node<T> *ptr = head; // ptr을 기존의 head로 assign 해줍니다.
        T value = head->data; // 일단 value를 임시로 저장해둡니다.
        head = ptr->next; // head를 기존 head의 다음 노드로 바꿔줍니다.
        if(head == nullptr){ // 새 head가 nullptr이면 빈 리스트가 됩니다. 
            tail = nullptr; // 그러므로 tail도 nullptr이 되어야 합니다.
        }
        else{ // 새 head가 nullptr이 아니라면
            head->prev = nullptr; // 새 head의 앞 노드를 nullptr로 만들어줍니다.
        /*    if(head->next == nullptr){ // 이 경우는 head == tail이 됩니다.
                tail = head; // 그래서 tail과 head를 같게 만들어줘야 합니다.
            }*/ // UPDATED(2020/04/23): 이 부분이 필요하지 않을 것 같습니다. 
        }
        delete ptr; // 임시 포인터였던 ptr은 지워주고
        length--; // 길이를 하나 줄여줍니다.
        return value;
    }
}

template<typename T>
T d_linked_list<T>::pop_back(){ // 리스트의 맨 뒤 노드를 지웁니다
    if(length <= 0 ){
        std::cout << "Linked List가 비어있습니다.\n";
    }
    else{	
        node<T> *ptr = tail; // ptr을 기존의 tail로 assign 해줍니다.
        T value = ptr->data; // 일단 value를 임시로 저장해둡니다.
        tail = ptr->prev; // tail을 기존 tail의 이전 노드로 바꿔줍니다.
        if(tail == nullptr){ // 새 tail이 nullptr이면 빈 리스트가 됩니다.
            head = nullptr; // 그러므로 head도 nullptr이 되어야 합니다.
        }
        else{ // 새 tail이 nullptr이 아니라면
            tail->next = nullptr; // 새 tail의 뒤 노드를 nullptr로 만들어줍니다.
            /*if(head->next == nullptr){ // 이 경우는 head == tail 이 됩니다.
                head = tail; // 그래서 head와 tail을 같게 만들어줘야 합니다.
            }*/ // UPDATED(2020/04/23): 이 부분이 필요하지 않을 것 같습니다. 
        }
        delete ptr; // 임시 포인터였던 ptr은 지워주고
        length--; // 길이를 하나 줄여줍니다.
        return value;
    }
}

template<typename T>
void d_linked_list<T>::insert_node_at(int idx, T n){ // index에 값을 넣습니다.
    if(length < idx || 0 > idx){
        std::cout << "해당 인덱스는 존재하지 않습니다\n";
    }
    else if(idx <= length/2){ // idx가 전체 길이 반보다 작으면 앞부터 탐색합니다.
        node<T> *new_node = new node<T>;
        new_node->data = n;
        node<T> *ptr = head; // head부터 탐색하는 ptr 포인터를 만들어줍니다.
        if(idx == 0){ // 삽입할 위치가 기존 head의 위치라면
            push_front(n);
        }
        else{
            for(int i=0; i < idx; i++){
                ptr = ptr->next; // 다음 노드로 타겟을 바꿉니다.
            }            
            new_node->next = ptr; // 새 노드의 다음 노드로 ptr을 두고        
            if(ptr != nullptr){ // ptr이 nullptr이면 빈 노드입니다. 
            // 그래서 아래 작업을 해 주면 오류가 납니다.
                new_node->prev = ptr->prev; // 기존 ptr의 이전 노드를 new_node->prev로
                ptr->prev = new_node; // ptr의 이전 노드를 new_node로
                if(new_node->prev != nullptr){
                    new_node-> prev -> next = new_node; // 조금 혼란스럽죠?
                }
                // A와 B라는 두 노드 사이에 N이라는 새 노드를 삽입 한다 생각하면
                // 첫줄의 연산을 하면 : A <- N -> B, A <-> B 상태가 되고
                // 두번째 줄의 연산을 하면 : A <- N <-> B, A -> B 상태가 됩니다
                // 이제 필요한 링크가 A -> B 의 링크가 필요하죠.
                // 그 링크를 만들기 위한 작업입니다.
                // new_node의 "이전 노드"를 찾아서, 
                // 그 노드의 "다음 노드"가 new_node라는걸 선언해 줍니다.
            }
            length++; // 노드를 삽입합니다.
        }
    }
    else{ // idx가 전체 길이 반보다 크면 뒤부터 탐색합니다.
        node<T> *new_node = new node<T>;
        new_node->data = n;
        node<T> *ptr = tail;
        for(int i=0; i < (length-idx); i++){ // 뒤에서부터 탐색합니다.
            ptr = ptr->prev; // 다음 노드로 타겟을 바꿉니다.
        }
        if(ptr == tail){ // 삽입할 위치가 기존의 tail의 위치라면
            push_back(n);
        }
        else{
            new_node->prev = ptr;
            new_node->next = ptr->next;
            ptr->next = new_node;
            if(new_node->next != nullptr){
                new_node->next->prev = new_node;
            }
            length++; // 노드를 삽입합니다.
        }
    }
}

template<typename T>
T d_linked_list<T>::pop_node_at(int idx){ // i번째 노드를 지웁니다.
    T value;
    if(length < idx || 0 > idx){
        std::cout << "해당 인덱스는 존재하지 않습니다\n";
    }
    else if(idx <= length/2){ // idx가 전체 길이 반보다 작으면 앞부터 탐색합니다.    
        if(idx == 0){ // 삭제할 위치가 기존 head의 위치라면
            return pop_front();
        }
        else{
            node<T> *ptr = head;
            for(int i=0; i < idx; i++){
                ptr = ptr->next; // 다음 노드로 타겟을 바꿉니다.
            }
            if(ptr == tail){ // 삭제할 위치가 기존의 tail의 위치라면
                return pop_back(); // (이 경우는 length = 2, idx = 1 인 경우만 발생합니다.)
            }            
            value = ptr->data;
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            length--; // 노드를 삭제합니다.
            delete ptr;
        }
    }
    else{ // idx가 전체 길이 반보다 크면 뒤부터 탐색합니다.
        node<T> *ptr = tail;
        for(int i=0; i < (length-idx); i++){
            ptr = ptr->prev; // 다음 노드로 타겟을 바꿉니다.
        }
        if(ptr == tail){ // 삭제할 위치가 기존의 tail의 위치라면
            return pop_back();
        }
        else{
            value = ptr->data;
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            length--; // 노드를 삭제합니다.
            delete ptr;
        }
    }
    return value;
}

template<typename T>
void d_linked_list<T>::delete_list(){
    node<T> *ptr = head;
    while(ptr != nullptr){
        head = ptr->next;
        delete ptr;
        ptr = head;
    }
    length = 0;
    std::cout << "리스트가 삭제되었습니다 \n";
}

// 검색 및 표시
template<typename T>
int d_linked_list<T>::size(){
    return length;
}

template<typename T>
T d_linked_list<T>::front(){ // 리스트의 맨 앞 노드를 조회합니다
    if(length <= 0 ){
        std::cout << "Linked List가 비어있습니다.\n";
    }
    else{	
        return head->data;
    }
}

template<typename T>
T d_linked_list<T>::back(){ // 리스트의 맨 앞 노드를 조회합니다
    if(length <= 0 ){
        std::cout << "Linked List가 비어있습니다.\n";
    }
    else{	
        return tail->data;
    }
}

template<typename T>
void d_linked_list<T>::display_contents(){
    node<T> *ptr = head;
    std::cout << "From head: nullptr->";
    while(ptr != nullptr){
        std::cout << ptr->data << "->";
        ptr = ptr->next;
    }
    std::cout << "nullptr" << "\n";

    ptr = tail;
    std::cout << "From tail: nullptr->";
    while(ptr != nullptr){
        std::cout << ptr->data << "->";
        ptr = ptr->prev;
    }
    std::cout << "nullptr" << "\n";	
}

template<typename T>
class dll_deque: public d_linked_list<T>{
    public:
        dll_deque() : d_linked_list<T>(){}
        ~dll_deque(){this->delete_list();}
        using d_linked_list<T>::push_front; // 방법 1
        void addFront(T n){push_front(n);}
        void addRear(T n){d_linked_list<T>::push_back(n);} // 방법 2
        T getFront(){return this->front();} // 방법 3
        T getRear(){return d_linked_list<T>::back();}
        T deleteFront(){return this->pop_front();}
        T deleteRear(){return d_linked_list<T>::pop_back();}       
};

