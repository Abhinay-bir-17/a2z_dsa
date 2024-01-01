typedef long long ll;
const ll M = 1e9 + 7;
int findWays(vector<int>& ar, int k) {
	// Write your code here.
	int n = ar.size();
	vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 1));
	for (int i = 1; i <= k; i++)dp[0][i] = 0; // empty set cant make sum other than 0
	for (int i = 1; i <= n; i++) { // i is rows
		for (int j = 1; j <= k; j++) { // here j means k , so j goes from 1,2,....k
			if ( ar[i - 1] > j)dp[i][j] = (dp[i - 1][j]) % M;
			else {
				dp[i][j] =  ( (dp[i - 1][j])  + (dp[i - 1][j - ar[i - 1]]) ) % M;
			}
		}
	}
	return dp[n][k];
}