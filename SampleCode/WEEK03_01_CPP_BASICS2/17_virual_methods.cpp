// 가상함수에 대해 배워봅시다.
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class SuperHero{
    public: 
        void getFamily() { cout << "우리는 영웅입니다" << "\n"; }
        // virtual void getClass() { cout << "나는 영웅입니다" << "\n"; }
        void getClass() { cout << "나는 영웅입니다" << "\n"; }
        // 주의점 "하위변수와 상위변수 함수의 꼴이 정확히 같아야지만 이 가상함수가 사용 가능합니다"
}; // 클래스 뒤에 ; 잊지 맙시다.


class Avangers : public SuperHero{
    public: 
        void getClass() { cout << "나는 어벤저스입니다" << "\n"; } // 함수 오버라이딩
};

class Ironman : public Avangers{
    public:
        void getClass() { cout << "나는 아이언맨입니다" << "\n"; }
        void getDerived() { cout << "나는 영웅이며 어벤저스입니다" << "\n"; }
};

void whatIsMyClass(SuperHero *superhero){
    superhero -> getClass();
} 


int main(){
    SuperHero *superhero = new SuperHero;
    Avangers *avangers = new Avangers;

    superhero -> getClass();
    avangers -> getClass(); // 이 경우는 virtual과 아닌 것에 아무 차이가 없습니다.
    whatIsMyClass(superhero);
    whatIsMyClass(avangers); 
    // virtual인 경우는 avangers의 함수가 제대로 호출되지만, 
    // 아니라면 superhero의 함수가 호출됩니다.
    // virtual 키워드는 컴파일 때는 어떤 함수가 불러질 지 정하지 하지 않고, 실행할때에 정하게 합니다.
    // 이런 것을 동적 바인딩(dynamic binding) 이라고 부릅니다.
    // 이 경우에는 SuperHero의 getClass를 실행할지, 아니면 Avangers의 getClass를 실행할지 나중에 결정합니다.

    Avangers spiderman;
    Ironman suit_mark1;
    Avangers *pSpiderman = &spiderman;
    Avangers *pIronman = &suit_mark1;

    pSpiderman -> getFamily();
    pSpiderman -> getClass();
    
    pIronman -> getFamily();
    pIronman -> getClass();
    return 0;
} 