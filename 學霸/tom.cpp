#include<bits/stdc++.h>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(a.first != b.first)
		return a.first > b.first;
	else
		return a.second > b.second;
}
int main()
{
	int cases;
	//freopen("suabar.in", "r" ,stdin);
	//freopen("ans.txt", "w", stdout);
	while(scanf("%d", &cases) != EOF) {
		while(cases--) {
			int num;
			scanf("%d", &num);
			int P[50005] = {0}, M[50005] = {0};
			for(int i = 0; i < num; i++)
				scanf("%d", &P[i]);
			for(int i = 0; i < num; i++)
				scanf("%d", &M[i]);
			vector<pair<int, int>> students;
			for(int i = 0; i < num; i++)
				students.push_back(make_pair(P[i], M[i]));
			sort(students.begin(), students.end(), cmp);
			int ans = 0, first_max = students[0].first, second_max = students[0].second;
			for(int i = 0; i < num; i++) {
				if(first_max == students[i].first && second_max == students[i].second)
					ans++;
				else if(first_max > students[i].first && second_max < students[i].second) {
					ans++;
					first_max = students[i].first;
					second_max = students[i].second;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}