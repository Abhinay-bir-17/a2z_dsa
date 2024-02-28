bool isKthBitSet(int n, int k) {
	// Write your code here.
	k -= 1;
	int temp = 1 << k;
	if ( temp & n) {cout << "YES";}
	else cout << "NO";

}