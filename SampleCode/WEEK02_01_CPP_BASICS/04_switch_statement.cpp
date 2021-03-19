//Switch에 대해서 알아봅시다.
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
    int guestLang = 3;
    switch (guestLang)
    {
    case 1:
        cout << "Hello!" << endl;
        break;

    case 2:
        cout << "Hola!" << endl;
        break;

    case 3:
        cout << "Ciao!" << endl;
        break;

    default:
        cout << "안녕하세요" << endl;
        break;
    }
    return 0;
}