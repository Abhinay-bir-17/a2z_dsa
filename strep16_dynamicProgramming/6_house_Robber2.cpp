// tabulation method: O(n) with constant space complexity
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

