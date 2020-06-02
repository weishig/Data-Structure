//
//  main.cpp
//  单链表实现stack
//
//  Created by Weishi on 6/1/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
typedef struct node{
    struct node* next;
    int val;
}node;

typedef struct headNode{
    struct node* next;
    struct node* tail;
    int size;
}headNode;

class LinkedList{
public:
    struct headNode* linkedList;
    LinkedList(){
        linkedList=createListHead();
    }
    struct headNode* createListHead(){
        struct headNode* node=(struct headNode*)malloc(sizeof(struct headNode));
        node->next=NULL;
        node->tail=NULL;
        node->size=0;
        return node;
    }
    struct node* createNode(int val){
        struct node* node=(struct node*)malloc(sizeof(struct node));
        node->val=val;
        return node;
    }
    
    void push(int val){
        struct node* node=createNode(val);
        node->next=linkedList->next;
        linkedList->next=node;
        return;
    }
    void pop(){
        struct node* node=linkedList->next;
        if (node!=NULL) {
            linkedList->next=node->next;
            free(node);
        }
        return;
    }
    
    void print(){
        struct node* cur=linkedList->next;
        while (cur!=NULL) {
            cout<<cur->val<<" ";
            cur=cur->next;
        }
        return;
    }
};

int main(int argc, const char * argv[]) {
    LinkedList* obj=new LinkedList();
    obj->push(3);
    obj->push(2);
    obj->push(1);
    obj->push(1);
    obj->pop();
    obj->pop();
    obj->print();
    return 0;
}
