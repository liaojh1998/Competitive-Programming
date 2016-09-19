//Title: Shtirlits
//Type: DFS/Structure
//Solution: DFS + pruning away case scenarios such that all other cases with same state would end up false
#include <cstdio>
int N, B[5][5], A[5][5];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool flag;
bool check(int x, int y){
	//Check all sides for anything bigger than A[y][x]
	int temp = 0;
	for(int i = 0; i < 4; i++)
		temp+=(A[y+dy[i]][x+dx[i]] > A[y][x]);
	if(temp == B[y][x]) return true;
	return false;
}
void DFS(int x, int y){
	//Case complete and 1 last test since all were tested before
	if(x == N + 1){
		if(!check(N, N)) return;
		flag = true;
	}
	//Pruning and DFS
	for(int i = 0; i <= 9 && !flag; i++){
		A[y][x] = i;
		//Only need to check above when we arrive at x limit ends and left
		if((x != 1 && !check(x-1, y)) || (x == N && y != 1 && !check(x, y-1))) continue;
		//DFS down before right
		if(y == N) DFS(x+1, 1);
		else DFS(x, y+1);
	}
}
int main(){
	//Instantiation
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			scanf("%d", &B[i][j]);
	//DFS
	DFS(1, 1);
	//Print solution
	if(flag)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				if(j != N)
					printf("%d ", A[i][j]);
				else
					printf("%d\n", A[i][j]);
	else
		printf("NO SOLUTION\n");
	return 0;
}