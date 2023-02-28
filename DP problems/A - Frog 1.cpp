// https://atcoder.jp/contests/dp/tasks/dp_a

#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;

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

    cost = min(cost, calculateJump(n - 1) + abs(h[n] - h[n - 1]));

    if (n > 1) // cause when when n=1 i check h[-1] and calculateJump(-1)
        cost = min(cost, calculateJump(n - 2) + abs(h[n] - h[n - 2]));

    return dp[n] = cost;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    cout << calculateJump(n - 1);
    return 0;
}