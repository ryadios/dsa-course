#include <bits/stdc++.h>
using namespace std;

int recursive(vector<int> &num, int x, vector<int>& dp)
{
    if (x == 0) return 0;
    if (x < 0) return INT_MAX;

    int mn = INT_MAX;

    if (dp[x] != -1) return dp[x];

    for (int i = 0; i < num.size(); i++) {
        int ans = recursive(num, x - num[i], dp);

        if (ans != INT_MAX) {
            mn = min(mn, ans + 1);
        }
    }

    return dp[x] = mn;
}

int tabulation(vector<int>& num, int x) {
    if (x == 0) return 0;

    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < num.size(); j++) {
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    if (dp[x] == INT_MAX) return -1;
    return dp[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. Minimum elements
	// https://www.naukri.com/code360/problems/minimum-elements_3843091
	
	int n;
	cin >> n;

	vector<int> nums(n);

	for (int i = 0; i < n; i++) cin >> nums[i];

	int x;
	cin >> x;

	cout << tabulation(nums, x) << "\n";

	vector<int> dp(x + 1, -1);
	cout << recursive(nums, x, dp);
			
	return 0;
}
