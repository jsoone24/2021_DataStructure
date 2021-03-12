// 사칙연산에 대해 배워봅시다
#include <iostream> // 외부 라이브러리를 #include를 통해서 불러옵니다
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
    cout << "8 + 3 = " << 8 + 3 << "\n";
    cout << "8 - 3 = " << 8 - 3 << "\n";
    cout << "8 * 3 = " << 8 * 3 << "\n";
    cout << "8 / 3 = " << 8 / 3 << "\n";
    cout << "8 % 3 = " << 8 % 3 << "\n"; // "\n" is bit faster than endl; in my experience.

    //STEP2 ++, -- 연산자

    int eight = 8;
    cout << "8++ = " << eight++ << " " << eight << "\n";
    cout << "++8 = " << ++eight << " " << eight << "\n";
    cout << "8-- = " << eight-- << " " << eight << "\n";
    cout << "--8 = " << --eight << " " << eight << "\n";

    //STEP3 += -= 연산자
    eight = 8;
    eight += 6; // eight = eight + 6;
    cout << "eight += 6 is " << eight << "\n";
    eight -= 6; // eight = eight - 6;
    cout << "eight -= 6 is " << eight << "\n";

    //STEP4 연산의 순서: * / 가 먼저, 그 다음이 + - (수학과 같습니다)
    cout << "1 + 2 - 3 * 4 = " << 1 + 2 - 3 * 4 << "\n";
    cout << "(1 + 2 - 3) * 4 = " << (1 + 2 - 3) * 4 << "\n";

    //STEP5 Typecast
    cout << "10 / 11 = " << 10 / 11 << "\n";
    cout << "10 / 11 = " << (float)10 / 11 << "\n";

    return 0;
}
