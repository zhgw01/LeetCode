#include "stdafx.h"
#include "DNASequence.h"
#include <unordered_map>
#include <string>


DNASequence::DNASequence(void)
{
}


DNASequence::~DNASequence(void)
{
}

std::vector<std::string> DNASequence::findRepeatedDnaSequences(std::string s)
{
    std::vector<std::string> result;
    std::unordered_map<int, int> m;

    for (int t = 0, i = 0, iEnd = s.size(); i < iEnd; ++i)
    {
        t = (t << 3 & 0x3FFFFFFF) | (s[i] & 7);
        if (m[t]++ == 1)
        {
            result.push_back(s.substr(i - 9, 10));
        }
    }


    return result;
}
