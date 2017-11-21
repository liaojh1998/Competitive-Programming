#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, num, lo, hi, t;
	cin >> T;
	while(T--){
		bool possible = true;
		cin >> N >> num;
		lo = 0, hi = 1000000001;
		while(possible && N){
			cin >> t;
			if(t > num){
				if(t > hi)
					possible = false;
				else
					hi = t;
			}else{
				if(t < lo)
					possible = false;
				else
					lo = t;
			}
			N--;
		}
		printf("%s\n", (possible ? "YES" : "NO"));
		while(N--)
			cin >> t;
	}
	return 0;
}