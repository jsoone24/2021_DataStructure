#pragma once
#include "CircularQueue.h"

class CircularDeque: public CircularQueue{
    public:
        CircularDeque(){}
        void addRear(int val){enqueue(val);}
        int deleteFront(){return dequeue();}
        int getFront(){return peek();}    
        void addFront(int val){
            if(isFull()){
                error(" Error: 덱이 포화상태입니다\n");
            }
            else{
                data[front] = val;
                front = (front-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
            }
        }
        int deleteRear(){        
            if(isEmpty()){
                error(" Error: 덱이 공백상태입니다\n");
            }
            else{
                int ret = data[rear];
                rear = (rear-1+MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                return ret;
            }
        }
        int getRear(){            
            if(isEmpty()){
                error(" Error: 덱이 공백상태입니다\n");
            }
            else return data[rear];
        }
        void display( ) {        
            std::cout << "Deque 안에는: ";
            int maxi = (front < rear) ? rear : rear + MAX_QUEUE_SIZE; 
            //front보다 rear 앞 인덱스인 경우는 rear를, 아니면 한바퀴 더 돈 곳에서 max를
            for( int i = front+1 ; i<=maxi ; i++ ){
                std::cout << data[i%MAX_QUEUE_SIZE] << " ";
            }
            std::cout << "\n";

        }
};
