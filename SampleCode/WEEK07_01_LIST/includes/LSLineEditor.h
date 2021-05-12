// Line Editor
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "LineHnSLinkedList.h" 
// 되도록 라이브러리의 종류에 따라 묶는게 좋습니다.

class LineEditor : public l_hn_s_linked_list{
    public:
        void Display(std::ostream *os);
        void InsertLine();
        void DeleteLine();
        void ReplaceLine();
        void LoadFile(std::string fname);
        void SaveFile(std::string fname);
};

void LineEditor::Display(std::ostream *os = &std::cout){
    int i=0;
    for(node *p = getHead(); p != nullptr; p=p->getLink(), i++) { 
        // for 문은 , 을 통해서 여러가지 증가 조건을 동시에 실행시킬 수 있습니다.
        // 여기서는 i를 증가시킴과 동시에 p의 다음 노드를 불러옵니다.
        std::cerr<< i << " ";
        p->display(os);
    }
}

void LineEditor::InsertLine(){
    int position;
    std::string line;
    std::cout << "  입력행 번호: ";
    std::cin >> position;
    std::cin.sync();
    std::cin.clear();
    std::cout << "  입력할 내용: ";
    getline(std::cin, line);
    insert(position, new node(line));
} 
// 현재 한국어에 대해 제대로 작동하지 않습니다. 
// 제가 나중에 시간날 때 조금 더 들여다보죠...

void LineEditor::DeleteLine(){
    int position;
    std::cout << "  삭제행 번호: ";
    std::cin >> position;
    remove(position);
}

void LineEditor::ReplaceLine(){
    int position;
    std::string line;
    std::cout << "  변경행 번호: ";
    std::cin >> position;
    std::cin.sync(); // 버퍼에 남아있는 개행문자를 처리해줍니다
    std::cin.clear(); 
    std::cout << "  변경할 내용 : ";
    getline(std::cin, line);
    replace(position, new node(line));
}
// 이것도 현재 한국어에 대해 제대로 작동하지 않습니다. 
// 제가 나중에 시간날 때 조금 더 들여다보죠...
// cin의 문제보다는 windows의 인코딩 문제같은데... 

void LineEditor::LoadFile(std::string fname){
    std::ifstream ifs(fname);
    std::string line;
    while(std::getline(ifs, line)){       
        insert(size(), new node(line));
    }
    ifs.close();
}
// 이건 한국어에 대해서도 제대로 작동합니다

void LineEditor::SaveFile(std::string fname) {
    std::ofstream ofs(fname);
    if(ofs.good()){
        Display(&ofs);
        ofs.close();
    }
}