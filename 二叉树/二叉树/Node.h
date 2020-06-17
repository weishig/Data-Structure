//
//  Node.hpp
//  二叉树
//
//  Created by Weishi on 6/6/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct node{
    int val;
    struct node* left;
    struct node* right;
    struct node* parent;
}node;

struct node* createNode(int val);
void createTree(struct node* node1);
struct node* tree_search_recursive(struct node* root,int val);
struct node* tree_search_interative(struct node* root,int val);
struct node* minimum_recursive(struct node* root);
struct node* minimum_interative(struct node* root);
struct node* maximum_recursive(struct node* root);
void print_inorder_recursive(struct node* root);
void print_preorder_recursive(struct node* root);
void print_postorder_recursive(struct node* root);
struct node* tree_successor(struct node* node);
struct node* tree_predecessor(struct node* node);
void print_inorder_by_TREE_SUCCESSOR(struct node* root);
void insertion(struct node* root,struct node* newNode);
void insertion_recursive(struct node* root,struct node* newNode);
void transplant(struct node* u,struct node* v);
void tree_delete(struct node* delete_node);
#endif /* Node_h */
