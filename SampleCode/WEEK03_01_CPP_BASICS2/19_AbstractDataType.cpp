// class로 데이터 타입을 만들어봅시다.
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Car{
    public: 
        virtual int getNumWheels() = 0;
        virtual int getNumDoors() = 0;
}; // 클래스 뒤에 ; 잊지 맙시다.


class SUV: public Car{
    public: 
        int getNumWheels(){ cout << "SUV의 바퀴는 4개입니다\n"; }
        int getNumDoors(){ cout << "SUV의 문은 5개입니다\n"; } 
};

int main(){
    Car* suv = new SUV();
    suv -> getNumDoors();
    return 0;
} 