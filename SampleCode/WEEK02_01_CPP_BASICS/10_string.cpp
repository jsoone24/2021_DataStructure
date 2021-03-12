//C++의 string에 대해서 알아봅시다
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main(void)
{
    //STEP1: char와 string에 대해서
    char textArray[6] = "Happy"; // C의 방법 char array
    string textString = " Day!"; // C++식의 방법 string
    cout << textArray + textString << endl;

    string userName;
    cout << "당신의 이름을 알려주세요 "
         << "\n";
    getline(cin, userName);
    cout << "반갑습니다 " << userName << "\n";

    string sPi = "3.14";
    double pi = 3.14;

    if (stod(sPi) == pi)
    {
        cout << "Match!" << endl;
    }

    //STEP2: string의 내부 변수와 함수들
    cout << "String 의 크기 " << sPi.size() << "\n";
    cout << "String 이 empty인지 " << sPi.empty() << "\n";
    cout << "String append " << sPi.append("285") << "\n";

    string dogSound = "멍멍";
    string catSound = "야옹";

    cout << dogSound.compare(catSound) << "\n";
    cout << catSound.compare(dogSound) << "\n"; // 두 String에 따라서 + 나 -값이 리턴
    cout << catSound.compare(catSound) << "\n"; // 두 String이 같다면 0이 리턴

    //STEP3: 스트링의 복사
    string fullName = userName.assign(userName);
    cout << fullName << "\n";
    string firstName = fullName.assign(fullName, 0, 3);
    cout << "성은 " << firstName << "\n";

    int lastNameIdx = userName.find("Jin");
    cout << "이름은 " << lastNameIdx << "부터 있습니다"
         << "\n";

    userName.insert(lastNameIdx, "Professor ");
    cout << "새 이름은 " << userName << "\n";

    userName.erase(lastNameIdx, 10);
    cout << "새 이름은 " << userName << "\n";

    userName.replace(lastNameIdx, 8, "Man");
    cout << "새 이름은 " << userName << "\n";

    return 0;
}