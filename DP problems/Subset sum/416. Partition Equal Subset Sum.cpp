// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;
int dp[205][20005];
bool findSubset(int n, int sum, vector<int> &nums)
{
    if (sum == 0)
        return true;
    if (n < 0)
        return false;
    if (dp[n][sum] != -1)
        return dp[n][sum];

    // not consider
    bool ispossible = findSubset(n - 1, sum, nums);
    // consider
    if (sum - nums[n] >= 0)
        ispossible |= findSubset(n - 1, sum - nums[n], nums);
    return dp[n][sum] = ispossible;
}

bool canPartition(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));

    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0)
        return false;
    sum /= 2;
    return findSubset(nums.size() - 1, sum, nums);
}

int main()
{
    vector<int> nums = {1, 2, 3, 5};
    cout << canPartition(nums);
}