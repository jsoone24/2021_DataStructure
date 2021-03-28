//포인터와 레퍼런스에 대해서 이야기해봅시다.
//자료구조 과목을 진행하는데 가장 중요한 문법일 수 있습니다.
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int change_val(int *p) { // function for 2nd STEP, 포인터 *p를 통해 number를 조회합니다.
    *p = 3;
    return 0;
}

int change_val2(int &p) { // function for 2nd STEP, 참조자(레퍼런스)를 통해서 조회합니다.
    p = 3;
    return 0;
}

// function for 4th step, 참조자를 return합니다. 
// int return_ref1(int &a) { return a; } //이 형태는 작동이 안됩니다.
int *return_ref2(int &a) { return &a; } // 하지만 이 형태는 됩니다.

int main(){
    int myAge = 100;
    char myGrade = 'A';

    cout << "Size of int" << sizeof(myAge) << "\n"; // 아마도 4바이트
    cout << "Size of char" << sizeof(myGrade) << "\n"; // 아마도 1바이트

    cout << "변수 myAge는 메모리의 어디에 있는가? " << &myAge << "\n"; // &: 레퍼런스, 참조자

    int* agePointer = &myAge;
    cout << "agePointer는 메모리의 어디를 참조하는가? " << agePointer << "\n"; 
    cout << "여기에는 무슨 값이 있는가? " << *agePointer << "\n"; 

    // STEP2: 참조자 이해하기
    int number = 5;
    cout << number << "\n";
    change_val(&number); // 참조자를 사용해 함수의 인자 p에 number의 주소값을 전달합니다.
    cout << number << "\n";

    number = 5;
    cout << number << "\n";
    change_val2(number); // 참조자를 사용해 함수의 인자 p에 number의 주소값을 전달합니다.
    cout << number << "\n";

    number = 10;
    int& ref = number; // 레퍼런스 정의는 이렇게 합니다. Reference는 NULL로 정의할 수 없습니다
    // 다시말해서 int &ref; 이런 형태로 정의는 못 합니다.
    int* p = &number;

    cout << ref << " " << &ref << "\n";
    ref++; 
    cout << ref << " " << &ref << "\n"; // 참조자의 연산은 값을 바꿉니다!
    cout << number << "\n"; // 원래 number의 값도 바뀌어 있습니다.

    cout << p << " " << *p << "\n";
    p++; // 참고, int의 크기가 4bytes이므로, 주소값도 4만큼 옮겨갑니다.
    cout << p << " " << *p << "\n"; // 포인터의 연산은 포인터가 가르키고있는 메모리 주소 자체를 바꿉니다
    cout << number << "\n"; // 원래 number의 값은 그대로입니다.

    // STEP3: Use reference wherever you can, pointers wherever you must.    
    int x;
    int& y = x;
    int& z = y; // int& y = x; 가 존재하므로, 사실 참조자 개념에서 int& z = x;와 이 할당은 의미가 같습니다.
    x = 1;
    cout << "x : " << x << " y : " << y << " z : " << z << "\n";
    y = 2;
    cout << "x : " << x << " y : " << y << " z : " << z << "\n";
    z = 3;
    cout << "x : " << x << " y : " << y << " z : " << z << "\n"; 
    // 즉, x, y, z 중 어느 것을 바뀌어도 x의 값이 바뀝니다.
    // 포인터였다면 y는 x를 가리키는 포인터, z는 y를 가리키는 포인터의 포인터... 겠죠
    // 즉 포인터의 연산보다 참조자의 연산이 훨! 씬! 간편합니다.

    // STEP3: Array of References, Reference of an Array

    /* 아래 형태로 정의할 수 없습니다 (중요)
    int a, b;
    int& arr[2] = {a, b}; 
    ISO 규격에 이런 말이 나와있죠. 
    There shall be no references to references, no arrays of references, and no pointers to references. 
    The declaration of a reference shall contain an initializer (8.5.3)
    */

    int arr2[3] = {1, 2, 3}; 
    int(&ref2)[3] = arr2; // Reference of Array는 가능합니다. 
    // 다만 포인터는 int *p 하나로 모든 1차원 배열들을 가리킬 수 있지요. 이 경우는 포인터가 더 편합니다.
    ref2[0] = 1;
    ref2[1] = 2;
    ref2[2] = 3;
    cout << ref2[0] << ref2[1] << ref2[2] << "\n";

    int arr3[2][3] = {1, 2, 3, 4, 5, 6};
    int (&ref3)[2][3] = arr3;
    cout << ref3[0][0] << ref3[0][1] << ref3[0][2] << "\n";
    cout << ref3[1][0] << ref3[1][1] << ref3[1][2] << "\n";

    // STEP 4: 레퍼런스를 리턴하는 함수가 가능할까요?
    // x = 1;
    // cout << return_ref1(x)++ << "\n";
    // cout << "x :: " << x << "\n"; return_ref1은 안됩니다

    x = 1;
    cout << return_ref2(x)++ << "\n"; // return_ref2의 내부에서 a는 x의 레퍼런스, 리턴도 레퍼런스를 합니다.
    cout << "x :: " << x << "\n"; // 결국 return_ref2(x)++ 라는 것은 x++과 동일해집니다.
    // C라면 많이 귀찮겠죠. x의 포인터를 리턴하고, 그걸 받아서 역참조하고, (*)++로 증가연산하고.
    // 레퍼런스 덕에 C++이 C보다는 많이 편리합니다... (하지만 python같은 요즘 언어에 비해서는...)

    return 0;

}