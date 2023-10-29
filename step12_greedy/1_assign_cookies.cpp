#include<bits/stdc++.h>
int assignCookie(vector<int> &g, vector<int> &s) {
	// Write your code here
	int n = g.size(); int m  = s.size();
	sort(g.begin(), g.end());
	sort(s.begin(), s.end());
	int ans = 0;
	int i = 0, j = 0;
	while (i < n && j < m) {
		if (s[j] >= g[i]) {
			i += 1; j += 1;
		} else j += 1;
		ans = i;
	}	return ans;
}
