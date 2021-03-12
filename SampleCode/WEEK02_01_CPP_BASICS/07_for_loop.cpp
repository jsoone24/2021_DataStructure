//for loop에 대해 알아봅시다.
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{

    //STEP1: 1D array
    int myNumbers[5];
    int yourNumbers[5] = {3, 4, 7, 6, 1};
    cout << "Your Number 1: " << yourNumbers[0] << endl;

    //STEP2: 2D array
    int yourNumbers2d[2][5] = {{3, 4, 7, 6, 1},
                               {13, 14, 17, 16, 11}}; // 5개 항목이 있는 Array를 2개 가진 Array

    for (int i = 1; i <= 10; i++)
    { // loop는 보통 몇번 iteration을 해야 할 지 미리 알 때 사용합니다.
        cout << i << endl;
    }

    for (int j = 0; j < 2; j++)
    {
        for (int k = 0; k < 5; k++)
        { // nested loop.
            cout << yourNumbers2d[j][k] << " ";
        }
        cout << "\n";
    }

    return 0;
}