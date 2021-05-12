#include "includes/ThreadedBinTree.h"

int main(){
	ThreadedBinTree tree;
    //            7
    //      3           6
    //  1       2   4	    5
	ThreadedBinNode *n1 = new ThreadedBinNode (1, nullptr, nullptr, true);
	ThreadedBinNode *n2 = new ThreadedBinNode (2, nullptr, nullptr, true);
	ThreadedBinNode *n3 = new ThreadedBinNode (3, n1, n2, false);
	ThreadedBinNode *n4 = new ThreadedBinNode (4, nullptr, nullptr, true);
	ThreadedBinNode *n5 = new ThreadedBinNode (5, nullptr, nullptr, false);
	ThreadedBinNode *n6 = new ThreadedBinNode (6, n4, n5, false);
	ThreadedBinNode *n7 = new ThreadedBinNode (7, n3, n6, false);
	tree.setRoot(n7); 
	// 스레드 설정 
	n1->setRight(n3);
	n2->setRight(n7);
	n4->setRight(n6);

	tree.threadedInorder();
	return 0;
}