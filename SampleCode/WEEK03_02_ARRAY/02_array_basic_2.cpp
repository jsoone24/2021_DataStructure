#include <iostream>
#include <array>
#include <vector>
// 배열에서 최대값을 찾아 반환하는 함수

/*
약간 잡설일 수 있지만
변수의 이름을 정하는 몇 가지 방법이 있습니다
1. 카멜케이스 (lower 카멜케이스): lowerCamelCase 이런 형태로 씁니다
2. Upper 카멜케이스/파스칼케이스: UpperCamelCase 이런 형태로 씁니다
3. 스케이크케이스: snake_case 형태로 _를 활용해서 씁니다
4. 헝가리안 표기법: 변수 앞에 변수의 타입을 써 줍니다
   예를 들어서, char 면 chAaaBbb, double이면 dbAaaBbb, boolean이면 b 형태입니다
*/

int findMaxValue(int a[], int len){
    std::cout << a << "\n";
    int maxVal = a[0];
    for(int i=1 ; i<len ; i++){
        if( maxVal < a[i] ){
            maxVal = a[i];
        }
    }
    return maxVal;
} 
// 배열의 함수는 무조건 배열의 길이를 같이 받아야 합니다... 안타깝게도
// 배열의 길이를 나중에 확인하는 것은 불가능합니다.

template<std::size_t SIZE>
int findMaxValueSTD(std::array<int, SIZE> &a){
    int maxVal = a[0];
    for(int i = 1 ; i< a.size() ; i++){
        if( maxVal < a[i] ){
            maxVal = a[i];
        }
    }
    return maxVal;
}
//C++11이후에는 std::array라는 것이 있습니다.
//size를 같이 인수로 넘겨줄 필요가 없습니다.
//대신 template를 통해서 함수를 만들어야 합니다.

int findMaxValueVector(std::vector<int> &v){
    int maxVal = v[0];
    for(int i=1 ; i < v.size() ; i++){
        if( maxVal < v[i] ){
            maxVal = v[i];
        }
    }
    return maxVal;
} 

int main(){
    int arr[10] = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
    int maxVal = findMaxValue( arr, 10 );
    std::cout << "array의 최대 값은: " << maxVal << "\n";

    std::array<int, 10> s_arr = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
    int s_maxVal = findMaxValueSTD(s_arr);
    std::cout << "std::array의 최대 값은: " << s_maxVal << "\n";

    std::vector<int> v_arr = {3, 24, 82, 12, 34, 7, 53, 17, 26, 51};
    int v_maxVal = findMaxValueVector(v_arr);
    std::cout << "std::vector의 최대 값은: " << v_maxVal << "\n";

    return 0;
}