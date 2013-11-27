//
//  LRUCache.h
//  LeetCode
//
//  Created by Zhang Gongwei on 11/26/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#ifndef __LeetCode__LRUCache__
#define __LeetCode__LRUCache__

#include "IRun.h"
#include <unordered_map>
#include <list>


struct node {
    int key;
    int value;
    
    node(int k, int v) : key(k), value(v) {}
};

class LRUCache : public IRun
{
public:
    LRUCache(int capacity = 2):
    m_capacity(capacity),
    m_hash(capacity),
    m_size(0)
    {
    }
    
    int get(int key);
    void set(int key, int value);
    
    virtual void run();

private:
    void update(int key, int value);
    void test1();
    const int m_capacity;
    std::unordered_map<int, std::list<node>::iterator> m_hash;
    std::list<node> m_lru;
    int m_size;
};

#endif /* defined(__LeetCode__LRUCache__) */
