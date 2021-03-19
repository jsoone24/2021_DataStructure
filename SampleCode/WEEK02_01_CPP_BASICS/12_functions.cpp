//C++의 함수에 대해 알아봅시다
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int multiplyNumbers(int numOne, int numTwo = 1)
{
    int resultValue = numOne * numTwo;
    return resultValue;
}

int multiplyNumbers(int numOne, int numTwo, int numThree)
{
    int resultValue = numOne * numTwo * numThree;
    return resultValue;
}

int getFactorial(int num)
{ // 재귀함수 (recursive function): 자신을 다시 호출해서 결과를 내는 함수
    int fac;
    if (num == 1)
    {
        fac = 1;
    }
    else
    {
        fac = getFactorial(num - 1) * num;
    }
    /*
    if(num==1) fac = 1;
    else fac = getFactorial(num - 1) * num; 단순한 조건문은 이런 식으로 한 줄로 표현해도 됨.
    */
    return fac;
}

int main(void)
{

    cout << multiplyNumbers(1) << "\n";
    cout << multiplyNumbers(1, 3) << "\n";
    cout << multiplyNumbers(1, 3, 5) << "\n";
    cout << "Factorial of 3 is " << getFactorial(3) << "\n";
    return 0;
}