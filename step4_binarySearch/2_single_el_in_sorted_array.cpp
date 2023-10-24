// naive aka brute force soln
class Solution {
public:
	int singleNonDuplicate(vector<int>& ar) {
		int n = ar.size();
		for (int i = 0; i < n - 2;)
		{
			if (ar[i] != ar[i + 1]) {
				return ar[i];
			} i += 2;

		} return ar[n - 1];
	}
};


// xo solution
// naive aka brute force soln
class Solution {
public:
	int singleNonDuplicate(vector<int>& ar) {
		int n = ar.size();
		int ans = 0;
		for (int i = 0; i < n; i += 1)
		{
			ans = ans ^ ar[i];

		} return ans;
	}
};

// binary search
class Solution {
public:
	int singleNonDuplicate(vector<int>& ar) {
		int n = ar.size();
		if (n == 1)return ar[0];
		if (ar[0] != ar[1])return ar[0];
		if (ar[n - 1] != ar[n - 2])return ar[n - 1];
		int l = 1, r = n - 2;
		while (l <= r) {
			int m = (l + r) / 2;
			// found the el at mth postn
			if (ar[m] != ar[m - 1] && ar[m] != ar[m + 1])return ar[m];
			// if m is odd nd its odd even-> shift r to m-2 as it shud be even odd
			if ( m & 1) {
				if (ar[m + 1] == ar[m])r = m - 1; else l = m + 1;
			} else {
				if ( ar[m - 1] == ar[m])r = m - 2;
				else l = m + 2;
			}
		}
		return "wtf";
	}
};


