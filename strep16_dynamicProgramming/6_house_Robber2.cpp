// tabulaton approach on 22 dec 2023 , 6:16 pm , it works
#include <bits/stdc++.h>
long long int houseRobber(vector<int>& ar) {
	// Write your code here abhinay bir
	int n = ar.size();

	if (n == 1)return ar[0];
	else if (n == 2)return 0;
	else if (n == 3)return max(ar[0], max(ar[1], ar[2]));

	vector<long long int>dp(n, 0);
	dp[0] = ar[0]; dp[1] = max(ar[0], ar[1]);
	for (int i = 2; i < n - 1; i++) {
		dp[i] = max( dp[i - 1], ar[i] + dp[i - 2]);
	}

	vector<long long int>aux(n, 0);
	aux[1] = ar[1];
	for (int i = 2; i <= (n - 3); i++) {
		aux[i] = max(aux[i - 1],  ar[i] + aux[i - 2]);
	}

	dp[n - 1] = max(dp[n - 2], ar[n - 1] + aux[n - 3]);
	return dp[n - 1];
}