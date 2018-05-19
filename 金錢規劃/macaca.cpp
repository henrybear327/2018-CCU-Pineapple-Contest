#include <iostream>

using namespace std;

int main()
{
	int TC;
	cin >> TC;
	for(int i = 0 ; i < TC; i++) {
		long long int earn,cost;
		int n;
		cin>>earn;
		cin>>n;
		for(int j = 0 ; j < n ; j++) {
			cin >> cost;
			earn -= cost;
		}
		cout<<earn<<endl;
	}
	return 0;
}
