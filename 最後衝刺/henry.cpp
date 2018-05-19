#include <bits/stdc++.h>
using namespace std;

struct Data {
	int start, end, score;
};

void solve()
{
	int n;
	cin >> n;
	assert(1 <= n && n <= 100);

	Data inp[n];
	for (int i = 0; i < n; i++) {
		int start, end, score;

		cin >> start >> end >> score;
		assert(start <= end);
		assert(0 <= start && start <= 24);
		assert(0 <= end && end <= 24);
		assert(1 <= score && score <= 1000);

		inp[i] = Data{start, end, score};
	}

	sort(inp, inp + n, [](const Data &a, const Data &b) -> bool {
		if (a.end == b.end) // WTF see case sorting.in
			return a.start < b.start;
		return a.end < b.end;
	});

	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++) {
		dp[i] = inp[i].score;

		for (int j = 0; j < i; j++) {
			if (inp[j].end <= inp[i].start) {
				dp[i] = max(dp[i], dp[j] + inp[i].score);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ncase;
	cin >> ncase;
	while (ncase--)
		solve();

	return 0;
}