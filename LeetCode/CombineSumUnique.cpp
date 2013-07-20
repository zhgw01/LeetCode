//
//  CombineSumUnique.cpp
//  LeetCode
//
//  Created by Zhang Gongwei on 7/20/13.
//  Copyright (c) 2013 Zhang Gongwei. All rights reserved.
//

#include "CombineSumUnique.h"
#include "ArrayUtil.h"

using namespace std;

void CombineSumUnique::run()
{
    cout<<"Run CombineSumUnique"<<endl;
    
    test1();
}

void CombineSumUnique::test1()
{
    int a[] = {1, 2};
    int n = sizeof(a) / sizeof(*a);
    vector<int> candidates = ArrayUtil::createFromArray(a, n);
    
    int target = 2;
    
    vector<vector<int> > result = combinationSum(candidates, target);
    
    assert(result.size() == 1);

}

vector<vector<int> > CombineSumUnique::combinationSum(std::vector<int> &candidates, int target)
{
    typedef vector<vector<int> > SumType;
    SumType result;
    
    sort(candidates.begin(), candidates.end());
    
    for (size_t i = 0; i < candidates.size(); ++i) {
        
        if (i > 0) {
            if (candidates[i - 1] == candidates[i]) {
                continue;
            }
        }
        
        int remainTarget = target - candidates[i];
        
        if (remainTarget < 0) {
            break;
        }
        else if(remainTarget == 0) {
            vector<int> sum;
            sum.push_back(candidates[i]);
            result.push_back(sum);
            
            return result;
        } else {
            
            vector<int> remainCandidate(candidates.begin() + i + 1, candidates.end());
            
            SumType remainResult = combinationSum(remainCandidate, remainTarget);
            
            for (size_t j = 0; j < remainResult.size(); ++j) {
                vector<int> sum;
                sum.push_back(candidates[i]);
                sum.insert(sum.end(), remainResult[j].begin(), remainResult[j].end());
                result.push_back(sum);
            }
            
        }
    }
    

    return result;
}