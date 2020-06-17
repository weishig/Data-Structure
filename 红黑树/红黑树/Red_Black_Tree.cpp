//
//  Red_Black_Tree.cpp
//  红黑树
//
//  Created by Weishi on 6/8/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include "Red_Black_Tree.hpp"

struct node* createNode(int val,int color){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->val=val;
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->parent=NULL;
    newNode->color=color;
    return newNode;
}
Red_Black_Tree::Red_Black_Tree(){
    nil=nullptr;
    root=nullptr;
}

void RB_Insert(Red_Black_Tree* tree,struct node* node){
    struct node* y=tree->nil;
    struct node* x=tree->root;
    

    while (x!=tree->nil && x!=NULL) {
        y=x;
        if (node->val<x->val) {
            x=x->left;
        }
        else if(node->val>x->val){
            x=x->right;
        }
    }
    
    if (y==tree->nil) {
        tree->root=node;
    }
    else if(node->val<y->val){
        y->left=node;
    }
    else{
        y->right=node;
    }
    
    node->left=tree->nil;
    node->right=tree->nil;
    node->parent=y;
    node->color=1;
    
    RB_Insert_Fixup(tree,node);
    return;
}

void left_rotate(Red_Black_Tree* tree,struct node* x){
    // assume that x->right!=T->nil and root->parent=T.nil
    struct node* y=x->right;
    x->right=y->left;
    y->left->parent=x;
    
    if (y->left!=tree->nil) {
        y->left->parent=x;
    }
    y->parent=x->parent;
    
    if (x->parent==tree->nil) { //如果x为root的话，更改root变为y
        tree->root=y;
    }
    else if(x==x->parent->left){//如果x不是root，并且x为x's parent的左孩子，则y变为x's parent的左孩子
        x->parent->left=y;
    }
    else{//如果x不是root，并且x为x's parent的右孩子，则y变为x's parent的右孩子
        x->parent->right=y;
    }
    
    y->left=x;
    x->parent=y;
    
    return;
    
}

void right_rotate(Red_Black_Tree* tree,struct node* y){
    struct node* x=y->left;
    
    //x的右孩子给y的左孩子
    y->left=x->right;
    if (x->right!=tree->nil) {
        x->right->parent=y;
    }
    
    //x的parent变为y->parent
    x->parent=y->parent;
    
    //y->parent的孩子变为x
    if(y->parent==tree->nil){
        tree->root=x;
    }
    else if(y==y->parent->left){
        y->parent->left=x;
    }
    else{
        y->parent->right=x;
    }
    
    //把y放到x->right
    x->right=y;
    y->parent=x;
    
    return;
}

void RB_Insert_Fixup(Red_Black_Tree* tree,struct node* node){
    // node是被插入的，颜色为红色
    
    while (node->parent->color==1) { //node parent为红色则一直进行while loop,因为node's color为红色，其parent不允许为红色。parent若为黑色的话则满足所有红黑树的性质
        struct node* parent=node->parent;
        struct node* grandParent=parent->parent;
        //如果parent为红色，那么一定存在一个grandparent
        if(parent==grandParent->left){
            struct node* uncle=grandParent->right;
            
            if (uncle->color==1) {//情况1：若parent和uncle都为红色
                grandParent->color=1;
                parent->color=0;
                uncle->color=0;
                
                node=grandParent;//此时须进行下一次检测， 因为之前把grandparent设置为红色了
            }
            else if(uncle->color==0 && node==parent->left){//情况2:parent,node为红色; uncle为黑色； node为parent左孩子
                //此时只需要把 parent right rotate
                right_rotate(tree,parent);
                parent->color=0;
                grandParent->color=1;
            }
            else if(uncle->color==0 && node==parent->right){
                left_rotate(tree, parent);
                right_rotate(tree, grandParent);
                node->color=0;
                grandParent->color=1;
            }
        }
        
        else{
            struct node* uncle=grandParent->left;
            
            if (uncle->color==1) {//情况1：若parent和uncle都为红色
                grandParent->color=1;
                parent->color=0;
                uncle->color=0;
                
                node=grandParent;//此时须进行下一次检测， 因为之前把grandparent设置为红色了
            }
            else if(uncle->color==0 && node==parent->right){//情况2:parent,node为红色; uncle为黑色； node为parent右孩子
                //此时只需要把 parent right rotate
                left_rotate(tree,parent);
                parent->color=0;
                grandParent->color=1;
            }
            else if(uncle->color==0 && node==parent->left){
                right_rotate(tree, parent);
                left_rotate(tree, grandParent);
                node->color=1;
                grandParent->color=1;
            }
        }
        
        
        
    }
    tree->root->color=0;
    return;
}

void print_inorder(Red_Black_Tree* tree, struct node* node){
    if(node!=tree->nil){
        print_inorder(tree,node->left);
        if (node->color==0) {
            cout<<node->val<<" black"<<endl;
        }
        else{
            cout<<node->val<<" red"<<endl;
        }
        print_inorder(tree,node->right);
    }
    return;
    
}
