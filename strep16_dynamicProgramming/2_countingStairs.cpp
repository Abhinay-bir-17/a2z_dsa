

// tablulaiton method aka bottom up
class Solution {
public:
	int code(vector<int>&dp, int n) {
		if (n < 2)return 1;
		if (dp[n] != -1)return dp[n];
		dp[n] = code(dp, n - 1) + code(dp, n - 2);
		return dp[n];
	}
	int climbStairs(int n) {
		vector<int>dp(n + 1, -1);
		return code(dp, n);
	}
};

//  best method
int climbStairs(int n) {
	if (n < 2)return 1;
	int a = 1, b = 1, sum = 0;
	for (int i = 2; i <= n; i++) {
		sum = a + b;
		a = b; b = sum;
	} return sum;
}