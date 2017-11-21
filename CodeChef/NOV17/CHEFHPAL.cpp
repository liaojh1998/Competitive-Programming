#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, N, A;
	cin >> T;
	while(T--){
		cin >> N >> A;
		if(A == 1){
			cout << N << " ";
			while(N--)
				cout << "a";
			cout << endl;
		}else if(A == 2){
			switch(N){
				case 1: cout << 1 << " a"; break;
				case 2: cout << 1 << " ab"; break;
				case 3: cout << 2 << " aab"; break;
				case 4: cout << 2 << " aabb"; break;
				case 5: cout << 3 << " aaaba"; break;
				case 6: cout << 3 << " aaabab"; break;
				case 7: cout << 3 << " aaababb"; break;
				case 8: cout << 3 << " aaababbb"; break;
				default: cout << 4 << " aaa";
					N -= 3;
					while(N >= 6){
						cout << "ababba";
						N -= 6;
					}
					if(N <= 3)
						while(N--)
							cout << "a";
					else{
						cout << "abab";
						if(N == 5)
							cout << "b";
					}
			}
			cout << endl;
		}else{
			cout << 1 << " ";
			for(int i = 0; i < N; i++)
				cout << (char)('a'+(i%A));
			cout << endl;
		}
	}
	return 0;
}