//
// Created by Pop Rosian on 04/05/2020.
//

#ifndef POLISHPARSE_STACK_H
#define POLISHPARSE_STACK_H


#include "Node.h"

class Stack {
    private:
        Node* top; //Pointer to the node that's on top of the stack.
        Node* bottom; //Pointer to the lowest node on the stack
        int size; //Size of the stack.
    public:
        Stack(); //Methods are explained better in Stack.cpp
        Node* getTop() const;
        void push(TreeNode*);
        bool isEmpty() const;
        TreeNode* pop();

};


#endif //POLISHPARSE_STACK_H
