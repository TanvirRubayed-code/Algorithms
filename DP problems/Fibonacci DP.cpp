#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;

int dp[N];

int fib(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    // top down approach -------> fibonacci tree approach
    if (dp[n] != -1) // memoize / memoization
        return dp[n];

    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{
    memset(dp, -1, sizeof(dp));

    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}