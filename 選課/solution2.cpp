#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

struct Slot {
	int weekday;
	int start, end;
};

void read(vector<vector<Slot>> &courses, int n)
{
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			int w, s, e;
			scanf("%d %d %d", &w, &s, &e);
			w--;
			courses[i].push_back(Slot{w, s, e});
		}
	}
}

void dfs(int who, vector<vector<int>> &dp, vector<vector<Slot>> &courses,
         int &n, int &k, bool select, int &ans)
{
	// cout << who << " " << select << endl;

	if (who == n) {
		// cal
		int overlap = 0;
		int credit = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 24; j++) {
				if (dp[i][j] > 1)
					overlap += dp[i][j] - 1;
				credit += dp[i][j];
			}
		}
		// update ans
		// cout << credit << endl;
		if (overlap <= k)
			ans = max(ans, credit);

		return;
	}

	if (select == true) {
		// update dp
		for (auto slot : courses[who]) {
			for (int i = slot.start; i < slot.end; i++) {
				dp[slot.weekday][i]++;
			}
		}
	}
	dfs(who + 1, dp, courses, n, k, true, ans);
	dfs(who + 1, dp, courses, n, k, false, ans);
	if (select == true) {
		// un-update dp
		for (auto slot : courses[who]) {
			for (int i = slot.start; i < slot.end; i++) {
				dp[slot.weekday][i]--;
				assert(dp[slot.weekday][i] >= 0);
			}
		}
	}
}

void solve()
{
	int n, k;
	scanf("%d %d", &n, &k);

	// read input
	vector<vector<Slot>> courses(n, vector<Slot>());
	read(courses, n);

	// solve
	vector<vector<int>> dp(5, vector<int>(24, 0));
	int ans = 0;
	dfs(0, dp, courses, n, k, true, ans);
	dfs(0, dp, courses, n, k, false, ans); // wow this case

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
		solve();

	return 0;
}