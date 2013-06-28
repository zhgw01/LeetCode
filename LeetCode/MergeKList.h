//
//  MergeKList.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/25/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__MergeKList__
#define __LeetCode__MergeKList__

#include "IRun.h"
#include "NthNode.h"

class MergeKList : public IRun{
public:
    virtual void run();
    
private:
    void test1();
    
    ListNode *mergeKLists(std::vector<ListNode *> &lists);
};


#endif /* defined(__LeetCode__MergeKList__) */
