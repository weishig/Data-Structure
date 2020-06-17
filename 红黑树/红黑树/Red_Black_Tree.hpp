//
//  Red_Black_Tree.hpp
//  红黑树
//
//  Created by Weishi on 6/8/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#ifndef Red_Black_Tree_hpp
#define Red_Black_Tree_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct node{
    int val;
    struct node* parent;
    struct node* left;
    struct node* right;
    int color; //0 is black 1 is red
}node;

class Red_Black_Tree{

public:
    struct node* root;
    struct node* nil;
    
    Red_Black_Tree();
    
    
};
struct node* createNode(int val,int color);
void left_rotate(Red_Black_Tree* tree,struct node* node);
void right_rotate(Red_Black_Tree* tree,struct node* node);
void RB_Insert(Red_Black_Tree* tree,struct node* node);    
void RB_Insert_Fixup(Red_Black_Tree* tree,struct node* node);
void print_inorder(Red_Black_Tree* tree, struct node* node);
#endif /* Red_Black_Tree_hpp */
