//
// Created by Pop Rosian on 04/05/2020.
//

#include "Stack.h"

Stack::Stack() { //Constructor, initializes all variables.
    this->top = nullptr;
    this->bottom = nullptr;
    this->size = 0;
}

Node *Stack::getTop() const{ //Returns the top of the stack.
    return this->top;
}

void Stack::push(TreeNode * node) { //We take in a TreeNode because that's the data the Node holds.
    Node* newNode = new Node(node); //When pushing, we create a new node based on the data.
    if(this->isEmpty() == true){ //If the stack is empty, both the top and the bottom pointers point to the same node.
        this->top = newNode;
        this->bottom = newNode;
    } else { //If there is more than one element, we point the top pointer to the new node.
        this->top->setNext(newNode);
        this->top = newNode; //Then we make the new node the top.
    }
    this->size++; //Finally, we increase the size.
}

bool Stack::isEmpty() const { //Basic check to see if the size is 0 or not.
    if(this->size == 0){
        return true;
    }
    return false;
}

TreeNode *Stack::pop() { //pop is a bit more complicated.
    if(this->isEmpty() == true){ //If the stack is empty, just return a null pointer.
        return nullptr;
    }
    TreeNode* data = this->top->getData(); //If not, the data variable will hold the TreeNode of the node on top of the stack.
    if(this->size == 1){ //If there is only one element, we simply free the memory for said element.
        delete this->top;
        this->top = nullptr; //We then just make both the top and bottom null pointers.
        this->bottom = nullptr;
    } else { //If there are more elements, we use an auxiliary node prev to get to the node before top.
        Node* prev = this->bottom;
        while (prev->getNext() != this->top){
            prev = prev->getNext();
        }
        prev->setNext(nullptr); //When we get to the node before the top, we cut the link between it and the top pointer.
        delete this->top; //Now we free the memory of the object held in the top pointer.
        this->top = prev; //And we make the auxiliary pointer the new top.
    }
    this->size--; //And finally decrease the size.
    return data; //In the end, we return the data, also known as the TreeNode that was held by the popped node.
}

