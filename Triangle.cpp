#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generate(int numRows);
vector<int> getRow(int rowIndex);

int maxProfit(vector<int> &prices)
{
    int maxDiff = 0;
    int i, start = 0, end = prices.size();
    int min = 99999999, max = 0, min_i = end - 1, max_i = 0, temp;
    for (i = start; i < end; i++)
    {
        if (min > prices[i])
        {
            min = prices[i];
            min_i = i;
        }
        if (max < prices[i])
        {
            max = prices[i];
            max_i = i;
        }
    }
    while (max_i == start && min_i == end - 1)
    {
        start++;
        end--;
        min = 99999999;
        max = 0;
        for (i = start; i < end; i++)
        {
            if (min > prices[i])
            {
                min = prices[i];
                min_i = i;
            }
            if (max < prices[i])
            {
                max = prices[i];
                max_i = i;
            }
        }
    }

    for (i = min_i + 1; i < end; i++)
    {
        temp = prices[i] - prices[min_i];
        if (maxDiff < temp)
            maxDiff = temp;
    }
    for (i = start; i < max_i; i++)
    {
        temp = prices[max_i] - prices[i];
        if (maxDiff < temp)
            maxDiff = temp;
    }

    return maxDiff;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    if (numRows == 0)
        return ans;
    vector<int> temp;
    vector<int> temp2;
    temp.push_back(1);
    ans.push_back(temp);
    for (int i = 1; i < numRows; i++)
    {
        temp.clear();
        temp.push_back(1);
        temp2 = ans[i - 1];
        for (int j = 1; j < temp2.size(); j++)
            temp.push_back(temp2[j - 1] + temp2[j]);
        temp.push_back(1);
        ans.push_back(temp);
    }
    return ans;
}

vector<int> getRow(int rowIndex)
{
    vector<int> ans(rowIndex + 1);
    ans[0] = 1;
    for (int i = 1; i < rowIndex + 1; ++i)
    {
        for (int j = i; j >= 1; --j) //从后往前是够聪明呀
        {
            ans[j] += ans[j - 1];
        }
    }
    return ans;

    // int pre, temp;
    // for (int i = 1; i < rowIndex + 1; i++)
    // {
    //     pre = 1;
    //     for (int j = 1; j <= i; j++)
    //     {
    //         temp = ans[j];
    //         ans[j] = pre + temp;
    //         pre = temp;
    //     }
    // }
    // return ans;
}