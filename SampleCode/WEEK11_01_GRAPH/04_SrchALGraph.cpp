#include <iostream>
#include "includes/SrchALGraph.h"

int main(void){
	SrchALGraph g;
    g.load("./data/graph2.txt");
    std::cout << "그래프를 불러왔습니다 \n";
    g.display();

    std::cout << "DFS ==> ";
    g.resetVisited();
    g.DFS(0);
    std::cout << "\n";

    std::cout << "BFS ==> ";
    g.resetVisited();
    g.BFS(0);
    std::cout << "\n";
	
	return 0;
}