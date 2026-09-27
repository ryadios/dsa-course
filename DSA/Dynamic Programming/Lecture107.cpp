#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z, vector<int> &dp) {
	if (n == 0) return 0;
	if (n < 0) return INT_MIN;

	if (dp[n] != -1) return dp[n];

	int a = solve(n - x, x, y, z, dp);
	int b = solve(n - y, x, y, z, dp);
	int c = solve(n - z, x, y, z, dp);

	return dp[n] = max(a, max(b, c)) + 1;
}

int tabulation(int n, int x, int y, int z) {
	vector<int> dp(n + 1, INT_MIN);
	dp[0] = 0;

	for (int i = 1; i <= n; i++) {
		if (i - x >= 0) {
			dp[i] = max(dp[i], dp[i - x] + 1);
		}

		if (i - y >= 0) {
			dp[i] = max(dp[i], dp[i - y] + 1);
		}

		if (i - z >= 0) {
			dp[i] = max(dp[i], dp[i - z] + 1);
		}
	}

	return max(0, dp[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. Cut into segments
	// https://www.naukri.com/code360/problems/cut-into-segments_1214651
	
	int n, x, y, z;
	cin >> n >> x >> y >> z;
		
	vector<int> dp(n + 1, -1);
	cout << max(0, solve(n, x, y, z, dp)) << "\n";

	cout << tabulation(n, x, y, z) << "\n";

	return 0;
}
