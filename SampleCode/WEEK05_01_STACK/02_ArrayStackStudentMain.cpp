#include "includes/ArrayStackStudent.h"

int main(){
    StudentStack stack;
    stack.push(Student(2015130007, "홍길동", "컴퓨터공학과"));
    stack.push(Student(2015130100, "이순신", "기계공학과"));
    stack.push(Student(2015130135, "황희", "법학과"));
    stack.display();
    stack.pop();
    stack.display();
    return 0;
}