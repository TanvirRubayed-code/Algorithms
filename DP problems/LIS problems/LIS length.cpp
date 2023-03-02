#include <bits/stdc++.h>
using namespace std;

const int N = 25e2 + 10;

vector<int> seq(N);
int dp[N];

int longestSeq(int n)
{
    if (dp[n] != -1)
        return dp[n];
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (seq[i] < seq[n])
        {
            ans = max(ans, longestSeq(i) + 1);
        }
    }
    return dp[n] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, longestSeq(i));
    }
    cout << res << endl;

    return 0;
}