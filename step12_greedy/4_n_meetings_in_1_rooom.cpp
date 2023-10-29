

// using vector of paris
int maxMeetings(int  start[], int end[], int n) {
	vector<pair<int, int>> meet;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		meet.push_back({end[i], start[i]});
	}
	// sorts using 'ending time' of each pair hence we put ending time as first element
// of each pair, if we have put 'start time' as 1st element in pair then it would sort by
// by 'start time' which we dont want;  here we r sorting by ascending of end time
	// hence we greedily pick the ones with earliest ending times
	sort(meet.begin(), meet.end());

	int ans = 1, aux = meet[0].first;
	for (int i = 1; i < n; i++) {
		cout << "aux:" << aux << endl;
		if (meet[i].second > aux) {
			ans += 1;
			aux = meet[i].first;
		}
	} return ans;
}