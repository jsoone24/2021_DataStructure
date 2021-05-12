#pragma once
#include <iostream>

class ThreadedBinNode{
    protected:
        int data;
        ThreadedBinNode *left;
        ThreadedBinNode *right;
    public:
        bool  bThread;
        ThreadedBinNode(int val=0, ThreadedBinNode *l=nullptr, 
                        ThreadedBinNode *r=nullptr, bool bTh=false)
                        :data(val), left(l), right(r), bThread(bTh){}
        int getData(){
            return data;
        }
        void setRight(ThreadedBinNode *r) {
            right= r;
        }
        ThreadedBinNode* getLeft(){
            return left;
        }
        ThreadedBinNode* getRight(){
            return right;
        }
};

class ThreadedBinTree{
    private:
        ThreadedBinNode* root;
    public:
        ThreadedBinTree(): root(nullptr){}
        ~ThreadedBinTree() {}

        void setRoot(ThreadedBinNode* node){
            root= node;
        }
        ThreadedBinNode* getRoot(){
            return root;
        }
        bool isEmpty(){
            return root==nullptr;
        }
        void threadedInorder(){
            if(!isEmpty()) {
                std::cout << "스레드 이진 트리 중위순회: ";
                ThreadedBinNode *q = root;
                while(q->getLeft())
                    q = q->getLeft(); // 가장 왼쪽 노드로 이동합니다
                
                do{
                    std::cout << " [" << q->getData() << "]"; // 데이터를 출력하고
                    q = findSuccessor(q); // 후속자를 불러옵니다
                }while(q);
                std::cout << "\n";
            }
        }
        ThreadedBinNode* findSuccessor(ThreadedBinNode* p){ 
            ThreadedBinNode *q = p->getRight(); // 오른쪽 자식 포인터를 저장
            if(q==nullptr || p->bThread){
                // 오른쪽 자식이 nullptr 이거나 스레드이면 오른쪽 포인터를 반환
                return q;
            }
            while(q->getLeft() != nullptr){
                // 만약 오른쪽 자식이 존재하면 다시 가장 왼쪽 노드로 이동
                q = q->getLeft();
            }
            return q;
        }
};