#include <bits/stdc++.h>
void fastscan(int &number)
{	bool negative = false;
	register int c;
	number = 0;
	c = getchar();
	if (c == '-')
	{	negative = true;
		c = getchar();
	} for (; (c > 47 && c < 58); c = getchar())
		number = number * 10 + c - 48;
	if (negative)
		number *= -1;
}
using namespace std;
#define FOR(i,a,b) for(auto i = (a); i < (b); ++i)
#define FORD(i,a,b) for(int i = (a); i >= (b); --i)
#define RI0n(i,n) FOR(i,0,(n))
#define RI1n(i,n) FOR(i,1,(n))
#define RI0n1(i,n) FOR(i,0,(n)-1)
#define RDn10(i,n) FORD(i,(n)-1,0)
// #define push_back pb;
typedef long long ll;
typedef vector<int> vi;
const ll inf = 1e9 + 7;
const int M = 1e9 + 7;
const int N = 1e5 + 10;
ll fact[N];

// tc is O(n) as dp(5)-> dp(4)->dp(3)->dp(2)->dp(1), for dp(4) = dp(3)+dp(2), its already
// calcculated .
// s.c is O(n) for n recursive calls in call stack, anothre O(n) for dp vector

// this is memorization method
void code3(vi &dp, int n) {
	if (n < 2)return n;
	if (dp[n] != -1)return dp[n];
	dp[n] = code3[n - 1] + code3[n - 2];
	return dp[n];
}

// tc is O(n) , and s.c is only O(n) for dp vector , tabluation
// means bottom up
void tabulation_method(vi &dp, int n) {
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i <= n; i++)dp[i] = dp[i - 1] + d[i - 2];
	cout << dp[n] << endl;
}

// time complexity is O(n), space complexity is constant.
void better_way(vi dp, int n) {
	if (n < 2) {cout << n << endl; return;}
	int a = 0, b = 1, sum = 0;
	for (int i = 2; i <= n; i++) {
		sum = a + b;
		a = b;
		b = sum;
	}
	cout << sum << endl;
}

void code() {
	// code here abhinay bir come on you can do it okay.
	int n; cin >> n;
	//if (n == 0 || n == 1) {cout << n << endl; return;}
	vi dp(n + 1, -1);
	cout << code3(dp, n);
}
int main()
{
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input_2023.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output_2023.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin >> t; while (t--)code();
}