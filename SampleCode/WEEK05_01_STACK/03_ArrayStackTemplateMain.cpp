#include "includes/ArrayStackTemplate.h"
#include "includes/Student.h"

int main(){
    ArrayStack<double> stack;
    for(int i = 1; i < 10; i++){
        stack.push( i );
    }
    stack.display();
    stack.pop();
    stack.pop();
    stack.pop();
    stack.display();

    ArrayStack<Student> stack2;
    stack2.push(Student(2015130007, "홍길동", "컴퓨터공학과"));
    stack2.push(Student(2015130100, "이순신", "기계공학과"));
    stack2.push(Student(2015130135, "황희", "법학과"));
    stack2.display();
    stack2.pop();
    stack2.pop();
    stack2.pop();
    stack2.display();
    return 0;
}