#include "stdafx.h"
#include "LargestNumber.h"
#include <algorithm>
#include <string>


LargestNumber::LargestNumber(void)
{
}


LargestNumber::~LargestNumber(void)
{
}

std::string LargestNumber::largestNumber(std::vector<int> &num)
{
    std::vector<std::string> numString(num.size());

    std::transform(num.begin(), num.end(), numString.begin(), [](int n){
         return std::to_string(n);
    });

    std::sort(numString.begin(), numString.end(), [](const std::string& a, const std::string& b){
        //descendant sorting
        return (a+b) > (b+a);
    });

    std::string result = "";

    std::for_each(numString.begin(), numString.end(), [&result](std::string n){
        if (!(result.empty() && n == "0"))
        {
            result += n;
        }
    });

    return result.empty() ? "0" : result;
}
