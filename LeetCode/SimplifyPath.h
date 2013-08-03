//
//  SimplifyPath.h
//  LeetCode
//
//  Created by Zhang Gongwei on 8/3/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__SimplifyPath__
#define __LeetCode__SimplifyPath__

#include "IRun.h"

class SimplifyPath : public IRun
{
public:
    virtual void run();

private:
    void test1();
    
    std::string simplifyPath(std::string path);

};

#endif /* defined(__LeetCode__SimplifyPath__) */
