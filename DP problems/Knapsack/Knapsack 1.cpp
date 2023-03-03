// https://atcoder.jp/contests/dp/tasks/dp_d

#include <bits/stdc++.h>
using namespace std;
long long weight[110], value[10010];
long long dp[110][100010];

long long takenItems(int index, int left_weight)
{
    if (index < 0)
        return 0;
    if (left_weight == 0)
        return 0;
    if (dp[index][left_weight] != -1)
        return dp[index][left_weight];

    // when the item is not choosen
    long long ans = takenItems(index - 1, left_weight);
    // when the item is choosen
    if (left_weight - weight[index] >= 0)
    {
        ans = max(ans, (takenItems(index - 1, left_weight - weight[index]) + value[index]));
    }
    return dp[index][left_weight] = ans;
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
    cout << takenItems(n, w) << endl;
}