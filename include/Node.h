//
// Created by Pop Rosian on 04/05/2020.
//

#ifndef POLISHPARSE_NODE_H
#define POLISHPARSE_NODE_H


#include "TreeNode.h"

class Node {
    private:
        TreeNode* data; //Each stack node holds a value, these nodes hold a pointer to a TreeNode.
        Node* next; //Each node of the stack holds a reference to the next node in the stack.
    public:
        explicit Node(TreeNode*); //Getters and setters for the stack node.
        TreeNode* getData() const;
        void setNext(Node* );
        Node* getNext() const;
};


#endif //POLISHPARSE_NODE_H
