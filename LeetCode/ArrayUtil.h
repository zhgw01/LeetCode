//
//  ArrayUtil.h
//  LeetCode
//
//  Created by Zhang Gongwei on 7/4/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__ArrayUtil__
#define __LeetCode__ArrayUtil__

#include <vector>

class ArrayUtil {
    
public:
    
    static std::vector<int> createFromArray(int a[], int n);
    
    static bool equalToArray(const std::vector<int>& v, int a[], int n);
};

#endif /* defined(__LeetCode__ArrayUtil__) */
