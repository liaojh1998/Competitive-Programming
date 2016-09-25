//Title: Divisible Group Sums
//Type: DP
//Complexity: O(NS) (N - N integers, S - S states)
//Solution: Classic 0-1 Knapsack using modulus, and very time consuming too!
#include <cstdio>
#include <cstring>
int T = 1, num[250], N, Q, D, M;
long long knapsack[250][30][30];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(scanf("%d%d", &N, &Q) && N && Q){
		printf("SET %d:\n", T++);
		for(int i = 1; i <= N; i++)
			scanf("%d", &num[i]);
		for(int q = 1; q <= Q; q++){
			printf("QUERY %d: ", q);
			scanf("%d%d", &D, &M);
			memset(knapsack, 0, sizeof(knapsack));
			for(int i = 0; i <= N; i++)
				knapsack[i][0][0] = 1;
			for(int i = 1; i <= N; i++)
				for(int j = 1; j <= M; j++)
					for(int k = 0; k < D; k++){
						int rem = (k - num[i]%D)%D;
						knapsack[i][j][k] = knapsack[i-1][j][k] + knapsack[i-1][j-1][rem >= 0 ? rem : rem+D];
					}
			printf("%lld\n", knapsack[N][M][0]);
		}
	}
	return 0;
}