#pragma once
#include "ArrayStackTemplate.h"
#include <string>
#include <sstream>
#include <iostream>
// 이런 수식에서 string을 넘겨주는게 사실 비효율적인 방법인긴 한데요
// 교과서에서 두 개를 따로 구현하는걸 보여주기도 했고
// 두 개 다 stack을 쓰는 좋은 예라서 그냥 이렇게 하겠습니다 ^^; 

double calcPostfixExpr(){ // 파라미터 입력이 없는 경우는 키보드에서 받습니다
    // Postfix 계산기
    char c;
    double val;
    ArrayStack<double> st;
    while(std::cin.get(c) && c != '\n'){
        if( c=='+' || c=='-' || c=='*' || c=='/' ){
            double val2 = st.pop();
            double val1 = st.pop();
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
        else if (c>='0' && c<='9') { // 만나는 글자를 
            std::cin.unget(); // 
            std::cin >> val; // 공백 전 까지의 값을 double로 받습니다
            st.push(val);
        }
    }
    return (st.pop());
}

double calcPostfixExpr(std::string str){ // 파라미터 입력이 있는 경우
    // Postfix 계산기
    std::istringstream iss(str);
    char c;
    double val;
    ArrayStack<double> st;
    while(iss.get(c) && c != '\n'){
        if( c=='+' || c=='-' || c=='*' || c=='/' ){
            double val2 = st.pop();
            double val1 = st.pop();
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
            }
        }
        else if (c>='0' && c<='9') {        
            iss.unget();
            iss >> val;
            st.push(val);
        }
    }
    return (st.pop());
}

inline int priority(char op){
    switch(op){
        case '(' : case ')' : return 0; 
        case '+' : case '-' : return 1;
        case '*' : case '/' : return 2;
    }
    return -1;
}

std::string infix2Postfix(){ // 파라미터 입력이 없는 경우는 키보드에서 받습니다
    // infix 수식을 postfix로 바꾸는 변환기
    char c, op;
    double val;
    std::ostringstream oss;
    ArrayStack<char> st;
    while(std::cin.get(c) && c != '\n'){
        if ((c>='0' && c<='9')) {
            std::cin.unget(); // 
            std::cin >> val; // 공백 전 까지의 값을 double로 받습니다
            oss << val << " ";
        }

        else if(c=='('){
            st.push( c );
        }
        else if(c==')') {
            while(!st.isEmpty()) {
                op = st.pop();
                if( op== '(' ) break;
                else oss << op << " ";
            }
        }

        else if(c=='+' || c=='-' || c=='*' || c=='/'){
            while(!st.isEmpty()) {
                op = st.peek();
                if (priority(c) <= priority(op)){
                    oss << op << " ";
                    st.pop();
                }
                else break;
            }
            st.push(c);
        }
    }
    while (!st.isEmpty()){
        oss << st.pop() << " ";
    }
    return oss.str();
}

std::string infix2Postfix(std::string istr){ // 파라미터 입력이 없는 경우는 키보드에서 받습니다
    // infix 수식을 postfix로 바꾸는 변환기
    char c, op;
    double val;
    std::ostringstream oss;
    std::istringstream iss(istr);
    ArrayStack<char> st;
    while(iss.get(c) && c != '\n'){
        if ((c>='0' && c<='9')) {
            iss.unget(); // 
            iss >> val; // 공백 전 까지의 값을 double로 받습니다
            oss << val << " ";
        }

        else if(c=='('){
            st.push( c );
        }
        else if(c==')'){
            while (!st.isEmpty()) {
                op = st.pop();
                if( op== '(' ) break;
                else oss << op << " ";
            }
        }

        else if(c == '+' || c=='-' || c=='*' || c=='/'){
            while(!st.isEmpty()){
                op = st.peek();
                if (priority(c) <= priority(op)) {
                    oss << op << " ";
                    st.pop();
                }
                else break;
            }
            st.push( c );
        }
    }
    while(!st.isEmpty()){    
        op = st.peek();
        oss << st.pop() << " ";
    }
    return oss.str();
}