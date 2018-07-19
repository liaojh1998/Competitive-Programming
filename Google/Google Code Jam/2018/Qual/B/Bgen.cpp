#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.txt", "w", stdout);
	int T = 100;
	cout << T << endl;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
	while(T--){
		int N = rnd()%50001 + 50000;
		cout << N << endl;
		for(int i = 0; i < N; i++)
			cout << rnd()%1000000001 << (i == N-1 ? "\n" : " ");
	}
	return 0;
}