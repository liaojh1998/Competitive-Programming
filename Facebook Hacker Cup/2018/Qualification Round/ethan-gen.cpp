#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("ethan_searches_for_a_string.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
	
	int T;
	cin >> T;
	cout << T << endl;
	while(T--){
		int N = rnd()%2000+1;
		while(N--)
			cout << static_cast<char>(rnd()%26 + 'A');
		cout << endl;
	}
	return 0;
}
