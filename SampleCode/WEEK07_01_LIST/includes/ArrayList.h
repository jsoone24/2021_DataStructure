#pragma once
#include <iostream>
#define MAX_LIST_SIZE 100000


inline void error(const char* str) { 
    std::cerr << str << "\n"; 
    exit(1);
};

class ArrayList{
    private:
        int data[MAX_LIST_SIZE];
        size_t length;  
        // size_t == unsigned int
        // 32비트 OS에선 uint32_t
        // 64비트 OS에선 uint64_t

    public:
        ArrayList(void){ length = 0; } // 생성자

        void insert(int pos, int e){
            if(!isFull() && pos >= 0 && pos<=length){
                for(int i = length; i > pos; i--)
                    data[i] = data[i - 1];
                data[pos] = e;
                length++;
            }
            else{ error("포화상태 오류 또는 삽입 위치 오류\n"); }
        }

        void remove(int pos){
            if(!isEmpty() && pos >= 0 && pos < length){
                for(int i = pos + 1; i < length; i++)
                    data[i - 1] = data[i];
                length--;
            }
            else{error("공백상태 오류 또는 삭제 위치 오류\n");}
        }

        int getEntry(int pos){ return data[pos]; }

        bool isEmpty(){ return length == 0; }

        bool isFull(){ return length == MAX_LIST_SIZE; }

        bool find(int item){
            for(int i = 0; i < length ; i++){
                if(data[i] == item){ return true; }
            }
            return false;
        }
        
        void replace(int pos, int e) {
            if(!isEmpty() && pos >= 0 && pos < length){
                data[pos] = e;
            }
            else{error("공백상태 오류 또는 치환 위치 오류\n");}
        }

        int size(){ return length; }

        void display(){
            std::cout << "Array List의 총 항목 수: " << length;           
            for(int i = 0; i < length; i++)
                std::cout << " [" << data[i]<< "]";
            std::cout << "\n";
        }
        
        void clear(){ length = 0; }
};
