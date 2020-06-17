//
//  main.cpp
//  红黑树
//
//  Created by Weishi on 6/8/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#include "Red_Black_Tree.hpp"
int main(int argc, const char * argv[]) {
    Red_Black_Tree* tree=new Red_Black_Tree();
    tree->nil=createNode(-1, 0);
    RB_Insert(tree, createNode(11, 1));
    RB_Insert(tree, createNode(2, 1));
    RB_Insert(tree, createNode(14, 1));
    RB_Insert(tree, createNode(1, 1));
    RB_Insert(tree, createNode(7, 1));
    RB_Insert(tree, createNode(15, 1));
    RB_Insert(tree, createNode(5, 1));
    RB_Insert(tree, createNode(8, 1));
    RB_Insert(tree, createNode(4, 1));
    
    return 0;
}
