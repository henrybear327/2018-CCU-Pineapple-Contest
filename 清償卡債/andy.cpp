#include <bits/stdc++.h>
using namespace std;

int main()
{

	int TC;
	scanf(" %d", &TC);

	while (TC--) {
		double a, b;
		scanf(" %lf %lf", &a, &b);

		assert(100000 <= a && a <= 200000);
		assert(5000 <= b && b <= 20000);

		int month = 0;
		while (a > 0) {
			for (int i = 0; i < 30; i++)
				a = a * 1.00054;
			a -= b;
			month++;
		}

		printf("%d\n", month);
	}

	return 0;
}
