void code(vector<int>&ans, vector<int>ar, int n, int i, int sum) {
	if (i == n) {
		ans.push_back(sum);
		return;
	}
	code(ans, ar, n, i + 1, sum + ar[i]);
	code(ans, ar, n, i + 1, sum);
}
vector<int> subsetSum(vector<int> &ar) {
	// Write your code here.
	int n = ar.size();
	vector<int> ans;
	code(ans, ar, n, 0, 0);
	sort(ans.begin(), ans.end());
	return ans;
}