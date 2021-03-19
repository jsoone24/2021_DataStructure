// 클래스를 공부해봅시다.
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Animal{
    private:
        int height; 
        int weight;
        string name;
        
        static int numberOfAnimals;
    public:
        int getHeight(){ return height; }
        int getWeight(){ return weight; }
        string getName(){ return name; }
        void setHeight(int newval){ height = newval; }
        void setWeight(int newval){ weight = newval; }
        void setName(string newval){ name = newval; }

        //void setAll(int, int, string);
        
        Animal(int, int, string); // 생성자
        ~Animal(); // 소멸자

        Animal();

        static int getNumAnimals(){ return numberOfAnimals; } 
        // 정적으로 정의되는 변수, 프로그램 전체에서 수명이 유지됩니다.
        void toString();
}; // 클래스 정의하고 세미콜론 찍는 것 잊지 마세요.

int Animal::numberOfAnimals = 0;
/*
void Animal::setAll(int height, int weight, string name){
    this -> height = height;
    this -> weight = weight;
    this -> name = name;
    Animal::numberOfAnimals++;
}*/ 

Animal::Animal(int height, int weight, string name){
    this -> height = height; // this는 자기 자신(즉 Animal class를) 나타내는 포인터입니다
    this -> weight = weight;
    this -> name = name;
    Animal::numberOfAnimals++;
}

Animal::~Animal(){
    cout << "Animal " << this -> name << " extincted" << "\n";
}

Animal::Animal(){
    Animal::numberOfAnimals++; 
}

void Animal::toString(){
    cout << "이 동물의 이름은 " << this -> name << "이고, 키는 " << this -> height << 
        "이며, 몸무게는 " << this -> weight << "입니다\n";
}

class Dog: public Animal{ //상속에 대해 배워봅시다.
    private:
        string sound = "멍멍";
    public:
        void doBark(){ cout << sound << endl; }
        Dog(int, int, string, string);
        Dog() : Animal(){};

        void toString(); 
}; // 클래스 정의하고 세미콜론 찍는 것 잊지 마세요.

Dog::Dog(int height, int weight, string name, string bark) : Animal(height, weight, name){
    this -> sound = bark;
}

void Dog::toString(){
     cout << "이 동물의 이름은 " << this -> getName() << "이고, 키는 " << this -> getHeight() << 
        "이며, 몸무게는 " << this -> getWeight() << "이며 " << this -> sound << "(이)라고 짖습니다.\n";
} // 함수 오버라이딩

int main(){
    Animal spider;
    spider.setHeight(60);
    spider.setWeight(20);
    spider.setName("peter parker");
    cout << "현재 동물 수를 조회합니다: " << Animal::getNumAnimals() << "\n";    
    cout << "이 동물의 이름은 " << spider.getName() << "이고, 키는 " << spider.getHeight() <<
        "이며, 몸무게는 " << spider.getWeight() << "입니다. 현재 동물의 총 수는" <<
        spider.getNumAnimals() << "입니다\n";
    Animal ant(5, 1, "Scott Lang");
    cout << "이 동물의 이름은 " << ant.getName() << "이고, 키는 " << ant.getHeight() <<
        "이며, 몸무게는 " << ant.getWeight() << "입니다. 현재 동물의 총 수는" <<
        ant.getNumAnimals() << "입니다\n";
    cout << "현재 동물 수를 spider로 조회합니다: " << spider.getNumAnimals() << "\n";
   
    Dog dog(40, 12, "mike", "왈왈");
    cout << "현재 동물 수를 조회합니다: " << Animal::getNumAnimals() << "\n";
    dog.doBark();
    spider.toString();
    dog.toString();
    dog.Animal::toString(); // 상위클래스의 methods를 그대로 쓸 수도 있습니다.

    return 0;
} // 프로그램이 소멸할 때 소멸자가 같이 불러져서 class도 사라집니다. 