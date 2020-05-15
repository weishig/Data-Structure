//
//  Node.cpp
//  leetcode814 二叉树剪枝
//
//  Created by Weishi on 5/8/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#include <stdio.h>
#include <vector>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
