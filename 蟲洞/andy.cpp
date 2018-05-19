#include <bits/stdc++.h>
using namespace std;

int dp[60][100010], ans[100010];
int main()
{
	int TC;
	scanf(" %d", &TC);

	while(TC--) {
		long long int n, k;

		scanf(" %lld %lld", &n, &k);

		for (int i = 0; i < n; i++) {
			int x;
			scanf(" %d", &x);
			dp[0][i] = x;
		}

		for (int i = 1; i < 60; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = dp[i - 1][dp[i - 1][j]];
			}
		}

		bool ch = true;
		int x = 1, b = 0;
		while(k) {
			if (k & 1) {
				if (x == 1) {
					for (int i = 0; i < n; i++) {
						ans[i] = dp[b][i];
					}
				} else {
					for (int i = 0; i < n; i++)
						ans[i] = dp[b][ans[i]];
				}
				x = 2;
			}

			b++;
			k >>= 1;
		}

		x = 1;
		for (int i = 0; i < n; i++) {
			if (ans[i] == 0) {
				if (x == 1)
					printf("%d", i);
				else
					printf(" %d", i);
				ch = false;
				x = 2;
			}
		}

		if (ch)
			printf("-1");
		printf("\n");

	}

	return 0;
}
