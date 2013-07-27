//
//  MergeInterval.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/27/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "MergeInterval.h"

using namespace std;

bool operator== (const Interval& lhs, const Interval& rhs)
{
    if (lhs.start == rhs.start && lhs.end == rhs.end) {
        return true;
    }
    
    return false;
}

void MergeInterval::run()
{
    cout<<"Run MergeInterval"<<endl;
    test3();
}

void MergeInterval::test1()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(15, 18));

    vector<Interval> result = merge(intervals);
    
    vector<Interval> expected;
    expected.push_back(Interval(1, 6));
    expected.push_back(Interval(8, 10));
    expected.push_back(Interval(15, 18));

    assert(result == expected);
}

void MergeInterval::test2()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 4));
    intervals.push_back(Interval(5, 6));
       
    vector<Interval> result = merge(intervals);
    
    vector<Interval> expected;
    expected.push_back(Interval(1, 4));
    expected.push_back(Interval(5, 6));

    
    assert(result == expected);

}

void MergeInterval::test3()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(2, 3));
    intervals.push_back(Interval(4, 5));
    intervals.push_back(Interval(6, 7));
    intervals.push_back(Interval(8, 9));
    intervals.push_back(Interval(1, 10));

    
    vector<Interval> result = merge(intervals);
    
    vector<Interval> expected;
    expected.push_back(Interval(1, 10));

    
    
    assert(result == expected);

}


vector<Interval> MergeInterval::merge(std::vector<Interval> &intervals)
{
    vector<Interval> result;
    
    if (intervals.size() == 0) {
        return result;
    }
    
    result.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); ++i) {
        
        Interval interval = intervals[i];
        
        int j;
        int mergeAt = -1;
        for (j = 0; j < result.size(); ++j) {
            if (result[j].start > interval.end) {
                break;
            }
            else if (result[j].end  >= interval.start ) {
                //can combine together
                
                if (interval.start < result[j].start) {
                    result[j].start = interval.start;
                }
                
                if (interval.end > result[j].end) {
                    result[j].end = interval.end;
                }
                
                interval = result[j]; //we maybe can continue to combine
                if (mergeAt != -1) {
                    result[mergeAt] = interval;
                    result.erase(result.begin() + j);
                    --j;
                }
                else
                    mergeAt = j;
            }
            
            //contintue to next for condition result[j] < interval (whole)
        }
        
        if (mergeAt == -1) {
            result.insert(result.begin() + j, interval);
        }
        
    }
    
    return result;
}