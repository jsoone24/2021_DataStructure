//for loop에 대해 알아봅시다.
#include <iostream> 
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void){
    //STEP1: While loop를 실습해봅시다.
    string yourAnswer;
    int intYourAnswer;

    do{
        cout << "1부터 10까지 숫자 중 하나를 맞춰보세요 ";
        getline(cin, yourAnswer);
        intYourAnswer = stoi(yourAnswer); // stoi : string to integer
    }
    while (intYourAnswer != 6);
    return 0;
}