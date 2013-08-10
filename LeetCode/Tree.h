//
//  Tree.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/10/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Tree__
#define __LeetCode__Tree__

#include <cstddef>

 struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class TreeUtil {
public:
    
    static  TreeNode* createTree(char* a, int n);
};

#endif /* defined(__LeetCode__Tree__) */
