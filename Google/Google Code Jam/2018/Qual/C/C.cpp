#include <bits/stdc++.h>
using namespace std;

bool solve(){
	int A;
	cin >> A;
	while(A%3)
		A++;
	int R = A/3, I, J, count;
	//2 to R-1
	bool mat[R+1][4];
	memset(mat, 0, sizeof(mat));
	//Greedy strategy
	cout << 2 << " " << 2 << endl;
	cin >> I >> J;
	while(I && J && (I != -1) && (J != -1)){
		mat[I][J] = true;
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
		for(int i = 2; i <= R-1; i++){
			count = 0;
			for(int j = -1; j <= 1; j++)
				for(int k = 1; k <= 3; k++)
					if(!mat[i+j][k])
						count++;
			if(count)
				q.push(pair<int, int>(count, i));
		}
		pair<int, int> t = q.top();
		cout << t.second << " " << 2 << endl;
		cin >> I >> J;
	}
	if(!I && !J)
		return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	bool solved = true;
	for(int idx = 1; idx <= T && solved; idx++)
		solved = solve();
	return 0;
}