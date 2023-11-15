// tabulation method: O(n) with constant space complexity

// i submitted this nd it worked lool
#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &ar) {
	// Write your code here abhinay bir
	int n = ar.size();
	if (n == 1)return ar[0];
	if (n == 2)return max(ar[0], ar[1]);
	int a = ar[0];
	int b = max(ar[0], ar[1]);
	for (int i = 2; i < n; i++) {
		int temp = b;
		b = max(b, a + ar[i]);
		a = temp;
	} return max(a, b);
}

// recursion approach: doing on my own, from left to right : WORKED
int code(int i, int n, vector<int>ar) {
	if (i >= n)return 0;

	int pick = ar[i] + code(i + 2, n, ar);
	int notPick = code(i + 1, n, ar);
	return max(pick, notPick);


}
#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &ar) {


	int n = ar.size();
	return code(0, n, ar);
}

// memorization + recursion approach: doing on my own, from left to right : worked.
int code(int i, int n, vector<int>ar, vector<int>&dp) {
	if (i >= n)return 0;
	if (dp[i] != -1)return dp[i];
	int pick = ar[i] + code(i + 2, n, ar, dp);
	int notPick = code(i + 1, n, ar, dp);
	dp[i] =  max(pick, notPick); return dp[i];
}
#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &ar) {


	int n = ar.size();
	vector<int>dp(n, -1);
	return code(0, n, ar, dp);
}