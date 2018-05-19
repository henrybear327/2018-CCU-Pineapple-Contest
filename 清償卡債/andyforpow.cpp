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
			a = a * pow(1.00054, 30);
			a -= b;
			month++;
		}

		printf("%d\n", month);
	}

	return 0;
}
