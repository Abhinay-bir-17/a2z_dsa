// tabulation method
int minimizeCost(int n, int k, vector<int> &ar) {
	// Write your code here.
	if (n == 1)return 0;
	if (n == 2)return abs(ar[1] - ar[0]);
	vector<int> dp(n, 0); dp[0] = 0; dp[1] = abs(ar[1] - ar[0]);
	for (int i = 2; i < n; i++) {
		int ans = INT_MAX;
		for (int j = 1; j <= k; j++) {

			if ( (i - j) >= 0)
				ans = min(ans, dp[i - j] + abs(ar[i] - ar[i - j]));
			else break;
		}
		dp[i] = ans;
	} return dp[n - 1];
}



//recursive i.e top down solution
#include <bits/stdc++.h>
using namespace  std;
int code(int n, int k, vector<int> &ar) {
	if (n == 0)return 0;

	int aux = INT_MAX;
	for (int i = 1; i <= k; i++) {
		if ((n - i) >= 0) aux = min(aux, code(n - i, k, ar) + abs(ar[n] - ar[n - i]));
		else break;
	}
	return aux;
}
int minimizeCost(int n, int k, vector<int> &ar) {
	// Write your code here.
	return code(n - 1, k, ar);
}

// using memorization i.e bottom up


//recursive i.e top down solution
#include <bits/stdc++.h>
using namespace  std;
int code(int n, int k, vector<int> &ar, vector<int>&dp) {
	if (n == 0)return 0;
	if (dp[n] != -1)return dp[n];
	int aux = INT_MAX;
	for (int i = 1; i <= k; i++) {
		// if(dp[n-i]!=0)return dp[n-i];
		if ((n - i) >= 0) {
			aux = min(aux, code(n - i, k, ar, dp) + abs(ar[n] - ar[n - i]));
		}
		else break;
	}
	dp[n] = aux;
	return aux;
}
int minimizeCost(int n, int k, vector<int> &ar) {
	// Write your code here.
	vector<int>dp(n, -1);
	return code(n - 1, k, ar, dp);
}