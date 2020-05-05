//
// Created by Pop Rosian on 04/05/2020.
//

#ifndef POLISHPARSE_EXPRESSIONTREE_H
#define POLISHPARSE_EXPRESSIONTREE_H


#include "TreeNode.h"
#include "Stack.h"

class ExpressionTree {
    private:
        TreeNode* root; //A pointer to the root node.
        Stack* stack; //Each of the expression trees points to a stack.
    public:
        ExpressionTree(); //All of the methods are explained in the ExpressionTree.cpp file
        TreeNode* getRoot() const;
        Stack* getStack() const ;
        bool insert(TreeNode*);
        double eval(TreeNode*);

};


#endif //POLISHPARSE_EXPRESSIONTREE_H
