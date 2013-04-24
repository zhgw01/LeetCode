//
//  IRun.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 4/22/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "IRun.h"

DemoFactory* DemoFactory::s_intance = NULL;

void DemoFactory::run()
{
    for (int i = 0; i < m_demos.size(); ++i) {
        m_demos[i]->run();
    }
}

DemoFactory* DemoFactory::getInstance()
{
    if (!s_intance) {
        s_intance = new DemoFactory();
    }
    
    return s_intance;
}