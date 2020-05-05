//
// Created by Pop Rosian on 04/05/2020.
//

#include "Node.h"

Node::Node(TreeNode * treeNode) {
    this->data = treeNode;
    this->next = nullptr;
}

TreeNode *Node::getData() const {
    return this->data;
}

void Node::setNext(Node * next) {
    this->next = next;
}

Node *Node::getNext() const {
    return this->next;
}
