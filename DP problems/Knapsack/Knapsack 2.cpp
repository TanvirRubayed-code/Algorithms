// https://atcoder.jp/contests/dp/tasks/dp_e

#include <bits/stdc++.h>
using namespace std;
int weight[105], value[105];
long long dp[105][1000005];
long long knapsackBag(int index, int left_value)
{

    if (left_value == 0)
        return 0;
    if (index < 0)
        return 1e15;
    if (dp[index][left_value] != -1)
        return dp[index][left_value];

    // don't choose
    long long ans = knapsackBag(index - 1, left_value);
    if (left_value - value[index] >= 0)
        ans = min(ans, knapsackBag(index - 1, left_value - value[index]) + weight[index]);

    return dp[index][left_value] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }

    int max_value = 1e5;
    for (int i = max_value; i >= 0; --i)
    {
        if (knapsackBag(n - 1, i) <= w)
        {
            cout << i << endl;
            break;
        }
    }
}
