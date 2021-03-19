//논리연산에 대해 배워봅시다 (if-else statement)
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
    // ==, !=, >, <, >=, <=
    // && (and), || (or), ! (not)

    int age = 40;
    int ageLastTest = 16;
    bool isNotDrunk = true;
    if ((age >= 1) && (age < 20))
    {
        cout << "20세 미만 운전할 수 없습니다"
             << "\n";
    }
    else if (!isNotDrunk)
    {
        cout << "술을 마시면 운전할 수 없습니다"
             << "\n";
    }
    else if ((age >= 80) && ((age > 100) || ((age - ageLastTest > 5))))
    {
        cout << "고령자는 테스트 없이 운전할 수 없습니다"
             << "\n";
    }
    else
    {
        cout << "운전하셔도 됩니다"
             << "\n";
    }
    return 0;
}