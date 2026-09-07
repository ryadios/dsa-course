#include <bits/stdc++.h>
using namespace std;

int countDistinctWays(int i, int n, vector<int> &dp) {
	if (i == n) return 1;	
	if (i > n) return 0;

	if (dp[i] != -1) return dp[i];

	return countDistinctWays(i + 1, n) + countDistinctWays(i + 2, n);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// 1. Count ways to reach the N-th stairs
	// https://www.naukri.com/code360/problems/count-ways-to-reach-nth-stairs_798650
	
	return 0;
}
