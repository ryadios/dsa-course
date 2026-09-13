#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& arr, int s, int n) {
    long long prev2 = 0, prev1 = arr[s];

    for (int i = s + 1; i <= n; i++) {
        long long curr = max(arr[i] + prev2, prev1);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 1. House Robbery II
	// https://www.naukri.com/code360/problems/house-robber_839733

	return 0;
}
