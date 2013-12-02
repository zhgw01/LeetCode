//
//  MaxPoints.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 12/2/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "MaxPoints.h"
#include <unordered_map>

using namespace std;

void MaxPoints::run()
{
    cout<<"Run MaxPoints"<<endl;
    test1();
}

void MaxPoints::test1()
{
    vector<Point> points;
    points.emplace_back(0, 0);
    points.emplace_back(0, 1);
    
    int result  = maxPoints(points);
    assert(result == 2);
}


int MaxPoints::maxPoints(std::vector<Point> &points)
{
    int result = 0;
    
    for (Point p : points) {
        unordered_map<float, int> slopes;
        int pNumber = 0;
        
        for (Point q: points) {
            
            if (p.x == q.x && p.y == q.y) {
                ++pNumber;
                continue;
            }
            
            float slope;
            if (p.x == q.x )
                slope = 0;
            else if(p.y == q.y)
                slope = 1;
            else
                slope = static_cast<float>(p.y - q.y) / static_cast<float>(p.x - q.x);
            
            if (slopes.find(slope) != slopes.end()) {
                slopes[slope] += 1;
            }
            else
                slopes[slope] = 1;
        }
        
        if (result < pNumber) {
            result = pNumber;
        }
        
        for (auto kv : slopes) {
            if (kv.second + pNumber > result) {
                result = kv.second + pNumber;
            }
        }
    }
    
    
    return result;
}