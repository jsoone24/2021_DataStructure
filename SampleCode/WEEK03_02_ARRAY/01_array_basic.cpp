#include <iostream>
#define MAX_SIZE 10

void sub(int x, int arr[]){ // 배열을 파라미터로 받는 함수
    x = 10;
    arr[0] = 10;
    for(int i = 0; i < MAX_SIZE; i++){
        std::cout << &arr[i] << "\n";
    }//arr과 main의 list의 주소는 같습니다.
} 
//즉, 배열을 파라미터로 받으면 배열의 주소가 파라미터로 넘어갑니다.
//다시 말해, 배열의 이름은 "포인터"와 같은 역할을 합니다.

int main(){//메인함수
    int var;             
    int list[MAX_SIZE]; // 배열은 정해진 크기로만 초기화가 가능합니다.
    // 가변 길이로 쓰기 위해서는 C++의 표준 자료형중 <vector>를 쓰시면 됩니다.
    
    var = 0;
    list[0] = 0;            
    sub(var, list);
    std::cout << var << "\t" << list[0] << "\n"; 
    // var는 그대로 0이지만, list는 10이 되었습니다. 
    for(int i=0; i<MAX_SIZE; i++){
        std::cout << &list[i] << "\n";
    }

    double list2[MAX_SIZE];
    for(int i = 0; i < MAX_SIZE; i++){
        std::cout << &list2[i] << "\n";
    }
    return 0;
}

int score_student[80];