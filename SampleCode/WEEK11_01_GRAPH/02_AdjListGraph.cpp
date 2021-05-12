#include "includes/AdjListGraph.h"

int main(void){
	AdjListGraph g;

	g.load("./data/graph.txt");
	g.display();

	return 0;
}

