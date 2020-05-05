//
// Created by Pop Rosian on 04/05/2020.
//

#ifndef POLISHPARSE_TREENODE_H
#define POLISHPARSE_TREENODE_H


class TreeNode {
    private:
        double val; //The value of the tree node, it's used to compute the final value
        char token; //The token, the token holds either the operator or operand
        TreeNode* left; //Left child
        TreeNode* right; //Right child
    public:
        explicit TreeNode(char); //Getters and setters for the nodes to access the private variables.
        char getToken() const;
        void setToken(char);
        void setLeft(TreeNode*);
        void setRight(TreeNode*);
        TreeNode* getRight() const;
        TreeNode* getLeft() const;
        void setVal(double);
};

                                
#endif //POLISHPARSE_TREENODE_H
