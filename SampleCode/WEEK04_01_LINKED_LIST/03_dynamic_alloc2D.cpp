#include <iostream>

// 물론 지난 주에 Array를 할 때, std::array로 만드는 법을 보여드렸지요
// 그래도 동적할당 공부할 겸
int** alloc2DInt(int rows, int cols){ 
    // 동적할당으로 2차원 배열을 만듭니다.
    // 포인터의 포인터로 (**) 만듭니다.
    if(rows <= 0 || cols <= 0){
        return nullptr;
    }     
    int** mat = new int* [rows]; // int 포인터를 저장할 배열을 만듭니다.
    for (int i = 0 ; i < rows ; i++){ 
        mat[i] = new int [cols]; // 실제 각 행의 데이터를 저장할 배열을 만듭니다.
    }
    return mat;
}

void free2DInt(int **mat, int rows, int cols = 0){
    // 제대로 메모리 해제해주는 것을 잊으면 안됩니다.
    // 몇번이고 강조하지만, 이걸 해 주지 않으면 메모리 누수가 일어납니다
    // 프로그램이 돌아가면 돌아갈수록 가용메모리가 줄어드는 현상...
    if(mat != NULL){
        for(int i = 0 ; i < rows ; i++){
            delete [] mat[i]; // array를 지울 때는 delete [] 잊지마세요
        }
        delete [] mat;
    }
}

void set2DRandom(int **mat, int rows, int cols){
    for(int i = 0 ; i < rows ; i++){
        for(int j=0 ; j < cols ; j++){
            mat[i][j] = rand()%100; // 나머지 연산 잊으신 것은 아니죠?
        }
    }
} // 0부터 99까지 중 하나의 값으로 채웁니다.

void print2DInt(int **mat, int rows, int cols){
    std::cout << "행의 수 = " << rows << ",  열의 수 = " << cols << "\n";
    for (int i = 0; i < rows ; i++){
        for (int j = 0; j < cols; j++){
            std::cout << mat[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main(){
    int    **mat;
    int    rows, cols;
    std::cout << "행과 열의 크기를 입력하시오: ";
    std::cin >> rows >> cols;
    mat = alloc2DInt( rows, cols );
    set2DRandom( mat, rows, cols );
    print2DInt( mat, rows, cols );
    free2DInt( mat, rows, cols );
    return 0;
}