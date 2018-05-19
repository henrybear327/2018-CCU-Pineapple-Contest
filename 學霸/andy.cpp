#include <bits/stdc++.h>
using namespace std;

int main()
{
	int TC;
	scanf(" %d", &TC);

	while(TC--) {
		int n;
		pair<int, int> p[50010];

		scanf(" %d", &n);

		assert(0 < n && n <= 50000);

		for (int i = 0; i < n; i++) {
			scanf(" %d", &p[i].first);
			assert(0 <= p[i].first && p[i].first <= 1e9);
		}
		for (int i = 0; i < n; i++) {
			scanf(" %d", &p[i].second);
			assert(0 <= p[i].second && p[i].second <= 1e9);
		}

		sort(p, p + n);

		int ans = 1, x = p[n - 1].first, y = p[n - 1].second;
		for (int i = n - 2; i >= 0; i--) {
			if (y < p[i].second) {
				ans += 1;
				x = p[i].first;
				y = p[i].second;
			} else if (y == p[i].second) {
				if (x == p[i].first)
					ans += 1;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
