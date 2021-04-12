#pragma once 
#include <iostream>
#include <typeinfo>
#include "Student.h"
// 사실 #pragma once 이게 표준은 아닙니다... 
// 근데 대부분의 컴파일러가 이 기능을 다 지원합니다. 
// 정석은 #ifndef ... #endif

#define MAX_STACK_SIZE 100

inline void error( const char* str ) { // 교과서 예제 코드에서 char* str 로 되어있습니다. 
    //C++ ISO 표준이 바뀌어서 이제 변수<->상수 암시적 변환이 안됩니다. 문자열 상수는 cosnt char*로 쓰세요.
    std::cerr << str << "\n"; // 에러의 경우는 std::cerr로 출력합니다.
    exit(1);
}; // inline: 인라인 함수는 함수를 호출하지 않고, 함수를 사용하는 
// 위치에 컴파일러가 코드 자체를 복사해줍니다 (그래서 라인 안에 들어가있다고 inline...)
// 더 빠르긴 한데... 흠흠...

template <typename T>
class ArrayStack{
    T data[MAX_STACK_SIZE]; // 요소의 배열
    int top; // 요소의 개수
    public:
        ArrayStack() { top = -1; }
        ~ArrayStack(){}
        bool isEmpty() { return top == -1; }
        bool isFull()  { return top == MAX_STACK_SIZE-1; }

        void push(T e){
            if(isFull()) error ("스택 포화 에러");
            data[++top] = e;
        }

        T pop(){
            if( isEmpty() ) error ("스택 공백 에러");
            return data[top--];
        }

        T peek(){
            if( isEmpty() ) error ("스택 공백 에러");
            return data[top];
        }

        void display(){ 
            std::cout << "[스택 항목의 수 = " << top+1 << "] \n";
            for (int i=0 ; i<=top ; i++)
                std::cout << "<" << data[i] << ">";
            std::cout << "\n";       
        }
}; 