#pragma once
#include <iostream>
#include <string>

class Student{
    int    id; // 학번
    std::string name; // 이름
    std::string dept; // 소속 학과
    public:
        Student(int i=0, std::string nam="", std::string dep=""){ 
            set(i, nam, dep);
        }
        void set(int i, std::string nam, std::string dep) {
            id = i;
            name = nam;
            dept = dep;
        }
        void display(){
            std::cout << "학번: " << id << " 성명: " << name << " 학과: " << dept << "\n";
        }

        std::string contents(){
            std::string str;
            str = "학번 :" + std::to_string(id) + " 성명:" + name + " 학과 : " + dept;
            return str;
        }
        friend std::ostream& operator<<(std::ostream& os, Student& st);    // 연산자 오버로딩
};

std::ostream& operator<<(std::ostream& os, Student& st){
    os << st.contents();
    return os;
}