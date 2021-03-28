//Exception을 어떤 식으로 다루는지
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void swap(int &a, int &b){
    int tmp;
    if(a == b) throw a;
    
    tmp = a;
    a = b;
    b = tmp; //공대유머... 프로그래머 2명이 자리를 바꿔 앉으려면 의자는 몇 개 필요할까요? 
}


int main(void){
    int num = 1;
    try{
        if(num == 0){
            throw num;
        }
        cout << 2/num << "\n";
    }
    catch(int num){
        cout << num << " 은 올바르지 않은 분모입니다" << "\n";
    }


    try{
        int a = 3;
        int b = 3;
        swap(a, b);
    }
    catch(int val){
        cout << "두 값이 모두 " << val << "(으)로 같습니다" << "\n";
    }

    return 0;

}