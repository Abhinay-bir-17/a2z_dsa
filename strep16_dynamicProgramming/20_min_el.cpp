#include <bits/stdc++.h>
int minimumElements(vector<int> &ar, int x)
{
	// Write your code here
	int n = ar.size();
	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
	for (int i = 1; i <= x; i++)dp[0][i] = x + 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			if (ar[i - 1] > j)dp[i][j] = dp[i - 1][j];
			else dp[i][j] = min( dp[i - 1][j], min( dp[i - 1][j - ar[i - 1]], dp[i][j - ar[i - 1]]) + 1);
		}
	}
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=x;j++){
	// 		cout<< dp[i][j]<<" ";
	// 	}cout<<endl;
	// }
//		cout<<"ans is:"<<dp[n][x]<<endl;
	if (dp[n][x] > x && x != 0) return -1;
	return dp[n][x];
}