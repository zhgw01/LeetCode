//
//  IRun.h
//  LeetCode
//
//  Created by Zhang Gongwei on 4/22/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__IRun__
#define __LeetCode__IRun__

#include <iostream>
#include <cassert>
#include <vector>

class IRun
{
public:
    virtual void run() = 0;
};

class DemoFactory {
    std::vector<IRun *> m_demos;
    static DemoFactory* s_intance;
    
public:
    void addDemo(IRun* demo) { m_demos.push_back(demo); }
    void run();
    static DemoFactory* getInstance();
    
protected:
    DemoFactory() {}
    
private:
    DemoFactory(const DemoFactory& );
    DemoFactory& operator=(const DemoFactory& );
};

#define REGISTER_CLASS(CLASSNAME) \
    (DemoFactory::getInstance())->addDemo(new CLASSNAME());

#endif /* defined(__LeetCode__IRun__) */
