#include "stdafx.h"
#include "CppUnitTest.h"
#include "RotateSortArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(RotateSortArrayTest)
    {
    public:
        
        TEST_METHOD(testMinium)
        {
            RotateSortArray array;

            int num[] = {4, 5, 6, 7, 0, 1, 2};
            std::vector<int> numVector(num, num + sizeof(num)/sizeof(*num));
            int expected = 0;

            int result = array.findMin(numVector);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testMinium21)
        {
            RotateSortArray array;

            int num[] = {2,1};
            std::vector<int> numVector(num, num + sizeof(num)/sizeof(*num));
            int expected = 1;

            int result = array.findMin(numVector);
            Assert::IsTrue(result == expected);
        }
      
        TEST_METHOD(testMinium312)
        {
            RotateSortArray array;

            int num[] = {3, 1, 2};
            std::vector<int> numVector(num, num + sizeof(num)/sizeof(*num));
            int expected = 1;

            int result = array.findMin(numVector);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testMiniumDuplicate)
        {
            RotateSortArray array;

            int num[] = {3,1,3};
            std::vector<int> numVector(num, num + sizeof(num)/sizeof(*num));
            int expected = 1;

            int result = array.findMinWithDuplicate(numVector);
            Assert::IsTrue(result == expected);
        }

        TEST_METHOD(testMiniumDuplicate10)
        {
            RotateSortArray array;

            int num[] = {10,1,10,10,10};
            std::vector<int> numVector(num, num + sizeof(num)/sizeof(*num));
            int expected = 1;

            int result = array.findMinWithDuplicate(numVector);
            Assert::IsTrue(result == expected);
        }

    };
}