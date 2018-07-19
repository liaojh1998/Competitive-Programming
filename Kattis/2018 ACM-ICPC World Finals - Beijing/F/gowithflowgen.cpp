#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N;
	freopen("input.txt", "w", stdout);
	cin >> T;
	cout << T << endl;
	N = 2;
	while(T--){
		N++;
		cout << N << endl;
		mt19937 rand(chrono::system_clock::now().time_since_epoch().count());
		for(int i = 0; i < N; i++){
			int p = rand()%42 + 1;
			for(int i = 0; i < p; i++)
				cout << (rand()%2 ? (char)(rand()%26+'A') : (char)(rand()%26+'a'));
			cout << (rand()%2 ? " " : "\n");
		}
	}
	return 0;
}