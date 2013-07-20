//
//  CombineSum.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/19/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "CombineSum.h"
#include "ArrayUtil.h"

using namespace std;

void CombineSum::run()
{
    cout<<"Run CombineSum"<<endl;
    
    test1();
}

void CombineSum::test1()
{
    int a[] = {1, 2};
    int n = sizeof(a) / sizeof(*a);
    vector<int> candidates = ArrayUtil::createFromArray(a, n);
    
    int target = 3;
    
    vector<vector<int> > result = combinationSum(candidates, target);
    
    assert(result.size() == 2);
}

vector<vector<int> > CombineSum::combinationSum(std::vector<int> &candidates, int target)
{
    typedef vector<vector<int> > SumType;
    
    SumType result;
    
    if (target <= 0) {
        return result;
    }
    
    if (candidates.size() == 1) {
        
        vector<int> sum;
        
        if (target % candidates[0] == 0) {
            while (target > 0) {
                sum.push_back(candidates[0]);
                target -= candidates[0];
            }
        }
        
        if (sum.size() > 0) {
            result.push_back(sum);
        }
        
        return result;
    }
    
    sort(candidates.begin(), candidates.end());
    
    
    for (int i = 0; i < candidates.size(); ++i) {
        
        if (candidates[i] <= target) {
            
            vector<int> remainCandidate(candidates.begin() + i, candidates.end());
            int remainTarget = target - candidates[i];
            
            if (remainTarget == 0) {
                vector<int> sum;
                sum.push_back(candidates[i]);
                result.push_back(sum);
                
                return result;
            }
            
            SumType possibleResult = combinationSum(remainCandidate, remainTarget);
            
            for(int j = 0; j < possibleResult.size(); ++j)
            {
                vector<int> sum;
                sum.push_back(candidates[i]);
                sum.insert(sum.end(), possibleResult[j].begin(), possibleResult[j].end());
                result.push_back(sum);
            }
        }
        else
            break;
        
    }
    
    
    return result;
}