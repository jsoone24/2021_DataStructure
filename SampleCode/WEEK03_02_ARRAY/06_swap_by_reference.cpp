#include <iostream>

void swap(int& x, int& y){
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}
// 지난 강의 시간에 했던 reference를 다시 한 번 짚어봅시다.

int main(){
    int a=1, b=2;
    std::cout << "변수1: " << a << ", 변수2: " << b << "\n";
    swap(a, b);
    std::cout << "변수1: " << a << ", 변수2: " << b << "\n";
    return 0;
}