//Title: Little Shop of Flowers
//Type: Dynamic Programming
//Solution: At first this seemed like the DFS O(100!) death, until question read "the bunch i must be in a vase to the left of the vase containing bunch j whenever i < j."
		/*	dp[i][j] represents the aesthetic value, and we either take dp[i][j-1] which is do not use this vase, or dp[i-1][j-1] + A[i][j] which uses that numbered vase.
			condition: dp[i][0] must all be -inf, answer is at dp[F][V] */
#include <iostream>
using namespace std;
const int INF = 5000; //since -50 * 100 is smallest aesthetic value.
int F, V, dp[101][101];
int main(){
	//Instantiation;
	cin >> F >> V;
	int A[F+1][V+1], vase[F+1];
	for(int i = 1; i <= F; i++){
		for(int j = 1; j <= V; j++){
			cin >> A[i][j];
		}
	}
	//DP condition
	for(int i = 1; i <= F; i++){
		dp[i][0] = -INF;
	}
	//DP
	for(int i = 1; i <= F; i++){
		for(int j = 1; j <= V; j++){
			if(dp[i][j-1] < dp[i-1][j-1] + A[i][j])
				dp[i][j] = dp[i-1][j-1] + A[i][j];
			else
				dp[i][j] = dp[i][j-1];
		}
	}
	//Reverse vase
	int f = F;
	for(int v = V; v >= 1; v--){
		if(dp[f][v] == dp[f-1][v-1] + A[f][v]){
			vase[f--] = v;
		}
	}
	//Print results
	cout << dp[F][V] << endl;
	for(int i = 1; i <= F; i++){
		if(i == F)
			cout << vase[i] << endl;
		else
			cout << vase[i] << " ";
	}
	return 0;
}