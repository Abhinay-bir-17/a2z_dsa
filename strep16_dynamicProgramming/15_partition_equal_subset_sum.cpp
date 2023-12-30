#include <bits/stdc++.h>
bool canPartition(vector<int> &ar, int n) {

	// Write your code here.
	int k = 0;
	for (int i = 0; i < n; i++)k += ar[i];
	if (k & 1) {
		return false;
	}
	k = k / 2;
	vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, true));
	for (int i = 1; i <= k; i++)dp[0][i] = false; // empty set cant make sum other than 0
	for (int i = 1; i <= n; i++) { // i is rows
		for (int j = 1; j <= k; j++) { // here j means k , so j goes from 1,2,....k
			if ( ar[i - 1] > j)dp[i][j] = dp[i - 1][j];
			else {
				if (dp[i - 1][j])dp[i][j] = true;
				else dp[i][j] = dp[i - 1][j - ar[i - 1]];
			}
		}
		if (dp[i][k])return true;
	}
	return dp[n][k];
}
