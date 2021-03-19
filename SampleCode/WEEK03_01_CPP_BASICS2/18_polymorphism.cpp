// 다형성에 대해 배워봅시다
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class SuperHero{
    public: 
        virtual void shoutSound() { cout << "우리는 영웅입니다 \n"; }
}; // 클래스 뒤에 ; 잊지 맙시다.


class Avangers : public SuperHero{
    public: 
        void shoutSound() { cout << "우리는 어벤저스입니다 \n"; }
};

class JusticeLeague : public SuperHero{
    public:
        void shoutSound() { cout << "우리는 저스티스리그입니다 \n"; }
};

int main(){
    SuperHero* pIronman = new Avangers;
    SuperHero* pSuperman = new JusticeLeague;
    pIronman -> shoutSound();
    pSuperman -> shoutSound();
    // 이렇게 같은 SuperHero pointer를 통해shoutSound라는 함수를 호출했음에도 
    // 어떤 경우는 Avangers의 함수가, 어떤 경우는 JusticeLeage의 함수가 호출되지요. 
    // 이런 것을 다형성(polymorphism)이라고 부릅니다.    
    return 0;
} 