#include <bits/stdc++.h>
using namespace std;

typedef struct{
	long long D, A, B;
}sign;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int c = 1; c <= T; c++){
		int N;
		cin >> N;
		sign signs[N+5];
		for(int i = 0; i < N; i++)
			cin >> signs[i].D >> signs[i].A >> signs[i].B;
		long long S[N+5][2][2], T[N+5][2][2];
		int dp[N+5][2][2], test;
		memset(dp, 0, sizeof(dp));
		dp[0][1][0] = dp[0][0][1] = dp[0][1][1] = 1;
		S[0][1][0] = S[0][1][1] = signs[0].D+signs[0].A;
		T[0][0][1] = T[0][1][1] = signs[0].D-signs[0].B;
		int maxans = 1, sets = 1;
		unordered_set<int> seq[N+5];
		seq[0].insert(0);
		for(int i = 1; i < N; i++){
			S[i][1][0] = signs[i].D+signs[i].A;
			T[i][0][1] = signs[i].D-signs[i].B;
			if(S[i][1][0] == S[i-1][1][0])
				dp[i][1][0] = dp[i-1][1][0] + 1;
			else
				dp[i][1][0] = 1;
			if(T[i][0][1] == T[i-1][0][1])
				dp[i][0][1] = dp[i-1][0][1] + 1;
			else
				dp[i][0][1] = 1;
			if(dp[i][1][1] < dp[i-1][0][1] + 1){
				S[i][1][1] = S[i][1][0];
				T[i][1][1] = T[i-1][0][1];
				dp[i][1][1] = dp[i-1][0][1] + 1;
			}
			if(dp[i][1][1] < dp[i-1][1][0] + 1){
				S[i][1][1] = S[i-1][1][0];
				T[i][1][1] = T[i][0][1];
				dp[i][1][1] = dp[i-1][1][0] + 1;
			}
			if((T[i][1][0] == T[i-1][1][1] || S[i][0][1] == S[i-1][1][1]) && dp[i][1][1] < dp[i-1][1][1] + 1){
				S[i][1][1] = S[i-1][1][1];
				T[i][1][1] = T[i-1][1][1];
				dp[i][1][1] = dp[i-1][1][1] + 1;
			}
			if(maxans < dp[i][1][0]){
				maxans = dp[i][1][0];
				sets = 1;
				seq[i-dp[i][1][0]+1].insert(i);
			}else if(maxans == dp[i][1][0]){
				if(!seq[i-dp[i][1][0]+1].count(i)){
					sets++;
					seq[i-dp[i][1][0]+1].insert(i);
				}
			}
			if(maxans < dp[i][1][1]){
				maxans = dp[i][1][1];
				sets = 1;
				seq[i-dp[i][1][1]+1].insert(i);
			}else if(maxans == dp[i][1][1]){
				if(!seq[i-dp[i][1][1]+1].count(i)){
					sets++;
					seq[i-dp[i][1][1]+1].insert(i);
				}
			}
			if(maxans < dp[i][0][1]){
				maxans = dp[i][0][1];
				sets = 1;
				seq[i-dp[i][0][1]+1].insert(i);
			}else if(maxans == dp[i][0][1]){
				if(!seq[i-dp[i][0][1]+1].count(i)){
					sets++;
					seq[i-dp[i][0][1]+1].insert(i);
				}
			}
		}
		cout << "Case #" << c << ": " << maxans << " " << sets << endl;
	}
	return 0;
}