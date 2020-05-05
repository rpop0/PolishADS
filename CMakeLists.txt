cmake_minimum_required(VERSION 3.16)
project(PolishParse)

set(CMAKE_CXX_STANDARD 14)

add_executable(PolishParse main.cpp include/TreeNode.cpp include/TreeNode.h include/Node.cpp include/Node.h include/Stack.cpp include/Stack.h include/ExpressionTree.cpp include/ExpressionTree.h)