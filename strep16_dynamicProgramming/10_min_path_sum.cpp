
int minSumPath(vector<vector<int>> &ar) {
	// Write your code here.
	int m = ar.size();
	int n = ar[0].size(); // colms

	for (int i = 1; i < n; i++)ar[0][i] += ar[0][i - 1];
	for (int i = 1; i < m; i++)ar[i][0] += ar[i - 1][0];

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			ar[i][j] +=   min(ar[i - 1][j] , ar[i][j - 1]);
		}
	}
	return ar[m - 1][n - 1];
}