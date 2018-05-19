#include <bits/stdc++.h>
using namespace std;

int main()
{
	int TC;
	scanf(" %d", &TC);

	while(TC--) {
		char a[20], b[20], c[20];
		scanf(" %s", a);
		scanf(" %s", b);
		scanf(" %s", c);

		for (int i = 0; i < 10; i++) {
			assert(a[i] == '0' || a[i] == '1');
			assert(b[i] == '0' || b[i] == '1');
			assert(c[i] == '0' || c[i] == '1');
		}

		int ans = 0;
		for (int i = 9; i >= 0; i--) {
			if (a[i] != b[i]) {
				int base = 1;
				for (int pos = i; pos > i - 7; pos--) {
					ans += base * (c[pos] - '0');
					base *= 2;
				}
				break;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
