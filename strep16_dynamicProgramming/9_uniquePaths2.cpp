const int M = 1e9 + 7;
int mazeObstacles(int m, int n, vector< vector< int> > &ar) {
	// Write your code here
	int temp = 1;
	for (int i = 0; i < n; i++) {
		if (ar[0][i] == -1)temp = 0;
		if (temp) {
			ar[0][i] = 1;
		}
	}

	temp = 1;
	for (int i = 0; i < m; i++) {
		if (ar[i][0] == -1)temp = 0;
		if (temp) {
			ar[i][0] = 1;
		}
	}

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (ar[i][j] != -1) {
				if (ar[i - 1][j] != -1)ar[i][j] =  (ar[i][j] + ar[i - 1][j]) % M;
				if (ar[i][j - 1] != -1)ar[i][j] =  (ar[i][j] + ar[i][j - 1]) % M;

			}
		}
	}
	return ar[m - 1][n - 1];
}