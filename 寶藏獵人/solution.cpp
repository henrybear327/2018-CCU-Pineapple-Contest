#include <bits/stdc++.h>

using namespace std;

int main()
{
	FILE *fPtr1, *fPtr2;
	// fPtr1 = freopen("treasure.in", "r", stdin);
	// fPtr2 = freopen("treasure.out", "w", stdout);
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		long long int map[50][50] = {0};
		for (int i = 1; i <= m; i++)
			map[1][i] = 1;
		for (int i = 1; i <= n; i++)
			map[i][1] = 1;
		int num;
		scanf("%d", &num);
		int x, y;
		for (int i = 0; i < num; i++) {
			scanf("%d %d", &x, &y);
			map[y][x] = -1;
		}
		for (int i = 2; i <= m; i++)
			if (map[1][i - 1] == -1)
				map[1][i] = -1;
		for (int i = 2; i <= n; i++)
			if (map[i - 1][1] == -1)
				map[i][1] = -1;

		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= m; j++) {
				if (map[i][j] == -1)
					continue;
				if (map[i - 1][j] != -1)
					map[i][j] += map[i - 1][j];
				if (map[i][j - 1] != -1)
					map[i][j] += map[i][j - 1];
			}
		}
		// for(int i = 1; i <= n; i++){
		//     for(int j = 1; j <= m; j++){
		//         printf("%lld ",map[i][j]);
		//     }
		//     printf("\n");
		// }
		printf("%lld\n", map[n][m]);
	}
	return 0;
}