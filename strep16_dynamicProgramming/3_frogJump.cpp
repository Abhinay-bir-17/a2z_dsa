typedef long long ll;
typedef vector<int> vi;
const ll inf = 1e9 + 7;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
ll fact[N];
#include <bits/stdc++.h>
using namespace  std;

// recursive soltuion: from left to right
void code(int n, vi ar, int i, int sum, int &ans) {
	if (i == (n - 1)) {
		if (sum < ans)ans = sum;
		return;
		// cout<<"ans is:"<<ans;
	} //cout<<"yo"<<endl;
	if ((i + 1) < n)code(n, ar, i + 1, sum + abs(ar[i + 1] - ar[i]), ans);
	if ((i + 2) < n)code(n, ar, i + 2, sum + abs(ar[i + 2] - ar[i]), ans);
}
int frogJump(int n, vector<int> &ar) {
	// Write your code here.
	int ans = INT_MAX;
	code(n, ar, 0, 0,  ans);
	return ans;
}

typedef long long ll;
typedef vector<int> vi;
const ll inf = 1e9 + 7;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
ll fact[N];
#include <bits/stdc++.h>
using namespace  std;

// tabulation: bottom up
int frogJump(int n, vector<int>&ar) {
	vector<int> dp(n);
	dp[0] = 0; dp[1] = abs(ar[1] - ar[0]);
	for (int i = 2; i < n; i++) { // could have done i=2, i<=n when dp[1]= 0, dp[2] = ar[1]-ar[0]
		dp[i] = min( dp[i - 2] + abs(ar[i] - ar[i - 2]) , dp[i - 1] + abs(ar[i] - ar[i - 1]) );
	} return dp[n - 1];
}
// using memorization(top down) and recursion (right to left):
#include <bits/stdc++.h>
using namespace  std;

int code(int n, vector<int>ar, vector<int>&dp) {
	if (n == 0)return 0;
	int l, r ;
	if (dp[n] != -1)return dp[n];
	if (n >= 1)l = code(n - 1, ar, dp) + abs(ar[n] - ar[n - 1]);
	if (n > 1) r = code(n - 2, ar, dp) + abs(ar[n] - ar[n - 2]);
	else r = INT_MAX;
	dp[n] = min(l, r);
	return dp[n];
}
int frogJump(int n, vector<int> &ar) {
	// Write your code here abhinay bir you can do it okay? bruh!!!
	vector<int> dp(n, -1);
	return code(n - 1, ar, dp);

}




