//
// Created by Pop Rosian on 04/05/2020.
//

#include "ExpressionTree.h"
#include <iostream>
ExpressionTree::ExpressionTree() { //Making the root of the tree null and creating a stack for the expression tree.
    this->root = nullptr;
    this->stack = new Stack();
}

TreeNode *ExpressionTree::getRoot() const { //Getter
    return this->root;
}

Stack *ExpressionTree::getStack() const { //Getter
    return this->stack;
}
//The insert function takes a TreeNode. The tree node we get from this function is given by the pop() method from the stack.
bool ExpressionTree::insert(TreeNode * node) {
    if(this->root == nullptr){ //If the root doesn't exist yet, make the current node the root.
        this->root = node;
    } else {
        Node* top = this->stack->getTop(); //Top is just a pointer to the top of the stack.
        if(top == nullptr){ //If the top is a null pointer, cancel the insertion.
            return false;
        }
        TreeNode* next = top->getData(); //The stack always contains operators. The top of the stack is always the next operator.
        if(next->getLeft() == nullptr){ //Now that we have the tree node from the stack, we check if it's left child is there.
            next->setLeft(node); //If it's not, set the node to be inserted as the left child of the operator.
        } else if (next->getRight() == nullptr){ //If a left child exists, insert it as the right child.
            next->setRight(node);
            this->stack->pop(); //Now we also pop the top element on the stack as now it already had two children.
        } else {
            return false;
        }
    }
    return true;
}

double ExpressionTree::eval(TreeNode *root) { //Recursive function to go through the tree post-order.
    if (root == nullptr){
        return 0;
    }
    double l = eval(root->getLeft()); //Going on the left and right of the tree
    double r = eval(root->getRight());
    char token = root->getToken(); //Getting the token.
    double val;
    if(token >= '0' and token <= '9'){ //If the token is a digit.
        val = token - '0'; //By subtracting '0' from a character digit, we get it's actual value.
    } else {
        switch (token) { //If the token is not a digit, we just switch and find what operand it is, then do the operation.
            case '+':
                val = l+r;
                break;
            case '-':
                val = l-r;
                break;
            case '/':
                val = l/r;
                break;
            case '*':
                val = l*r;
                break;
            default:
                break;
        }
    }
    root->setVal(val); //Finally, setting the value of the root
    return val; //And then finally returning the value.
}

