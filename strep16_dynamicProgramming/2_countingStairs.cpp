
// recursion method: giving tle ofc
int code3(int i, int n) {
	if (i == n)return 1;
	if (i > n)return 0;

	return (code3(i + 1, n), code3(i + 2, n));
}
void code() {
	// code here abhinay bir come on you can do it okay.
	int n; cin >> n;

}

// memorization method: giving tle!
#include <bits/stdc++.h>
int code3(int i, int n, vector<int>dp) {
	if (i == n)return 1;
	if (i > n)return 0;
	if (dp[i] != -1)return dp[i];
	dp[i] = (code3(i + 1, n, dp) + code3(i + 2, n, dp));
	return dp[i];
}
int countDistinctWays(int n) {
	//  Write your code here.
	vector<int> dp(n + 1, -1);

	return code3(0, n, dp);
}

//