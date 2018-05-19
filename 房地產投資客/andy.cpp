#include <bits/stdc++.h>
using namespace std;

int main()
{

	int TC;
	scanf(" %d", &TC);

	while (TC--) {
		double a, b;
		int c;

		scanf(" %lf %lf %d", &a, &b, &c);

		assert(100 <= a && a <= 1000);
		assert(0.025 <= b && b <= 0.04);
		assert(1 <= c && c <= 10);

		double ans = a;
		for (int i = 0; i < c; i++) {
			ans = ans + ans * 10.0 * 0.085 - 9.0 * ans * b;
		}

		printf("%.2lf\n", ans);
	}

	return 0;
}
