/*
struct Item{
    int value;
    int weight;
};
*/

bool comp(Item c, Item b) {
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double).weight;
	return r1 > r2;
}
double fractionalKnapsack(int w, Item ar[], int n) {
	// come on abhinay bir, you can do it
// logic is to choose the item 1st with all its weight if it gives highes value per unit weight
// ex :values ={60,100,120} , weights = {10,20,30} so 1st item give 6 value/weight, 2nd item gives
// 5 per unit, 3rd: 4 per unit, so choose all of 1st item, and of 2nd item if their combined
// weight  is less than w = 50, for remaing choose 20 parts of 3 rd item = (120/30)*20 = 80
// so ans = 60 + 100 + 80 = 240

	sort(ar, arr + n, comp);
	double ans = 0;
	int i = 0;
	while (w > 0 && i < n) {
		if (ar[i].weight <= w) {
			ans += ar[i].value;
			w -= ar[i].weight;
		} else {
			ans += w * (ar[i].value / ar[i].weight); w = 0;
		}
		i += 1;
	} return ans;
}

// submitted code:
#include<bits/stdc++.h>
class Solution
{
public:
	//Function to get the maximum total value in the knapsack.
	static bool comp(Item c, Item b) {
		double r1 = (double)c.value / (double)c.weight;
		double r2 = (double)b.value / (double)b.weight;
		return r1 > r2;
	}
	double fractionalKnapsack(int w, Item ar[], int n)
	{
		// Your code here please with good brrrrr
		sort(ar, ar + n, comp);
		double ans = 0;
		int i = 0;
		while (w > 0 && i < n) {
			if (ar[i].weight <= w) {
				ans += ar[i].value;
				w -= ar[i].weight;
			} else {
				ans += (double)w * (ar[i].value / (double)ar[i].weight); w = 0;
			}
			i += 1;
		} return ans;

	}

};