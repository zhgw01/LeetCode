#include "stdafx.h"
#include "CppUnitTest.h"
#include "DNASequence.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(DNASequenceTest)
    {
    public:
        
        TEST_METHOD(testDNASquence)
        {
            std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
            
            std::string a[] = {"AAAAACCCCC", "CCCCCAAAAA"};
            std::vector<std::string> expected(a, a + sizeof(a)/sizeof(*a));

            DNASequence dna;
            std::vector<std::string> result = dna.findRepeatedDnaSequences(s);

            Assert::IsTrue(result == expected);
        }

    };
}