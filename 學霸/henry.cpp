/*
for a point (x,y) to be suabar
there can't exist a point in range (>= x,  >= y)
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int solve()
{
	// get input
	int n;
	scanf("%d", &n);

	ii inp[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &inp[i].first);
	for (int i = 0; i < n; i++)
		scanf("%d", &inp[i].second);
	sort(inp, inp + n);

	// solve
	int ans = 0, prevX = INT_MAX, mxY = 0;
	bool selected[n];
	memset(selected, false, sizeof(selected));
	for (int i = n - 1; i >= 0; i--) {
		int x = inp[i].first;
		int y = inp[i].second;

		if (prevX != x) {
			// check if there is anyone in >= y
			if (y > mxY) {
				mxY = y;
				selected[i] = true;
			}
			prevX = x;
		} else {
			if (inp[i].second == inp[i + 1].second && selected[i + 1]) {
				selected[i] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
		if (selected[i])
			ans++;
	return ans;
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
		printf("%d\n", solve());

	return 0;
}
