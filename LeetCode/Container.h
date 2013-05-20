//
//  Container.h
//  LeetCode
//
//  Created by Zhang Gongwei on 5/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__Container__
#define __LeetCode__Container__

#include "IRun.h"

class Container : public IRun {
    
public:
    
    virtual void run();
    
protected:
    int maxArea(std::vector<int>& height);
};

#endif /* defined(__LeetCode__Container__) */
