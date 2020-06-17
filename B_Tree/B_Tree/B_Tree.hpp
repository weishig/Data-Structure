//
//  B_Tree.hpp
//  B_Tree
//
//  Created by Weishi on 6/15/20.
//  Copyright © 2020 Weishi. All rights reserved.
//

#ifndef B_Tree_hpp
#define B_Tree_hpp

#include <stdio.h>
typedef struct B_Tree_Node{
    int key_count;
    int 
    
}B_Tree_Node;

class B_Tree{
    B_Tree_Node* root;
    
public:
    B_Tree_Node* Search(B_Tree_Node* root,int val);
    
}

#endif /* B_Tree_hpp */
