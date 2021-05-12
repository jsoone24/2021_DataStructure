#include "includes/TopoSortGraph.h"

int main(void){
	TopoSortGraph g;

	for(int i = 0; i < 6; i++){
        g.insertVertex(std::string(1, 'A' + i));
	}

	g.insertDirEdge(0, 2);
	g.insertDirEdge(0, 3);

	g.insertDirEdge(1, 3);
	g.insertDirEdge(1, 4);

	g.insertDirEdge(2, 3);
	g.insertDirEdge(2, 5);

	g.insertDirEdge(3, 5);

	g.insertDirEdge(4, 5);

	std::cout << "Topology Sort:\n";

	g.TopoSort();
	
	return 0;
}

