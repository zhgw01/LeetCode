//
//  Graph.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef LeetCode_Graph_h
#define LeetCode_Graph_h

using std::vector;

struct UndirectedGraphNode {
         int label;
         vector<UndirectedGraphNode *> neighbors;
         UndirectedGraphNode(int x) : label(x) {};

};

#endif
