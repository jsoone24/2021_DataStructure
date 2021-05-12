#include "includes/ArrayList.h"
#include <chrono>

int main(){
    ArrayList list;

    list.insert(0, 10);
    list.insert(0, 20);
    list.insert(1, 30);
    list.insert(list.size(), 40);
    list.insert(2, 50);
    list.display();

    list.remove(2);
    list.remove(list.size() - 1);
    list.remove(0);
    list.replace(1, 90);
    list.display();

    list.clear();
    list.display();

    ArrayList list2;

    auto end = std::chrono::steady_clock::now();            
    auto start = std::chrono::steady_clock::now();
    for(int i = 0; i < 10000; i++){ 
        list2.insert(0, 0);     
        if(i % 1000 == 999){
            end = std::chrono::steady_clock::now();
            std::cout << i << "번째 삽입: ";
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns \n";
            start = std::chrono::steady_clock::now();
        }
    }

    start = std::chrono::steady_clock::now();
    for(int i = 0; i < 10000; i++){       
        list2.remove(0);        
        if(i % 1000 == 999){
            end = std::chrono::steady_clock::now();
            std::cout << i << "번째 삭제: ";
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns \n";
            start = std::chrono::steady_clock::now();
        }       
    }

    return 0;
}