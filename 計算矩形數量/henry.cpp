#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);

	int g[n][n];
	for (int i = 0; i < n; i++) {
		char inp[n + 2];
		scanf("%s", inp);
		for (int j = 0; j < n; j++) {
			g[i][j] = inp[j] - '0';
		}
	}

	int ans = 0;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			// (x, y)
			for (int a = x + 1; a < n; a++) {
				for (int b = y + 1; b < n; b++) {
					// (a, b)

					if (g[x][y] == 1 && g[a][b] == 1 && g[x][b] == 1 && g[a][y] == 1)
						ans++;
				}
			}
		}
	}

	printf("%d\n", ans);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);

	while (ncase--)
		solve();

	return 0;
}