//
//  CloneGraph.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "CloneGraph.h"

using namespace std;

void CloneGraph::run()
{
    cout<<"Run CloneGraph"<<endl;
    
    test1();
}

void CloneGraph::test1()
{
    
    UndirectedGraphNode *node = new UndirectedGraphNode(0);
    node->neighbors.push_back(node);
    node->neighbors.push_back(node);
    
    UndirectedGraphNode * clone = cloneGraph(node);
    
    assert(clone != NULL);
}

UndirectedGraphNode *CloneGraph::cloneWithMap(UndirectedGraphNode *node, std::unordered_map<int, UndirectedGraphNode*>& map)
{
    int label = node->label;
    if (map.find(label) != map.end())
        return map[label];
    
    UndirectedGraphNode * cloneNode  = new UndirectedGraphNode(label);
    map[label] = cloneNode;
    
    auto it = node->neighbors.begin();
    auto end = node->neighbors.end();
    
    for (; it != end; ++it) {
        cloneNode->neighbors.push_back(cloneWithMap(*it, map));
    }
    
    return cloneNode;
}

UndirectedGraphNode *CloneGraph::cloneGraph(UndirectedGraphNode *node)
{
    if (!node) {
        return nullptr;
    }
    
    std::unordered_map<int, UndirectedGraphNode*> map;
    
    return cloneWithMap(node, map);
    
}