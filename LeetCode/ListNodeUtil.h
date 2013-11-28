//
//  ListNodeUtil.h
//  LeetCode
//
//  Created by Zhang Gongwei on 6/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ListNodeUtil__
#define __LeetCode__ListNodeUtil__

#include  "NthNode.h"

class ListNodeUtil {
    
public:
    static ListNode* createListFromArray(int nums[], int n);
    static ListNode* createListFromVector(std::vector<int>& v);
    static std::vector<int> getArrayFromList(ListNode *head);
    
};

#endif /* defined(__LeetCode__ListNodeUtil__) */
