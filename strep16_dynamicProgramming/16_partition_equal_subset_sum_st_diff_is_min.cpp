int minSubsetSumDifference(vector<int>& ar, int n) {
	// Write your code here abhinay bir bro let push this  on github
	int k = 0;
	for (int i = 0; i < n; i++)k += ar[i];
	// cout<<"k is:"<<k<<endl;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1));

	for (int i = 1; i <= k; i++)dp[0][i] = 0; // empty set cant make sum other than 0
	for (int i = 1; i <= n; i++) { // i is rows
		for (int j = 1; j <= k; j++) { // here j means k , so j goes from 1,2,....k
			if ( ar[i - 1] > j)dp[i][j] = dp[i - 1][j];
			else {
				if (dp[i - 1][j])dp[i][j] = 1;
				else dp[i][j] = dp[i - 1][j - ar[i - 1]];
			}
		}
	}


	int ans;
	for (int i = 0; i <= (k / 2); i++) {
		// cout<<"i is:"<<i<<", its val:"<<dp[n][i]<<endl;
		if (dp[n][i])ans = i;
	}
	return (k - 2 * ans);
}
