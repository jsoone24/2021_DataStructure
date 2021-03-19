#include <iostream>
#include <array>

// 2차원 영상에서 최대 밝기 값을 찾아 반환하는 함수
int findMaxPixel(int a[][5], int h, int w){
    int maxVal = 0;        // 영상의 최소 밝기 = 0
    for( int i=0 ; i<h ; i++ ){
        for( int j=0 ; j<w ; j++ ){
            if( maxVal < a[i][j] )
                maxVal = a[i][j];
        }
    }
    return maxVal;
}
// 정말 이상한 코드죠. 좌우 길이가 5 이상이면 쓸 수도 없고...

template<std::size_t x_size, std::size_t y_size>
int findMaxPixelSTD(std::array< std::array<int, x_size> , y_size> &a){
    int maxVal = 0;
    for(int i=0 ; i < x_size ; i++){
        for( int j=0 ; j< y_size ; j++ ){
            if( maxVal < a[i][j] )
                maxVal = a[i][j];
        }
    }
    return maxVal;
}
// 사실은 표준 자료형은 이렇게 2d로도 만들 수 있습니다

int main(){
    int img[4][5]= {
            { 3, 24, 82, 12, 22},
            { 34, 7, 12, 19, 21},
            { 99, 7, 65, 73, 58},
            { 20, 7,  9, 48, 29}};
    int maxPixel = findMaxPixel( img, 4, 5 );
    std::cout << "array 영상의 최대 밝기는: " << maxPixel << "\n";
    
    std::array<std::array<int, 5>, 4> s_img = {{
            { 3, 24, 82, 12, 22},
            { 34, 7, 12, 19, 21},
            { 99, 7, 65, 73, 58},
            { 20, 7,  9, 48, 29}}};
    //추가적인 괄호 한 개가 더 필요한 것에 유의하세요!
             
    int s_maxPixel = findMaxPixelSTD(s_img);
    std::cout << "std::array 영상의 최대 밝기는: " << s_maxPixel << "\n";
    return 0;
}