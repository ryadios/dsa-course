#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long solve(int n, vector<long long>& dp) {
    if (n == 1) return 0;
    if (n == 2) return 1;

    if (dp[n] != - 1) return dp[n];

    return dp[n] = (1LL * (n - 1) * (solve(n - 1, dp) + solve(n - 2, dp))) % MOD;
}

long long tabulation(int n) {

    long long prev2 = 0, prev1 = 1;

    for (int i = 3; i <= n; i++) {
        int curr = (1LL * (i - 1)) * (prev1 + prev2) % MOD;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. Count defragments
	// https://www.naukri.com/code360/problems/count-derangements_873861
	
	long long n;
	cin >> n;

	vector<long long> dp(n + 1, -1);
	cout << solve(n, dp) << "\n";

	cout << tabulation(n) << "\n";
	
	return 0;
}
