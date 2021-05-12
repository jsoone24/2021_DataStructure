#include "includes/DArrayList.h"
#include <iostream>
#include <chrono>

int main(){   
    DArrayList list(10);
    for(int i = 0; i < 20; i++){
        list.insert(list.size(), i);
        if(i%10 == 9){
            list.display();
        }
    }
    
    for(int i = 0; i < 20; i++){
        list.remove(list.size()-1);
        if(i%10 == 9){
            list.display();
        }        
    }
    list.display();

    for(int i = 0; i < 100; i++){
        auto start = std::chrono::steady_clock::now();
        list.insert(list.size(), i);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns ";
    }
    std::cout << "\n";
    
    for(int i = 0; i < 100; i++){
        auto start = std::chrono::steady_clock::now();
        list.remove(list.size()-1);
        auto end = std::chrono::steady_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count() << " ns ";
    }
    
    list.clear();
    list.display();
    
    return 0;
}