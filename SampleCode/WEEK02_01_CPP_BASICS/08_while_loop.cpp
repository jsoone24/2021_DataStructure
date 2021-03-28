//for loop에 대해 알아봅시다.
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void){
    //STEP1: While loop를 실습해봅시다.
    int randNum = (rand() % 20) + 1; // 실제로는 더 좋은 (pseudo) random number generator를 써야합니다
    while (randNum != 20){ // 몇번을 계산해야 할 지 모를 때는 while을 씁니다.
        cout << randNum << " ";
        randNum = (rand() % 20) + 1;
    }
    cout << randNum << endl;

    //STEP2: While loop를 for 처럼 쓰려면?
    int idx = 0;
    while (idx < 10){
        cout << idx << " ";
        idx++;
    }
    //STEP3: do-while lopp를 다뤄봅시다.
    randNum = (rand() % 20) + 1;
    do{
        cout << randNum << " ";
        randNum = (rand() % 20) + 1;
    }
    while (randNum != 20); // do 문을 먼저 합니다. 
    return 0;
}