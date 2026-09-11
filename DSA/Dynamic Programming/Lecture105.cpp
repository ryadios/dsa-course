#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int n, vector<int> &dp) {
    if (n < 0) return 0;
    if (n == 0) return nums[0];

    if (dp[n] != -1) return dp[n];

    int incl = solve(nums, n - 2, dp) + nums[n];
    int excl = solve(nums, n - 1, dp);

    return dp[n] = max(incl, excl);
}

int tabulation(vector<int> &nums) {
    int n = nums.size();

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++) {
        int curr = max(prev2 + nums[i], prev1);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. Maximum sum of non-adjacent elements
	// https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261
	
	int n;
	cin >> n;
	
	vector<int> nums(n);
	for (int i = 0; i < n; i++) cin >> nums[i];

	vector<int> dp(nums.size(), -1);
    cout << solve(nums, nums.size() - 1, dp) << "\n";

    cout <<  tabulation(nums) << "\n";

	return 0;
}
