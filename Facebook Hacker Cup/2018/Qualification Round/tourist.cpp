#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("tourist.txt", "r", stdin);
	freopen("tourist-out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for(int index = 1; index <= T; index++){
		long long N, K, V;
		cin >> N >> K >> V;
		string str[N+5];
		for(int i = 0; i < N; i++)
			cin >> str[i];
		int loc = K*(V-1)%N;
		cout << "Case #" << index << ": ";
		if(loc + K > N){
			int end = loc + K - N;
			for(int i = 0; i < end; i++)
				cout << str[i] << " ";
			for(int i = loc; i < N; i++)
				cout << str[i] << (i == N-1 ? "\n" : " ");
		}else{
			int end = loc + K;
			for(int i = loc; i < end; i++)
				cout << str[i] << (i == end-1 ? "\n" : " ");
		}
	}

	return 0;
}
