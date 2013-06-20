//
//  LCP.h
//  LeetCode
//
//  Created by Zhang Gongwei on 5/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__LCP__
#define __LeetCode__LCP__

#include "IRun.h"

#include <string>
#include <vector>

class LCP : public IRun {
    
public:
    virtual void run();
    
protected:
    std::string longestCommonPrefix(std::vector<std::string> &strs);
    
    bool isEqualAtIndex(std::vector<std::string>& strs, size_t index);
};

#endif /* defined(__LeetCode__LCP__) */
