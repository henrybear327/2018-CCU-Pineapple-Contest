#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct LectureTime {
	int weekday;
	int start;
	int end;
};

struct Course {
	vector<LectureTime> timetable;
};

int solve()
{
	// read input
	int n, k;
	cin >> n >> k;

	// get course info
	// Course *inp = new Course[n];
	vector<LectureTime> inp[n];
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;

		for (int j = 0; j < m; j++) {
			LectureTime tmp;
			cin >> tmp.weekday >> tmp.start >> tmp.end;
			// inp[i].timetable.push_back(tmp);
			inp[i].push_back(tmp);
		}
	}

	// compute
	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		// cout << i << ": ";
		int credit = 0;
		int overlap = 0;
		int occupy[7][24];
		memset(occupy, 0, sizeof(occupy));

		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				// for (auto t : inp[j].timetable) {
				for (auto t : inp[j]) {
					for (int l = t.start; l < t.end; l++) {
						if (occupy[t.weekday][l] > 0)
							overlap++;
						occupy[t.weekday][l]++;
						credit++;
					}
				}
			}

			if (overlap <= k)
				ans = max(ans, credit);
		}

		// cout << credit << endl;
	}
	// cerr << "Done!" << endl;

	// delete[] inp;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ncase;
	cin >> ncase;
	while (ncase--)
		cout << solve() << endl;

	return 0;
}
