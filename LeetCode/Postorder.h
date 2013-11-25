//
//  Postorder.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Postorder__
#define __LeetCode__Postorder__

#include "IRun.h"
#include "Tree.h"

using std::vector;

class Postorder : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    vector<int> postorderTraversal(TreeNode *root);

};

#endif /* defined(__LeetCode__Postorder__) */
