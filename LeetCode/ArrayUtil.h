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
    
    template<class T>
    static std::vector<T> createFromArray(T a[], int n)
    {
        std::vector<T> result;
        
        for (int i = 0; i < n; ++i) {
            result.push_back(a[i]);
        }
        
        return result;

    }
    
    static bool equalToArray(const std::vector<int>& v, int a[], int n);
};

#endif /* defined(__LeetCode__ArrayUtil__) */
