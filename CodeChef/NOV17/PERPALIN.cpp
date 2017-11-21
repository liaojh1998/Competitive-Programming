#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, P;
	cin >> T;
	while(T--){
		cin >> N >> P;
		if(P <= 2)
			cout << "impossible" << endl;
		else{
			int len = P/2;
			string f, b;
			for(int i = 0; i < len; i++)
				if(i&1){
					f += 'b';
					b = 'b'+b;
				}else{
					f += 'a';
					b = 'a'+b;
				}
			string str = f + ((P&1) ? ((len&1) ? "b" : "a") : "") + b;
			N /= P;
			while(N--)
				cout << str;
			cout << endl;
		}
	}
	return 0;
}