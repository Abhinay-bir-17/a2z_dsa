// recursion , works on 23rd dec

#include<bits/stdc++.h>
int code(int r, int c, vector<vector<int>>ar) {
	if (r < 0)return 0;

	int temp = INT_MIN;
	for (int i = 2; i >= 0; i--) {
		if (i != c)
			temp = max( temp, ar[r][i] +  code(r - 1, i, ar) );
	}
	return temp;
}
int ninjaTraining(int n, vector<vector<int>> &ar)
{
	// you can do it abhinay bir dont give up mate
	int ans = INT_MIN;
	for (int i = 2; i >= 0; i--) {

		ans = max (ans, ar[n - 1][i] + code(n - 2, i, ar));
	}
	return ans;
}

// memorization , giving tle
#include<bits/stdc++.h>
int code(int r, int c, vector<vector<int>>ar, vector<vector<int>>&dp) {
	if (r == 0) {
		int temp = INT_MIN;
		for (int i = 0; i <= 2; i++) {
			if (i != c)temp = max(temp, ar[0][i]);
		} return temp;
	}
	int temp = INT_MIN;

	for (int i = 2; i >= 0; i--) {
		if (i != c) {
			if (dp[r][i] == -1) {
				dp[r][i] = ar[r][i] +  code(r - 1, i, ar, dp);
				temp = max( temp,  dp[r][i]);

			}
			else temp =  max(temp, dp[r][i]);
		}
	}
	return temp;
}
int ninjaTraining(int n, vector<vector<int>> &ar)
{
	// you can do it abhinay bir dont give up mate
	int ans = INT_MIN;
	vector<vector<int>>dp(n, vector<int>(3, -1));
	for (int i = 2; i >= 0; i--) {

		ans = max (ans, ar[n - 1][i] + code(n - 2, i, ar, dp));
	}
	// cout << "dp vec is:" << endl;
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < 3; j++) {
	// 		cout << dp[i][j] << " ";
	// 	} cout << endl;
	// }
	return ans;
}

// bottom up approach:
int ninjaTraining(int n, vector<vector<int>>&ar) {
	for (int i = 1; i < n; i++) {

		for (int j = 0; j <= 2; j++) {
			int temp = INT_MIN;
			for (int k = 0; k <= 2; k++) {
				if (j != k) {
					temp = max(temp, ar[i - 1][k]);
				}
			} ar[i][j] = temp + ar[i][j];
		}
	}
	int ans = INT_MIN;
	for (int i = 0; i <= 2; i++)ans = max(ans, ar[n - 1][i]); return ans;
}