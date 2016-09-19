/*
ID: liaojh11
PROG: inflate
LANG: C++
*/
//Title: inflate
//Type: DP
//Solution: Knapsack Algorithms for the win.
#include <stdio.h>
FILE *fin, *fout;
int M, N, s, t, dp[10001] = {0};
int main(){
	//Instantiation
	fin = fopen("inflate.in", "r");
	fout = fopen("inflate.out", "w");
	fscanf(fin, "%d %d", &M, &N);
	//Knapsack
	for(int i = 0; i < N; i++){
		fscanf(fin, "%d %d", &s, &t);
		for(int j = t; j <= M; j++){
			//At first I did j += time[i], until I realized we could go over M as long as it's incrementing only 1 extra test.
			if(dp[j - t] + s > dp[j])
				dp[j] = dp[j - t] + s;
		}
	}
	fprintf(fout, "%d\n", dp[M]);
	return 0;
}