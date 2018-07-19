#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("tourist.txt", "w", stdout);

	int T, N, K, V;
	cin >> T >> N >> K >> V;
	cout << T << endl;
	while(T--){
		mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
		int curN, curK, curV;
		curN = rnd()%N + 1;
		curK = rnd()%curN + 1;
		curV = rnd()%V + 1;
		cout << curN << " " << curK << " " << curV << endl;
		while(curN--){
			int strlen = rnd()%20 + 1;
			while(strlen--){
				int p = rnd()%3;
				switch(p){
					case 0: cout << static_cast<char>(rnd()%26 + 'a'); break;
					case 1: cout << static_cast<char>(rnd()%26 + 'A'); break;
					case 2: cout << static_cast<char>(rnd()%10 + '0'); break;
				}
			}
			cout << endl;
		}
	}
	return 0;
}
