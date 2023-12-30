#include <bits/stdc++.h>
int minimumPathSum(vector<vector<int>>& ar, int n) {
	// Write your code here.
	int r = ar.size();
	int c = ar[r - 1].size();

	int temp = 2;
	for (int i = 1; i < r; i++) {

		for (int j = 0; j < temp; j++) {
			if ( (j <= (i - 1))  &&  ((j - 1) >= 0) )ar[i][j] += min(  ar[i - 1][j], ar[i - 1][j - 1] );
			else if ( (j - 1) >= 0)ar[i][j] += ar[i - 1][j - 1];
			else ar[i][j] += ar[i - 1][j];
		}
		temp += 1;
	}

	//return min of last row
	// temp = 0;cout<<"dp is now:"<<endl;
	// for(int i=0;i<r;i++){
	//     for(int j=0;j<=temp;j++){
	// 		cout<<ar[i][j]<<" ";
	//     }
	// 	cout<<endl;temp+=1;
	// }
	temp = INT_MAX;
	for (int i = 0; i < c; i++) {
		// cout<<ar[r-1][i]<<" ";
		temp = min(temp, ar[r - 1][i]);
	}
	return temp;
}