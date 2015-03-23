#include "stdafx.h"
#include "CppUnitTest.h"
#include "PeakNumber.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(PeakNumberTest)
    {
    public:
        
        TEST_METHOD(testPeakNumber)
        {
            int a[] = {1, 2, 3, 1};
            std::vector<int> num(a, a + sizeof(a) / sizeof(*a));

            int expected = 2;
            PeakNumber peak;
            int result = peak.findPeakElement(num);

            Assert::IsTrue(expected == result);
        }

    };
}