// coded using {1,1,2} as example
void code(vector<vector<int>>&ans, vector<int> aux, vector<int>ar, int n, int i) {
	if (i == n) {
		ans.push_back(aux);
		return;
	}

	aux.push_back(ar[i]);
	code(ans, aux, ar, n, i + 1);
	aux.pop_back();

	int prev = ar[i];

	while (i < n) {
		if (ar[i] != prev) {
			aux.push_back(ar[i]);
			code(ans, aux, ar, n, i + 1);
			aux.pop_back();
			code(ans, aux, ar, n, i + 1);
			prev = ar[i];
		} i += 1;
	}

}

vector<vector<int>> getUniqueSubsets(vector<int>& ar) {
	// Write Your Code Here
	int n = ar.size();
	vector<vector<int>>ans;
	vector<int>aux;
	code(ans, aux, ar, n, 0);
	n = ans.size();
	sort(ans, ans + n);
	return ans;
}