#include <bits/stdc++.h>
using namespace std;

// Top down approach
int fib(int n, vector<int> &dp) {
	if (n == 0 || n == 1) return n;

	if (dp[n] != -1) return dp[n];

	dp[n] = fib(n - 1, dp) + fib(n - 2, dp);

	return dp[n];
}

// Bottom up approach (tabulation)
int fib(int n) {
	vector<int> dp(n + 1, -1);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

// Use curr, prev1 and prev2 variables in bottom up approach for space optimisation from O(n) -> O(1)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> dp(n + 1, -1);
	cout << fib(n, dp) << '\n';

	cout << fib(n);
		
	return 0;
}
