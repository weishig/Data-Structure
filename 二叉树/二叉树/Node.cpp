//
//  Node.cpp
//  二叉树
//
//  Created by Weishi on 6/6/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include "Node.h"
using namespace std;
struct node* createNode(int val){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->parent=NULL;
    node->val=val;
    node->left=NULL;
    node->right=NULL;
    
    return node;
}
void createTree(struct node* node1){
    struct node* node2=createNode(6);
    struct node* node3=createNode(18);
    node2->parent=node1;
    node3->parent=node1;
    node1->left=node2;
    node1->right=node3;
    struct node* node4=createNode(3);
    node4->parent=node2;
    struct node* node5=createNode(7);
    node5->parent=node2;
    node2->left=node4;
    node2->right=node5;
    struct node* node6=createNode(17);
    node6->parent=node3;
    struct node* node7=createNode(20);
    node7->parent=node3;
    node3->left=node6;
    node3->right=node7;
    struct node* node8=createNode(2);
    node8->parent=node4;
    struct node* node9=createNode(4);
    node9->parent=node4;
    node4->left=node8;
    node4->right=node9;
    struct node* node10=createNode(13);
    node10->parent=node5;
    struct node* node11=createNode(9);
    node11->parent=node10;
    node5->right=node10;
    node10->left=node11;
    return;
}
struct node* tree_search_recursive(struct node* node,int val){
    if (node==NULL || node->val==val) {
        return node;
    }
    if(node->val>val){
        return tree_search_recursive(node->left, val);
    }
    else return tree_search_recursive(node->right, val);
    
}

struct node* tree_search_interative(struct node* node,int val){
    while (node!=NULL) {
        if(val<node->val) node=node->left;
        else if(val>node->val) node=node->right;
        else break;
    }
    
    return node;
}
struct node* minimum_recursive(struct node* root){
    if (root->left==NULL) {
        return root;
    }
    return minimum_recursive(root->left);
}
struct node* minimum_interative(struct node* root){
    while (root->left!=NULL) {
        root=root->left;
    }
    return root;
}

struct node* maximum_recursive(struct node* root){
    while (root->right!=NULL) {
        root=root->right;
    }
    return root;
}

void print_inorder_recursive(struct node* root){
    //prints the key of the root of a subtree between printing the values in its left subtree and printing those in its right subtree
    if (root!=NULL) {
        print_inorder_recursive(root->left);
        cout<<root->val<<" ";
        print_inorder_recursive(root->right);
    }
    return;
    
}

void print_preorder_recursive(struct node* root){
    //preorder tree walk prints the root before the values in either subtree,
    
}

void print_postorder_recursive(struct node* root){
    //a postorder tree walk prints the root after the values in its subtrees.) To use the following procedure to print all the elements in a binary search tree T
}

struct node* tree_successor(struct node* node){
    if (node->right!=NULL) {
        return minimum_interative(node->right);
    }
    struct node* parent=node->parent;
    while (parent!=NULL && parent->left!=node) {
        node=parent;
        parent=parent->parent;
    }
    return parent;
}

struct node* tree_predecessor(struct node* node){
    if (node->left!=NULL) {
        return maximum_recursive(node->left);
    }
    struct node* parent=node->parent;
    while (parent!=NULL && parent->right!=node) {
        node=parent;
        parent=parent->parent;
    }
    
    return parent;
}

void print_inorder_by_TREE_SUCCESSOR(struct node* root){
    cout<<"using tree_minimum and tree_successor to print tree inorder"<<endl;
    struct node* node=minimum_recursive(root);
    cout<<node->val<<" ";
    int treeSize=11;
    for(int i=1;i<=treeSize-1;i++){
        node=tree_successor(node);
        cout<<node->val<<" ";
    }
    cout<<endl;
    
}
