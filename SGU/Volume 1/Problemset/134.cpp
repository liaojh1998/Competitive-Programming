//Title: Centroid
//Type: DP + DFS
//Solution: Interesting concept of Tree DP and how to use it. Loved learning it.
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> edges[16001];
int N, dp[16001], u, v, cent[16001], cenl, mindp = 16001;
//DFS search down the tree
int dfs(int i, int p){
	int tree, len = edges[i].size(), sum = 0;
	for(int j = 0; j < len; j++)
		if(edges[i][j] != p){ //check if it's the parent node
			tree = dfs(edges[i][j], i);
			dp[i] = max(tree, dp[i]);
			sum+= tree;
		}
	dp[i] = max(dp[i], N-sum-1); //dfs that would happen in the parent direction
	return sum+1;
}
int main(){
	//Input
	scanf("%d", &N);
	for(int i = 0; i < N-1; i++){
		scanf("%d %d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	//DP down the tree
	dfs(1, 0);
	//Look for minimum v value
	for(int i = 1; i <= N; i++)
		if(mindp > dp[i]){
			cenl = 0;
			cent[cenl++] = i;
			mindp = dp[i];
		}else if(mindp == dp[i])
			cent[cenl++] = i;
	//Print answer
	//No node exception
	if(mindp == 16001)
		mindp = 0;
	//Print for the rest
	printf("%d %d\n", mindp, cenl);
	for(int i = 0; i < cenl; i++)
		if(i == cenl-1)
			printf("%d", cent[i]);
		else
			printf("%d ", cent[i]);
	printf("\n");
	return 0;
}