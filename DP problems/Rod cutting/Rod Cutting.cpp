// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

#include <bits/stdc++.h>
using namespace std;

int cutting(int len, vector<int> &prices)
{
    if (len == 0)
        return 0;
    int ans = 0;
    for (int len_to_cut = 1; len_to_cut < prices.size(); len_to_cut++)
    {
        if (len - len_to_cut >= 0)
        {
            ans = max(ans, cutting(len - len_to_cut, prices) + prices[len_to_cut - 1]);
        }
    }
    return ans;
}

int cutRod(int price[], int n)
{
    vector<int> prices(price, price + n);
    return cutting(n, prices);
}

int main()
{
    int N = 8;
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    cutRod(price, N);
}