//
//  InsertInterval.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/28/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "InsertInterval.h"

using namespace std;

void InsertInterval::run()
{
    cout<<"Run InsertInterval"<<endl;
    test1();
}

void InsertInterval::test1()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(2, 5));
    intervals.push_back(Interval(6, 7));
    intervals.push_back(Interval(8, 9));


    

    Interval ins(0, 10);
    
    vector<Interval> result = insert(intervals, ins);
    
    vector<Interval> expected;
    expected.push_back(Interval(0, 10));
  
    
    assert(result == expected);

}

vector<Interval> InsertInterval::insert(std::vector<Interval> &intervals, Interval newInterval)
{
    vector<Interval> result(intervals);
    
    if (intervals.size() == 0) {
        result.push_back(newInterval);
        return result;
    }
    
    int mergeIndex = -1;
    int i;
    for (i = 0; i < result.size(); ++i) {
        if (result[i].start > newInterval.end ) {
            break;
        }
        else if(result[i].end >= newInterval.start) {
            if (newInterval.start < result[i].start) {
                result[i].start = newInterval.start;
            }
            
            if (newInterval.end > result[i].end) {
                result[i].end = newInterval.end;
            }
            
            newInterval = result[i];
            if (mergeIndex != -1) {
                result[mergeIndex] = newInterval;
                result.erase(result.begin() + i);
                --i;
            }
            else 
                mergeIndex = i;
        }
    }
    
    if (mergeIndex == -1) {
        result.insert(result.begin() + i, newInterval);
    }
    
    return result;
}