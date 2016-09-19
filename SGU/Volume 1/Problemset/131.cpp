//Title: Hardwood Floor
//Type: State Compression + DP
//Solution: Still got to do more of this. State compression (into bits) + Dynamic Programming.
#include <cstdio>
#include <cstring>
#define binary(i) (1<<i)
#define empty(a, i) (!(a&binary(i)))
int N, M, max;
long long temp[1<<9], ans[1<<9];
void dfs(int a, int b, long long k){
	//When filled
	if(a == max){
		temp[b] += k;
		return;
	}
	for(int i = 0; i <= M; i++){
		//If current block has nothing filled
		if(empty(a, i)){
			if(i + 1 < M && empty(a, i+1)){
				dfs(a|binary(i)|binary(i+1), b, k); //#1: 2x1
				//If bottom block has nothing filled
				if(empty(b, i))
					dfs(a|binary(i)|binary(i+1), b|binary(i), k); //#2: 2x2 without bottom right
				if(i + 1 < M && empty(b, i+1))
					dfs(a|binary(i)|binary(i+1), b|binary(i+1), k); //#4: 2x2 without bottom left
			}
			if(empty(b, i)){
				dfs(a|binary(i), b|binary(i), k); //#2: 1x2
				if(i + 1 < M && empty(b, i+1))
					dfs(a|binary(i), b|binary(i)|binary(i+1), k); //#5: 2x2 without upper right
				if(i >= 1 && empty(b, i-1))
					dfs(a|binary(i), b|binary(i)|binary(i-1), k); //#6: 2x2 without upper left
			}
			break; //Break everytime there has been a fill
		}
	}
}
int main(){
	//Instantiation
	scanf("%d %d", &N, &M);
	max = (1<<M)-1;
	ans[max] = 1;
	//For every line
	for(int i = 0; i <= N; i++){
		//Enumerate everything starting from 0
		for(int j = 0; j <= max; j++){
			if(ans[j]) dfs(j, 0, ans[j]); //DFS 6 different conditions
		}
		memcpy(ans, temp, sizeof(temp));
		memset(temp, 0, sizeof(temp));
	}
	printf("%lld\n", ans[0]);
	return 0;
}