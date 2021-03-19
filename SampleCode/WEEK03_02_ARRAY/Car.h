#pragma once
#include <iostream>
#include <string>
// #pragma once는 de facto 아무 문제 없이 쓰고 있긴 한데요.
// 사실은 정석은 #ifndef ... #endif로 하는게 표준입니다.
// 컴파일러에 따라 작동하지 않을 수도 있습니다.
// 다만 #pragma가 미묘하게 더 빨라요... 

class Car {
    protected:
        int speed; // 속도 (protectecd)
        std::string name; // 이름 (protected)
    public:
        int gear; 
        // 기어 (public). 예제니 이리 잡습니다만
        // 변수는 왠만하면 private/protected
        Car(){ } // 생성자
        ~Car(){ } // 소멸자
        Car(int s, std::string n, int g)
            : speed(s), gear(g) {
                name = n; 
        } // 생성자 (초기화 하면서)
        void changeGear(int g = 4){ // 파라미터가 없으면 기본으로 g를 4로 둡니다
            gear = g;
        } 
        void speedUp(){    
             speed += 5;
        }
        void display(){    
            std::cout << name << ", 기어: " << gear;
            std::cout << "단, 속도 : " << speed << "\n";
        }
        void whereAmI() {
            std::cout << this << "\n"; 
        }
};