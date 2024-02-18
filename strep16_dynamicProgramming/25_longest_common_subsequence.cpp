// pure recursion it works
int code(string ar, string br, int m, int n, int ind, int indd) {
	if (ind == -1 || indd == -1)return 0;
	if (ar[ind] == br[indd])return 1 + code(ar, br, m, n, ind - 1, indd - 1);
	else if (ar[ind] != br[indd]) {
		return max( code(ar, br, m, n, ind - 1, indd), code(ar, br, m, n, ind, indd - 1));
	}
}

int lcs(string ar, string br)
{
	//Write your code here
	int m = ar.size(); int n = br.size();
	return code(ar, br, m, n, m - 1, n - 1);
}

//recursion with memorization
int code(string ar, string br, int m, int n, int ind, int indd, vector<vector<int>>&dp) {
	if (ind == -1 || indd == -1)return 0;
	if (dp[ind][indd] != -1)return dp[ind][indd];
	if (ar[ind] == br[indd])return  dp[ind][indd] = 1 + code(ar, br, m, n, ind - 1, indd - 1, dp);
	else if (ar[ind] != br[indd]) {
		return dp[ind][indd] = max( code(ar, br, m, n, ind - 1, indd, dp), code(ar, br, m, n, ind, indd - 1, dp));
	}
}

int lcs(string ar, string br)
{
	//Write your code here
	int m = ar.size(); int n = br.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
	return code(ar, br, m, n, m - 1, n - 1, dp);
}