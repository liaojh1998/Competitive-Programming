#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("interception.txt", "r", stdin);
	freopen("interception-out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for(int index = 1; index <= T; index++){
		int N, dump;
		cin >> N;
		cout << "Case #" << index << ": ";
		if(N & 1)
			cout << 1 << endl << "0.0" << endl;
		else
			cout << 0 << endl;	
		for(int i = 0; i <= N; i++)
			cin >> dump;
	}

	return 0;
}
