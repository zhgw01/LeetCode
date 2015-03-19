#include "stdafx.h"
#include "MaxProduct.h"
#include <vector>
#include <algorithm>


MaxProduct::MaxProduct(void)
{
}


MaxProduct::~MaxProduct(void)
{
}

int MaxProduct::maxProduct(int A[], int n)
{
    if (n <= 0)
    {
        return 0;
    }

    std::vector<int> product(A, A + n);
    std::vector<int> minusProduct(A, A+n);

    for (int i = n-2; i >=0; --i)
    {
        if (product[i] >= 0)
        {
            if (product[i+1] > 0)
            {
                product[i] *= product[i+1];
            }

            if (minusProduct[i+1] < 0)
            {
                minusProduct[i] *= minusProduct[i+1];
            }
        }
        else
        {
            if (minusProduct[i+1] < 0)
            {
                product[i] *= minusProduct[i+1];
            }

            if (product[i+1] > 0)
            {
                minusProduct[i] *= product[i+1];
            }
        }

    }

    auto it = std::max_element(product.begin(), product.end());
    return *it;
}
