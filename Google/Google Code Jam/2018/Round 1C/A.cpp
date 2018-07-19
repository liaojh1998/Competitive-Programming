#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int idx = 1; idx <= T; idx++){
		int N, L;
		cin >> N >> L;
		bool has[L+5][26][26];
		int loc[L+5][26];
		string arr[N+5];
		memset(loc, -1, sizeof(loc));
		memset(has, 0, sizeof(has));
		for(int i = 0; i < N; i++){
			cin >> arr[i];
			for(int j = 0; j < L-1; j++){
				loc[j][arr[i][j]-'A'] = i;
				has[j][arr[i][j]-'A'][arr[i][j+1]-'A'] = true;
			}
			loc[L-1][arr[i][L-1]-'A'] = i;
		}
		string ans;
		bool none = true;
		for(int i = 0; i < L-1 && none; i++){
			bool used = false;
			for(int j = 0; j < 26 && none; j++){
				if(loc[i][j] != -1){
					for(int k = 0; k < 26 && none; k++){
						if(loc[i+1][k] != -1 && !has[i][j][k]){
							none = false;
							if(used)
								ans[i] = static_cast<char>(j + 'A');
							else
								ans += static_cast<char>(j + 'A');
							ans += arr[loc[i+1][k]].substr(i+1, L-i);
						}
					}
					if(none && !used){
						ans += static_cast<char>(j + 'A');
						used = true;
					}
				}
			}
		}
		cout << "Case #" << idx << ": ";
		if(none)
			cout << "-" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}