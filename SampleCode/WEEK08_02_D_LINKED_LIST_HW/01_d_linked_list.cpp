#include <iostream>
#include <string>
#include "includes/d_linked_list.h"

int main(){
    d_linked_list<int> list1;
    for(int i = 0; i < 5; i++){
        list1.push_front(i);
        list1.push_back(i);
        list1.insert_node_at(list1.size() - 1, i);
        list1.display_contents();
    }

    for(int i = 0; i < 5; i++){
        list1.pop_front();
    }
    list1.display_contents();

    for(int i = 0; i < 5; i++){
        list1.pop_node_at(list1.size() - 1);
    }
    list1.display_contents();

    for(int i = 0; i < 5; i++){
        list1.pop_back();
        list1.display_contents();
    }
    
    /*
    d_linked_list<std::string> list2;
    for(int i = 0; i < 5; i++){
        list2.push_front(std::to_string(i));
        list2.push_back(std::to_string(i));
        list2.insert_node_at(list2.size() - 1, std::to_string(i));
        list2.display_contents();
    }

    for(int i = 0; i < 5; i++){
        list2.pop_front();
    }
    list2.display_contents();

    for(int i = 0; i < 5; i++){
        list2.pop_node_at(list2.size() - 1);
    }
    list2.display_contents();

    for(int i = 0; i < 5; i++){
        list2.pop_back();
    }
    list2.display_contents();

    dll_deque<int> deque1;
    for(int i = 0; i < 5; i++){
        deque1.push_front(i);
        deque1.push_back(i);
    }
    deque1.display_contents();

    for(int i = 0; i < 5; i++){
        std::cout << deque1.deleteFront() << " ";
    }

    for(int i = 0; i < 5; i++){
        std::cout << deque1.deleteRear() << " ";
    }
    return 0;
    */
}
