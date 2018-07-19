#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("interception.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	cout << T << endl;
	mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
	
	while(T--){
		int N = rnd()%51;
		cout << N << endl;
		int first = static_cast<int>(rnd()%101) - 50;
		while(!first)
			first = static_cast<int>(rnd()%101) - 50;
		cout << first << endl;
		while(N--){
			cout << static_cast<int>(rnd()%101) - 50 << endl;
		}
	}	

	return 0;
}
