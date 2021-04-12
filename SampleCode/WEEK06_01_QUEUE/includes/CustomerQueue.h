#pragma once
#include "Customer.h"

#define MAX_QUEUE_SIZE 100

inline void error(const char* str){
    std::cerr << str << "\n"; // 에러의 경우는 std::cerr로 출력합니다.
    exit(1);
};

class CustomerQueue{
    private:
        int    front;                    
        int    rear;                    
        Customer data[MAX_QUEUE_SIZE];    
    public:
        CustomerQueue()    {front = rear = 0;}
        bool isEmpty() { return front == rear;}
        bool isFull(){return (rear+1) % MAX_QUEUE_SIZE == front;} // 나머지 연산으로 위치를 찾습니다.
        void enqueue(Customer& val) {
            if(isFull()){
                error(" Error: 큐가 포화상태입니다\n");
            }
            else{
                rear = (rear+1) % MAX_QUEUE_SIZE;
                data[rear] = val;
            }
        }
        Customer& dequeue(){    
            if(isEmpty()){
                error(" Error: 큐가 공백상태입니다\n");
            }
            else{
                front = (front+1) % MAX_QUEUE_SIZE;
                return data[front];
            }
        }
};
