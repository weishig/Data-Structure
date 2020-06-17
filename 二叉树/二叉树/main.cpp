//
//  main.cpp
//  二叉树
//
//  Created by Weishi on 6/6/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;

int main(int argc, const char * argv[]) {
    struct node* root=createNode(15);
    createTree(root);
    
    //search node recursive
    struct node* search_node=tree_search_recursive(root, 15);
    if(search_node!=NULL) cout<<search_node->val<<endl;
    
    //search node iterative
    search_node=tree_search_interative(root, 15);
    if(search_node!=NULL) cout<<search_node->val<<endl;
    
    //minimum node recursive
    struct node* minimum_node=minimum_recursive(root);
    cout<<"minimum is "<<minimum_node->val<<endl;
    
    //minimum node iterative
    minimum_node=minimum_interative(root);
    cout<<"minimum is "<<minimum_node->val<<endl;
    
    //print inorder
    print_inorder_recursive(root);
    cout<<endl;
    
    struct node* node=tree_search_recursive(root, 13);
    struct node* successor=tree_successor(node);
    cout<<"successor of "<<node->val<<" is "<<successor->val<<endl;
    
    struct node* node1=tree_search_recursive(root, 13);
    struct node* predeccessor=tree_predecessor(node1);
    cout<<"predeccessor of "<<node1->val<<" is "<<predeccessor->val<<endl;
    
    struct node* node17=tree_search_recursive(root, 6);
    tree_delete(node17);
    cout<<"delete 6"<<endl;
    print_inorder_recursive(root);
    cout<<endl;
    
    struct node* node21=createNode(1);
    insertion_recursive(root, node21);
    cout<<"insert 21"<<endl;
    print_inorder_recursive(root);
    cout<<endl;
    
    return 0;
}
