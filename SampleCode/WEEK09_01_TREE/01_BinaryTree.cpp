#include <iostream>
#include "includes/BinaryNode.h"
#include "includes/BinaryTree.h"

int main(){
    BinaryTree tree;
    //            1
    //      2           3
    //  4       5   6        
    BinaryNode *d = new BinaryNode(4, nullptr, nullptr);
    BinaryNode *e = new BinaryNode(5, nullptr, nullptr);
    BinaryNode *b = new BinaryNode(2, d, e );
    BinaryNode *f = new BinaryNode(6, nullptr, nullptr);
    BinaryNode *c = new BinaryNode(3, f, nullptr);
    BinaryNode *a = new BinaryNode(1, b, c );
    tree.setRoot(a);

    std::cout << " 노드의 수: " << tree.getCount() << "\n";
    std::cout << " 노드의 수: " << tree.getLeafCount() << "\n";
    std::cout << " 노드의 수: " << tree.getHeight() << "\n";
    tree.inorder();
    std::cout << "\n";
    tree.preorder();
    std::cout << "\n";    
    tree.postorder();
    std::cout << "\n";
    tree.levelorder();

    BinaryTree tree2;
    //            +
    //      *           -
    //  3       2   5       6
    BinaryNode *n1 = new BinaryNode (3 , nullptr, nullptr);
    BinaryNode *n2 = new BinaryNode (2 , nullptr, nullptr);
    BinaryNode *n3 = new BinaryNode ('*', n1, n2 );
    BinaryNode *n4 = new BinaryNode (5 , nullptr, nullptr);
    BinaryNode *n5 = new BinaryNode (6 , nullptr, nullptr);
    BinaryNode *n6 = new BinaryNode ('-', n4, n5);
    BinaryNode *n7 = new BinaryNode ('+', n3, n6);
    tree2.setRoot(n7);
    std::cout << " 계산 결과: " << tree2.evaluate() << "\n";

    //          ROOT
    //     50          100
    //             200     500
    BinaryTree tree3;
    BinaryNode *m4 = new BinaryNode (200, nullptr, nullptr);
    BinaryNode *m5 = new BinaryNode (500, nullptr, nullptr);
    BinaryNode *m3 = new BinaryNode (100, m4, m5);
    BinaryNode *m2 = new BinaryNode (50, nullptr, nullptr);
    BinaryNode *m1 = new BinaryNode (0, m2, m3);
    tree3.setRoot(m1);
    std::cout << " 용량 계산 결과: " << tree3.calcSize() << "\n";
    return 0;
}