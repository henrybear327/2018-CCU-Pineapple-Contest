#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int(x.size()))
typedef long long ll;
inline ll getll()
{
	ll inp;
	scanf(" %lld", &inp);
	return inp;
}
inline int getint()
{
	int inp;
	scanf(" %d", &inp);
	return inp;
}

const int MAX_LOG_K = 60;
const int MAX_N = 50000;

ll dp[MAX_LOG_K][MAX_N];
void solve()
{
	int N = getint();
	ll K = getll();

	for (int u = 0; u < N; u++) {
		dp[0][u] = getint();
	}

	for (int i = 1; (1ll << i) <= K; i++) {
		for (int u = 0; u < N; u++) {
			dp[i][u] = dp[i - 1][dp[i - 1][u]];
		}
	}

	vector<int> movements;
	for (int i = 0; (1ll << i) <= K; i++) {
		if (K & (1ll << i)) {
			movements.push_back(i);
		}
	}

	vector<int> ans;
	for (int u = 0; u < N; u++) {
		int v = u;
		for (auto m : movements) {
			v = dp[m][v];
		}
		if (v == 0) {
			ans.push_back(u);
		}
	}

	if (sz(ans) == 0) puts("-1");
	else {
		for (int i = 0; i < sz(ans); i++) {
			if (i > 0) printf(" ");
			printf("%d", ans[i]);
		}
		puts("");
	}
}

int main()
{
	int TC = getint();
	while (TC--) {
		solve();
	}
	return 0;
}
