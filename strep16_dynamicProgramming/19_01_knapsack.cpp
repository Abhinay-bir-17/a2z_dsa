// recursion, gives tle
#include <bits/stdc++.h>
int code(int n, vector<int>we, vector<int>val, int w) {
	if (w <= 0 || n < 0)return 0;
	int a, b;
	if (we[n] <= w) a = val[n] + code(n - 1, we, val, w - we[n]);
	else  a = INT_MIN;

	b =  code(n - 1, we, val, w);
	return max(a, b);
}

int knapsack(vector<int> we, vector<int> val, int n, int w)
{
	// Write your code here abhinay bir okay?
	return code(n - 1, we, val, w);
}

// recursion with memorization: works
#include <bits/stdc++.h>
int code(int n, vector<int>we, vector<int>val, int w, vector<vector<int>>&dp) {
	if (w <= 0 || n < 0)return 0;
	if (dp[n][w] != -1)return dp[n][w];
	int a, b;
	if (we[n] <= w) a = val[n] + code(n - 1, we, val, w - we[n], dp);
	else  a = INT_MIN;

	b =  code(n - 1, we, val, w, dp);
	return dp[n][w] = max(a, b);
}

int knapsack(vector<int> we, vector<int> val, int n, int w)
{
	// Write your code here abhinay bir okay?
	vector<vector<int>> dp(n, vector<int>(w + 1, -1));
	return code(n - 1, we, val, w, dp);
}

// tabulation method : worked bro insane
#include <bits/stdc++.h>
int knapsack(vector<int> we, vector<int> val, int n, int w)
{
	// Write your code here abhinay bir okay?
	vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if ( we[i - 1] > j)dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = max(  dp[i - 1][j],  val[i - 1] + dp[i - 1][j - we[i - 1]]);
			}
		}
	} return dp[n][w];

}

// 0 0 1 2 3 4 5
// 0 0 0 0 0 0 0
// 1 0 5 5 5 5 5
// 2 0 5 5 9 9 9
// 3 0
// 4 0

// 1
// 4
// 1 2 4 5 : we
// 5 4 8 6 : val
// 5       : w
