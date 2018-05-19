#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int base, num;
	cin >> base >> num;

	if (num == 0) {
		// what a special case
		cout << 0 << endl;
		return;
	}

	assert(2 <= base && base <= 10);
	assert(0 <= num && num <= 10000);

	vector<int> ans;
	while (num > 0) {
		ans.push_back(num % base);
		num /= base;
	}
	reverse(ans.begin(), ans.end());

	string res = "";
	for (auto i : ans)
		res += to_string(i);
	cout << res << endl;
}

int main()
{
	int ncase;
	cin >> ncase;

	while (ncase--)
		solve();

	return 0;
}