//삼항연산자에 대해 알아봅시다
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
    //변수 = 조건 ? 참값 : 거짓값 형태로 씁니다
    int largerNum = (10 > 5) ? 10 : 5;
    cout << "Larger Number between 10 and 5 is :" << largerNum << endl;
}