#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	string str;
	getline(cin, str);
	while(T--){
		getline(cin, str);
		int col = -1, count = 0, len = str.size(), A = 0, B = 0;
		for(int i = 0; i < len; i++){
			if(str[i] == 'A'){
				if(col == 0)
					A += count;
				A++;
				count = 0;
				col = 0;
			}else if(str[i] == 'B'){
				if(col == 1)
					B += count;
				B++;
				count = 0;
				col = 1;
			}else
				count++;
		}
		printf("%d %d\n", A, B);
	}
}