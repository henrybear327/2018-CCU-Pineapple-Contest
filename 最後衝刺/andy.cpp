#include <bits/stdc++.h>
using namespace std;

struct Cls {
	int s, e, g;

	bool operator<(const Cls &c) const
	{
		if (e == c.e)
			return s < c.s;
		return e < c.e;
	}
};

int main()
{

	int TC;
	scanf(" %d", &TC);

	while (TC--) {
		int n;
		vector<Cls> v;
		int dp[1000] = {0};

		scanf(" %d", &n);
		assert(1 <= n && n <= 100);

		Cls inp;
		for (int i = 0; i < n; i++) {
			scanf(" %d %d %d", &inp.s, &inp.e, &inp.g);
			assert(0 <= inp.s && inp.s <= 24);
			assert(0 <= inp.e && inp.e <= 24);
			assert(1 <= inp.g && inp.g <= 1000);
			v.push_back(inp);
		}

		sort(v.begin(), v.end());

		dp[0] = v[0].g;
		for (int i = 1; i < n; i++) {
			Cls now = v[i];
			dp[i] = now.g;
			for (int j = i - 1; j >= 0; j--) {
				if (now.s >= v[j].e) {
					dp[i] = max(dp[i], now.g + dp[j]);
				}
			}
		}

		int ans = -1;
		for (int i = 0; i < n; i++)
			ans = max(ans, dp[i]);

		printf("%d\n", ans);
	}

	return 0;
}
