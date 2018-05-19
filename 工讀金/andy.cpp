#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;

	while (scanf(" %d", &n)) {
		if (n == -1)
			break;

		assert(1 <= n && n <= 4);

		int ans = 0, inp;
		for (int i = 0; i < n; i++) {
			int time = 0;
			while (scanf(" %d", &inp)) {

				assert(0 <= inp && inp <= 100);

				if (inp == 0)
					break;
				time += inp;
			}

			if (time <= 50)
				ans += time * 140;
			else if (51 <= time && time <= 65)
				ans += time * 280;
			else
				ans += time * 420;
		}

		printf("%d\n", ans);
	}
	return 0;
}
