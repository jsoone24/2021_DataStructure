// 를 통해서 C++ 에서 코멘트를 남길 수 있습니다.

/* 여러 줄의 코멘트를 남기려면
이러한 방식으로 여러 줄의 코멘트를 남길 수 있습니다.
*/

#include <iostream> // 외부 라이브러리를 #include를 통해서 불러옵니다
#include <vector>
#include <string>
#include <fstream>

using namespace std; //std namespace를 기본으로 사용합니다 (비추천?)

int main()  // 중요: 책에서 자꾸 void main()을 씁니다. 좋은 방법이 아니므로 저희는 int main()을 씁니다.
{                                  
    cout << "Hello World" << endl; // Hello World를 출력합니다.

    return 0;
}