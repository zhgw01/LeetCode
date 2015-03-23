#include "stdafx.h"
#include "MinStack.h"


MinStack::MinStack(void)
{
}


MinStack::~MinStack(void)
{
}

void MinStack::push(int x)
{
    m_data.push_back(x);

    if (m_min.empty() || x < m_data[m_min.back()])
    {
        m_min.push_back(m_data.size() - 1);
    }

}

void MinStack::pop()
{
    if (m_min.back() == m_data.size() - 1)
    {
        m_min.pop_back();
    }
    m_data.pop_back();
}

int MinStack::top()
{
    if (m_data.empty())
    {
        throw "Empty Stack, cannot get top";
    }

    return m_data.back();
}

int MinStack::getMin()
{
    if (m_min.empty())
    {
        throw "Empty Stack, cannot call getMin";
    }

    int index = m_min.back();

    return m_data[index];
}
