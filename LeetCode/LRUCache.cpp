//
//  LRUCache.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 11/26/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "LRUCache.h"

using namespace std;

void LRUCache::run()
{
    cout<<"Run LRUCache"<<endl;
    test1();
}

void LRUCache::test1()
{
    set(2, 1);
    set(1, 1);
    
    int k = get(2);
    assert(k == 1);
    
    set(4,1);
    k = get(1);
    assert(k == -1);
}

void LRUCache::update(int key, int value)
{
    m_lru.push_front(node(key, value));
    m_hash[key] = m_lru.begin();
}

int LRUCache::get(int key)
{
    if (m_hash.find(key) != m_hash.end()) {
        auto lruIt = m_hash[key];
        int value = lruIt->value;
        
        m_lru.erase(lruIt);
        update(key, value);
        
        return value;
    }
    
    return -1;
}

void LRUCache::set(int key, int value)
{
    auto it = m_hash.find(key);
    if ( it != m_hash.end()) {
        m_lru.erase(it->second);
    }
    else {
        if (m_size < m_capacity)
            ++m_size;
        else
        {
            int oldKey = m_lru.rbegin()->key;
            m_lru.pop_back();
            m_hash.erase(oldKey);
        }
    }
    
    update(key, value);
}