#include<bits/stdc++.h>

using namespace std;
struct subject {
	int start_time;
	int end_time;
	int weight;
};
bool cmp(subject a, subject b)
{
	if(a.end_time != b.end_time)
		return a.end_time < b.end_time;
	else
		return a.start_time < b.start_time;
}
int main()
{
	//freopen("pa.in", "r", stdin);
	//freopen("ans.txt", "w", stdout);
	int cases;
	while(scanf("%d", &cases) != EOF) {
		while(cases--) {
			int num;
			scanf("%d", &num);
			subject subjects[110];
			for(int  i = 0; i < num; i++)
				scanf("%d %d %d", &subjects[i].start_time, &subjects[i].end_time, &subjects[i].weight);

			sort(subjects, subjects + num, cmp);
			int dp[2][110] = {0};
			dp[0][0] = subjects[0].end_time;
			dp[1][0] = subjects[0].weight;
			for(int i = 1 ; i < num; i++) {
				//dp[0][i] = subjects[i].start_time;
				dp[0][i] = subjects[i].end_time;
				int temp = 0;
				for(int j = 0; j < i; j++) {
					if(dp[0][j] <= subjects[i].start_time)
						temp = max(temp, dp[1][j]);
					else
						break;
				}
				dp[1][i] = subjects[i].weight + temp;
			}
			int ans = 0;
			for(int i = 0; i < num; i++)
				ans = max(ans,dp[1][i]);
			printf("%d\n", ans);
		}
	}
	return 0;
}