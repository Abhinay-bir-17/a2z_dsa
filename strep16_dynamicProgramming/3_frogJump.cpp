typedef long long ll;
typedef vector<int> vi;
const ll inf = 1e9 + 7;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
ll fact[N];
#include <bits/stdc++.h>
using namespace  std;

// recursive soltuion: from right to left, aka top down
#include <bits/stdc++.h>
int code(int n, vector<int>&ar) {
	if (n == 0)return 0;
	if (n == 1)return (abs(ar[1] - ar[0]));
	return min(abs(ar[n] - ar[n - 1]) + code(n - 1, ar) , abs(ar[n] - ar[n - 2]) + code(n - 2, ar) );

}
int frogJump(int n, vector<int> &ar)
{
	// Write your code here.
	return code(n - 1, ar);
}

typedef long long ll;
typedef vector<int> vi;
const ll inf = 1e9 + 7;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
ll fact[N];
#include <bits/stdc++.h>
using namespace  std;

// tabulation method aka bottom up
#include <bits/stdc++.h>
int frogJump(int n, vector<int> &ar)
{	vector<int>dp(n, 0);
	if (n == 1)return 0;
	if (n == 2)return abs(ar[1] - ar[0]);
	dp[1] = abs(ar[1] - ar[0]);

	for (int i = 2; i < n; i++) {
		dp[i] = min( dp[i - 1] + abs(ar[i] - ar[i - 1]), dp[i - 2] + abs(ar[i] - ar[i - 2]));
	}
	return dp[n - 1];
}
// using memorization(top down) and recursion (right to left):
#include <bits/stdc++.h>
int code(int n, vector<int>&ar, vector<int>&dp) {
	if (n == 0)return 0;
	if (n == 1)return (abs(ar[1] - ar[0]));
	if (dp[n] != -1)return dp[n];
	dp[n] =  min(abs(ar[n] - ar[n - 1]) + code(n - 1, ar, dp) , abs(ar[n] - ar[n - 2]) + code(n - 2, ar, dp) );
	return dp[n];
}
int frogJump(int n, vector<int> &ar)
{
	// Write your code here.
	vector<int>dp(n, -1);
	return code(n - 1, ar, dp);
}