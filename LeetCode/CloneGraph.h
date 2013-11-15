//
//  CloneGraph.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__CloneGraph__
#define __LeetCode__CloneGraph__

#include "IRun.h"
#include "Graph.h"
#include <unordered_map>

class CloneGraph : public IRun
{
public:
    virtual void run();

private:
    void test1();

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node);
    UndirectedGraphNode *cloneWithMap(UndirectedGraphNode *node, std::unordered_map<int, UndirectedGraphNode*>& map);
};

#endif /* defined(__LeetCode__CloneGraph__) */
