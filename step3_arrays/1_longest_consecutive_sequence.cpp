class Solution {
public:
  int longestConsecutive(vector<int>& ar) {
    // write code below abhinay bir you can do it okay!!!!!!!!!!!!!!!!!!!!!!! abhinay never give up okay lol?
    int n = ar.size();
    if (n <= 1)return n;
    sort(ar.begin(), ar.end());
    // 0 0 1 2 3 4 5 6 7 8
    int ans = 1;
    int temp = 1;
    for (int i = 0; i < n - 1; i++) {
      if (ar[i] == (ar[i + 1] - 1)) {
        temp += 1;
      } else if (ar[i] < ar[i + 1]) {
        temp = 1;
      } ans = max(ans, temp);
    } return ans;
  }
};