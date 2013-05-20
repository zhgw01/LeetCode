//
//  Container.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 5/15/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "Container.h"

using namespace std;

void Container::run()
{
    cout<<"Run Container"<<endl;
}

int Container::maxArea(std::vector<int> &height)
{
    int result = 0;
    int left = 0;
    int right = height.size() - 1;
    
    while (left < right) {
        
        int area = (right - left) * min(height[left], height[right]);
        if (area > result) {
            result = area;
        }
        
        //the area is based on the min height, try to find higher height
        if (height[left] < height[right]) {
            ++left;
        }
        else
            --right;
    
    }
    
    return  result;
}