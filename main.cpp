#include <iostream>
#include <fstream>
#include <string>
#include "include/ExpressionTree.h"
using  namespace std;
ifstream f("input.txt");

int main() {
    ExpressionTree expressionTree = ExpressionTree();
    string inputString;
    f>>inputString;
    bool success = true;
    int i=0;
    int inputLength = inputString.length();
    while(i < inputLength and success){
        if(inputString[i] >= '0' and inputString[i] <= '9'){ //If the character is a digit, create a node and insert it.
            TreeNode* node = new  TreeNode(inputString[i]);
            success = expressionTree.insert(node);
        } else if (inputString[i] == '-' or inputString[i] == '+' or inputString[i] == '*' or inputString[i] == '/'){
            TreeNode* node = new TreeNode(inputString[i]); //If it's an operand, do the same.
            success = expressionTree.insert(node);
            expressionTree.getStack()->push(node); //Also push it to the stack.
        } else if (inputString[i] != '(' and inputString[i] != ')'){ //Any other characters besides operators, digits and ( ), stop the loop.
            success = false;
        }
        i++;
    }

    if(success == false or expressionTree.getStack()->isEmpty() == false){
        cout<<"Expression is invalid!";
    } else {
        cout<<expressionTree.eval(expressionTree.getRoot());
    }
    f.close();

}
