#include <iostream>
#include <string>
#include "includes/AdjMatGraph.h"

int main(void){
    AdjMatGraph g;
    for(int i = 0; i < 4; i++){
        g.insertVertex(std::string(1, 'A' + i));
    }
    g.insertEdge(0,1);
    g.insertEdge(0,3);
    g.insertEdge(1,2);
    g.insertEdge(1,3);
    g.insertEdge(2,3);
    g.display();
    g.store("./data/graph.txt");
    std::cout << "Graph saved \n";
    g.reset();
    std::cout << "Graph reset \n";
    g.load("./data/graph.txt");
    std::cout << "Graph loaded \n";
    g.display();

    return 0;
}