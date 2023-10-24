// naive soln: linear search
int findPeakElement(vector<int> &ar) {
	// Write your code here
	int n = ar.size();
	if (n == 1)return 0;
	else if (ar[0] > ar[1]) {
		return 0;
	}
	else if (ar[n - 1] > ar[n - 2])return n - 1;
	else {
		for (int i = 1; i < n - 1; i++) {
			if (ar[i] > ar[i - 1] && ar[i] > ar[i + 1]) {
				return i;
			}
		}
	}
	return -1;
}
// my own binary search method
int findPeakElement(vector<int> &ar) {
	int n = ar.size();
	if (n == 1)return 0;
	else if (ar[0] > ar[1]) {
		return 0;
	}
	else if (ar[n - 1] > ar[n - 2])return n - 1;
	else {
		int l = 1, r = n - 2; int m ;
		while (l <= r) {
			m = (l + r) / 2;
			if (ar[m] > ar[m - 1] && ar[m + 1] < ar[m])return m;
			else if (ar[m] < ar[m - 1] && ar[m] < ar[m + 1])l = m + 1;
			else if (ar[m] > ar[m - 1])l = m + 1;
			else if (ar[m] > ar[m + 1])r = m - 1;

		}
	} return -1;

}