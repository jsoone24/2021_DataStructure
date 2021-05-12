#include <iostream>
#include "includes/ConnectedComponentGraph.h"

int main(void){
	ConnectedComponentGraph g;
	
	for(int i = 0; i < 5; i++){
        g.insertVertex(std::string(1, 'A' + i));
	}
	g.insertEdge(1,0);
	g.insertEdge(2,0);
	g.insertEdge(3,4);
    g.store( "./data/graph3.txt" );
	std::cout << "Connected Component Test";
	g.display();

	g.resetVisited();
	g.findConnectedComponent();

	return 0;
}