vector<int> MinimumCoins(int n)
{
	// Write your code here abhinay bir okay????
	vector<int> ar = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
	vector<int> ans;
	for (int i = 8; i >= 0;) {
		if (n == 0)break;
		if (ar[i] > n)i -= 1;
		else {
			ans.push_back(ar[i]);
			n -= ar[i];
		}
	} return ans;
}