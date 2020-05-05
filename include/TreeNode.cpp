//
// Created by Pop Rosian on 04/05/2020.
//

#include "TreeNode.h"

TreeNode::TreeNode(char token) {
    this->token = token;
    this->left = nullptr;
    this->right = nullptr;
}

char TreeNode::getToken() const {
    return this->token;
}

void TreeNode::setToken(char token) {
    this->token = token;
}

void TreeNode::setLeft(TreeNode * left) {
    this->left = left;
}

void TreeNode::setRight(TreeNode * right) {
    this->right = right;
}

TreeNode *TreeNode::getRight() const {
    return this->right;
}


TreeNode *TreeNode::getLeft() const {
    return this->left;
}

void TreeNode::setVal(double val) {
    this->val = val;
}





