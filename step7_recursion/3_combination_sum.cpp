void code(vector<vector<int>>&ans, vector<int>ar, vector<int>aux, int n, int k, int i, int sum) {
	// write from here such a woke answer man lmao lmao lol
	if (sum == k) {
		ans.push_back(aux); return;
	}
	if (i == n) {
		if (sum == k) {ans.push_back(aux);}
		return;
	}
	if (sum > k) {
		return;
	}
	if (sum < k) {
		aux.push_back(ar[i]);
		code(ans, ar, aux, n, k, i, sum + ar[i]);
		aux.pop_back();
		code(ans, ar, aux, n, k, i + 1, sum);

	}


}
vector<vector<int>> combSum(vector<int> &ar, int k)
{
	// Write your code here.
	vector<vector<int>> ans;
	sort(ar.begin(), ar.end());
	vector<int>aux; int n = ar.size();
	code(ans, ar, aux, n, k, 0, 0); return ans;
}