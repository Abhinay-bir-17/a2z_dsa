
// my code, didnt run for 29th test case
#include<bits/stdc++.h>
using namespace std;
void code(vector<vector<int>>&ans, vector<int> ar, vector<int>aux, int n, int k, int i, int sum) {
	if (sum > k) {
		return;
	}
	else if (sum == k) {
		// cout<<"sum:"<<sum<<endl;
		int b = 1;
		for (auto it : ans) {
			if (it == aux) {
				b = 0; break;
			}
		} if (b) {
			ans.push_back(aux);
		} return;
	} else if (i == n)return;
	else {
		aux.push_back(ar[i]);
		code(ans, ar, aux, n, k, i + 1, sum + ar[i]);
		aux.pop_back();
		code(ans, ar, aux, n, k, i + 1, sum);
	}
}
vector<vector<int>> combinationSum2(vector<int> &ar, int n, int k) {
	// Write your code here abhinay bir, never give up
	vector<vector<int>> ans;
	sort(ar.begin(), ar.end());
	vector<int>aux;
	code(ans, ar, aux, n, k, 0, 0);
	return ans;
}

// striver methd i.e lets say u have {1, 1, 1, 2, 2} ; k = 4 ;
// so at start u can pick all 5 el. lets say u pick 1st posn el i.e 1. choosin this removes the
// chance of pickin 2nd, 3rd el as 1st el of our array. so once we pick 1st '1', wht options we
// hve for 2nd el {1, ?} ?  we have 4 options now named {1,1,2,2}, if we pick 2 now aux is {1,1}
// choosing 2nd '1' removes chance of choosing 3d '1' as 2nd el as chosing it will give
// us same {1,1} aux. so now wht options we have? {1,2,2} we can choose '1', now aux={1,1,1}
// now options={2,2}, choosing '2 ' we get {1,1,1,2} sum > 4, we retrack to { 1,1,1} but now we
// cant choose 2nd '2' as it will give same {1,1,1,2}. so we retrack to {1,1} now we choose 1st '2'
// so aux = {1,1,2}sum = k;

//striver way and my implementation
#include<bits/stdc++.h>
using namespace std;
void code(vector<vector<int>>&ans, vector<int> ar, vector<int>aux, int n, int k, int i, int sum) {
	if (sum > k)return;
	else if (sum == k) {
		ans.push_back(aux); return;
	}
	else if (i == n)return;
	else if (sum < k) {
		aux.push_back(ar[i]);
		code(ans, ar, aux, n, k, i + 1, sum + ar[i]);
		aux.pop_back();
		int temp = ar[i];
		while (i < n) {
			if (ar[i] == temp) {
				i += 1;
			} else {
				temp = ar[i];
				aux.push_back(ar[i]);
				code(ans, ar, aux, n, k, i + 1, sum + ar[i]);
				aux.pop_back();
			}
		}
	}
}
vector<vector<int>> combinationSum2(vector<int> &ar, int n, int k) {
	// Write your code here abhinay bir, never give up
	vector<vector<int>> ans;
	sort(ar.begin(), ar.end());
	vector<int>aux;
	code(ans, ar, aux, n, k, 0, 0);
	return ans;
}