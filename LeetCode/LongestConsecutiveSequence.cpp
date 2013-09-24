//
//  LongestConsecutiveSequence.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 9/24/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "LongestConsecutiveSequence.h"
#include "ArrayUtil.h"
#include <unordered_map>

using namespace std;

void LongestConsecutiveSequence::run()
{
    cout<<"Run LongestConsecutiveSequence"<<endl;
    test2();
}

void LongestConsecutiveSequence::test1()
{
    int a[] = {100, 4, 200, 1, 3, 2};
    int na = sizeof(a) / sizeof(*a);
    
    vector<int> num = ArrayUtil::createFromArray(a, na);
    int result = longestConsecutive(num);
    
    int expected = 4;
    
    assert(result == expected);
}

void LongestConsecutiveSequence::test2()
{
    int a[] = {0, -1};
    int na = sizeof(a) / sizeof(*a);
    
    vector<int> num = ArrayUtil::createFromArray(a, na);
    int result = longestConsecutive(num);
    
    int expected = 2;
    
    assert(result == expected);
    
}

int merge(unordered_map<int, int>& map, int left, int right)
{
    int lower = left - map[left] + 1;
    int upper = right + map[right] - 1;
    
    int length = upper - lower + 1;
    map[lower] = length;
    map[upper] = length;
    
    return length;
}

int LongestConsecutiveSequence::longestConsecutive(std::vector<int> &num)
{
    unordered_map<int, int> map;
    
    int size = num.size();
    int index = 0;
    int maxLength = 1;
    
    
    while (index < size) {
        int i = num[index++];
        if (map.find(i) != map.end()) {
            continue;
        }
        
        map[i] = 1;
        
        if (map.find(i-1) != map.end()) {
            maxLength = std::max(maxLength, merge(map, i-1, i));
        }
        
        
        if (map.find(i+1) != map.end()) {
            maxLength = std::max(maxLength, merge(map, i, i+1));
        }
    }
    
    return maxLength;
}