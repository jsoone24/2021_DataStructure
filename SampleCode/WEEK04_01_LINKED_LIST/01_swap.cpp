#include <iostream>
void pswap(int* px, int* py) { // 포인터로 swap 해 봅시다
    int tmp;
    tmp = *px;
    *px = *py;
    *py = tmp;
}

void rswap(int& x, int& y){ // 레퍼런스로 swap 해 봅시다
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

int main(){
    int a=1, b=2;
    std::cout << "Before swap: " << a << " " << b << "\n";
    pswap(&a, &b);
    std::cout << "After swap: " << a << " " << b << "\n";

    std::cout << "Before swap: " << a << " " << b << "\n";
    rswap(a, b);
    std::cout << "After swap: " << a << " " << b << "\n";

    void (*p_rswap)(int&, int&);
    p_rswap = rswap; // 함수의 주소를 가지는 포인터도 있습니다.

    std::cout << "Before swap: " << a << " " << b << "\n";
    (*p_rswap)(a, b);
    std::cout << "After swap: " << a << " " << b << "\n";    
    return 0;
}