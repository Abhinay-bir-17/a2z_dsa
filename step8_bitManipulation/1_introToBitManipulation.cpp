vector<int> bitManipulation(int n, int i) {
	// Write your code here abhinay, focus FOCUS
	i -= 1;
	int temp  = n;
	int aux = 1 << i;
	// get the bit val at ith position
	if ( (aux & temp))cout << "1";
	else cout << "0";
	cout << " ";

	/* set the bit at ith position: at ith
	position or it with 1 nd do or with 0 elsewhere
	*/

	cout << (aux | temp) << " ";

	// clear the bit at the ith positn

	cout << ( ~aux & temp ) ;
}