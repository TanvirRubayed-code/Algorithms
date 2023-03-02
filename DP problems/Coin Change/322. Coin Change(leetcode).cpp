// https: // leetcode.com/problems/coin-change/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int dp[N];

int findCoin(int amount, vector<int> &coins)
{
    if (amount == 0)
        return 0;

    if (dp[amount] != -1)
        return dp[amount];

    int ans = INT_MAX;

    for (int coin : coins)
    {
        if (amount - coin >= 0)
        {
            ans = min(ans + 0LL, findCoin(amount - coin, coins) + 1LL);
        }
    }
    return dp[amount] = ans;
}

int coinChange(vector<int> &coins, int amount)
{
    memset(dp, -1, sizeof(dp));

    int ans = findCoin(amount, coins);
    return ans == INT_MAX ? -1 : ans;
}

int main()
{
    vector<int> coins = {2};
    cout << coinChange(coins, 3) << endl;
}
