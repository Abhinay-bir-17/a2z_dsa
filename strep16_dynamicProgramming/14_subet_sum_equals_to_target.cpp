// recursion method , works
#include <bits/stdc++.h>
int code(int n, int k, vector<int>&ar) {
	if (k == 0)return 1;
	if (n < 0 || k < 0)return 0;

	if (code(n - 1, k - ar[n], ar))return 1;
	if (code(n - 1, k, ar))return 1;

	return 0;
}
bool subsetSumToK(int n, int k, vector<int> &ar) {
// Write your code here abhinay bir

	if (code(n - 1, k, ar))return true;
	else return false;
}

// bottom up approach

// learned it from pepcoding trage sum subsets question
#include <bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &ar) {
	// Write your code here.
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
