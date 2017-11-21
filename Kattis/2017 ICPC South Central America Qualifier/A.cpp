#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--){
		double N, div;
		int t;
		cin >> N;
		div = N;
		double ans = 0;
		for(int i = 0; i < N; i++){
			cin >> t;
			if(t == -1)
				div--;
			else
				ans += t;
		}
		ans /= div;
		printf("%.6lf\n", ans);
	}
	return 0;
}