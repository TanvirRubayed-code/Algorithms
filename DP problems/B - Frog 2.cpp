// https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;

int k;
int dp[N];
int h[N];

int calculateJump(int n)
{

    // base case because the frog initially in number 1 stone. so cost = 0
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int cost = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (n - j >= 0) // cause when when n=1 i check h[-1] and calculateJump(-1)
            cost = min(cost, calculateJump(n - j) + abs(h[n] - h[n - j]));
    }

    return dp[n] = cost;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cout << calculateJump(n - 1);
    return 0;
}