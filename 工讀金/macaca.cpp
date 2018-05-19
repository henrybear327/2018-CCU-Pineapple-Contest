#include <iostream>

using namespace std;

int main()
{
	int N;
	while(1) {
		cin>>N;
		if(N == -1)
			break;
		int paid;
		int hours;
		for(int i = 0 ; i < N ; i++) {
			while(1) {
				int t;
				cin>>t;
				if(t == 0)
					break;
				hours += t;
			}
			if(hours <= 50)
				paid += hours * 140;
			else if(51 <= hours && hours <= 65)
				paid += hours * 280;
			else
				paid += hours * 420;
			hours = 0;
		}

		// cout<<hours<<endl;
		cout<<paid<<endl;
		paid = 0;
	}
	return 0;
}
