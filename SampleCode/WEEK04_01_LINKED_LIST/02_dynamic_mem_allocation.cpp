#include <iostream>
#include <string>

int main(){
    char *str; //이 시점에서는 메모리가 할당이 안되어 있고
    str = new char [100000000000]; // char를 위한 메모리를 할당받습니다.
    // 자꾸 키우다보면 연속된 메모리 공간이 없어서 할당이 안되거나.
    // 혹은 아키텍쳐때문에 할당이 안되거나 합니다.
    
    if(str == nullptr){
        // 교과서에 자주 NULL이 나옵니다.
        // C++11에는 nullptr이라는 것이 추가되었습니다.
        // C++에서 NULL은 0L입니다 (0의 long int)
        // 그래서! int로 typecasting이 됩니다.
        // 그래서!! 발생하는 다양한 문제들이 있었... 습니다 (잘 기억이 안나요 사실)
        // 그래서!!! std::nullptr_t라는 별도의 자료형이 생겼습니다.
        std::cout << "Not enough memory. 할당되지 않았습니다 \n";
    }
    else{
        //do something
        std::cout << "메모리를 할당받았습니다 \n";
        delete [] str;
    }

    long long int *superlongint; 
    superlongint = new long long int [10000000000];
    // 자꾸 키우다보면 연속된 메모리 공간이 없어서 할당이 안되거나.
    // 혹은 아키텍쳐때문에 할당이 안되거나 합니다.
    
    if(superlongint == nullptr){
        std::cout << "Not enough memory. 할당되지 않았습니다 \n";
    }
    else{
        //do something
        std::cout << "메모리를 할당받았습니다 \n";
        delete [] superlongint;
    }    

    int *num;
    num = new int;
    
    if(num == nullptr){
        std::cout << "Not enough memory. 할당되지 않았습니다 \n";
    }
    else{
        //do something
        std::cout << "메모리를 할당받았습니다 \n";
        delete num;
    }    
    return 0;
}