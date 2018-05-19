#include <iostream>

using namespace std;

int main()
{
	int TC;
	cin >> TC;
	for(int i = 0 ; i < TC ; i++) {
		int n, tag = 0;
		int in[26] = {0};
		int out[26] = {0};
		cin >> n;
		for(int j = 0 ; j < n ; j++) {
			string s ;
			cin >> s;
			in[s[0] - 'a']++;
			out[s[s.length() - 1] - 'a']++;
		}
		for(int j = 0 ; j < 26 ; j++) {
			if(in[j] != out[j]) {
				tag = 1;
				break;
			}
		}
		if(tag)
			cout<<"QAQ"<<endl;
		else
			cout<<"Lucky"<<endl;
	}
	return 0;
}
