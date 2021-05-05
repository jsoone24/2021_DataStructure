//	06장-TextEditor.cpp: 라인 에디터 프로그램
#include "includes/LSLineEditor.h"
#include <iostream>
#include <limits>

void Usage(){
    std::cout << "[메뉴선택] i-입력, d-삭제, r-변경, p-출력, l-파일읽기, s-저장, q-종료=> ";
}

int main(){
    LineEditor editor;
    char command;
    do{
        Usage();
        command = std::getchar();
        std::cin.sync(); // 버퍼에 남아있는 개행문자를 처리해줍니다
        switch(command) {
            case 'd': 
                editor.DeleteLine();
                break;
            case 'i': 
                editor.InsertLine();
                break;
            case 'r': 
                editor.ReplaceLine(); 
                break;
            case 'l': 
                editor.LoadFile("test.txt");
                break; 
            case 's': 
                editor.SaveFile("test.txt");
                break;
            case 'p': 
                editor.Display();
                break;
            case 'q':
                break;
        }
        // fflush(stdin): 비표준입니다. GCC에서는 작동하지 않습니다.        
    } while(command != 'q');
    return 0;
}