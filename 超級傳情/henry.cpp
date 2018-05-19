#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n, m;
	cin >> n >> m;
	assert(3 <= n && n <= 300);
	assert(0 <= m && m <= 500);

	int g[n][n];
	memset(g, 0, sizeof(g));
	for (int i = 0; i < n; i++)
		g[i][i] = 1;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		g[u][v] = 1;
	}

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				g[i][j] = g[i][j] || (g[i][k] && g[k][j]);

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < n; j++) {
	// 		cout << g[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;

			if (g[i][j] == 1)
				ans++;
		}
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