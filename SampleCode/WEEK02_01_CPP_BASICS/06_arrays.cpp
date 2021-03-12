//Array에 대해 알아봅시다.
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
    cout << "Your Number 2D 0, 2 : " << yourNumbers2d[0][2] << endl;

    int yourNumbers2d2[][5] = {{3, 4, 7, 6, 1},
                               {13, 14, 17, 16, 11}}; // 초기화 하는 경우에는 왼쪽 첨자는 생략가능
    cout << "Your Number 2D 0, 2 : " << yourNumbers2d2[0][2] << endl;

    int Array2D[3][5] = {0};
    cout << "Array2D 2,4 : " << Array2D[2][4] << endl;
}