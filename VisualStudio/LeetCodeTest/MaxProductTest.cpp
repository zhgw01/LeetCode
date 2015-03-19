#include "stdafx.h"
#include "CppUnitTest.h"
#include "MaxProduct.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LeetCodeTest
{
    TEST_CLASS(MaxProductTest)
    {
    public:
        
        TEST_METHOD(testMaxProduct)
        {
            int A[] = {2, 3, -2, 4};
            int expected = 6;

            MaxProduct product;
            int result = product.maxProduct(A, sizeof(A)/ sizeof(*A));

            Assert::IsTrue(result == expected, L"the result should be 6");
        }

        TEST_METHOD(testMaxProductWithMinus)
        {
            int A[] = {-2};
            int expected = -2;

            MaxProduct product;
            int result = product.maxProduct(A, sizeof(A)/ sizeof(*A));

            Assert::IsTrue(result == expected, L"wrong result");
        }

        TEST_METHOD(testMaxProductWithZero)
        {
            int A[] = {0};
            int expected = 0;

            MaxProduct product;
            int result = product.maxProduct(A, sizeof(A)/ sizeof(*A));

            Assert::IsTrue(result == expected, L"the result should be 1");
        }

        TEST_METHOD(testMaxProductWithZeroAndMinus)
        {
            int A[] = {-2, 0, -1};
            int expected = 0;

            MaxProduct product;
            int result = product.maxProduct(A, sizeof(A)/ sizeof(*A));

            Assert::IsTrue(result == expected, L"the result should be 1");
        }

        TEST_METHOD(testMaxProductWithMinusInMiddel)
        {
            int A[] = {3, -1, 4};
            int expected = 4;

            MaxProduct product;
            int result = product.maxProduct(A, sizeof(A)/ sizeof(*A));

            Assert::IsTrue(result == expected, L"the result should be 1");
        }

        TEST_METHOD(testMaxProductWithMinusInMiddel2)
        {
            int A[] = {2,-5,-2,-4,3};
            int expected = 24;

            MaxProduct product;
            int result = product.maxProduct(A, sizeof(A)/ sizeof(*A));

            Assert::IsTrue(result == expected, L"the result should be 24");
        }

        TEST_METHOD(testMaxProductWithAdjacentMinus)
        {
            int A[] = {-4,-3,-2};
            int expected = 12;

            MaxProduct product;
            int result = product.maxProduct(A, sizeof(A)/ sizeof(*A));

            Assert::IsTrue(result == expected, L"the result should be 12");
        }

        TEST_METHOD(testMaxProductWithAdjacentMinusOne)
        {
            int A[] = {-1,-1};
            int expected = 1;

            MaxProduct product;
            int result = product.maxProduct(A, sizeof(A)/ sizeof(*A));

            Assert::IsTrue(result == expected, L"the result should be 12");
        }

        TEST_METHOD(testMaxProductWithLongArray)
        {
            int A[] = {1,2,-1,-2,2,1,-2,1,4,-5,4};
            int expected = 1280;

            MaxProduct product;
            int result = product.maxProduct(A, sizeof(A)/ sizeof(*A));

            Assert::IsTrue(result == expected, L"the result should be 12");
        }

    };
}