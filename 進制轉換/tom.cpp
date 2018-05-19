#include<bits/stdc++.h>

using namespace std;

int main()
{
	// FILE *fPtr1, *fPtr2;
	// fPtr1 = freopen("numeral.in", "r", stdin);
	// fPtr2 = freopen("test.out", "w", stdout);
	int cases;
	scanf("%d", &cases);
	while(cases--) {
		int K, N;
		scanf("%d %d", &K, &N);
		long long int num = 0;
		int digit = 1;
		while(digit <= N) {
			digit *= K;
		}
		if(digit != 1)
			digit /= K;
		while(digit != 1) {
			num = num * 10 + (N / digit);
			N %= digit;
			digit /= K;
		}
		printf("%lld\n", num * 10 + N);
	}
	return 0;
}
