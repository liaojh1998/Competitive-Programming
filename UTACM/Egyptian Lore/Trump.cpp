//Type: 2D DP, USACO problem 3.3.4 Home on the Range same question lol
#include <cstdio>
#include <cstring>
int T, N, mat[1002][1002], ans[1001], max;
char c;
int min(int a, int b, int c){
	if(a > b) a = b;
	if(a > c) a = c;
	return a;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		getchar();
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				scanf("%c", &c);
				mat[i][j] = c - '0';
			}
			getchar();
		}
		//2D DP, pretty amazing solution... If only I can think of something like this
		for(int i = N-1; i >= 0; i--){
			for(int j = N-1; j >= 0; j--){
				if(mat[i][j])
					mat[i][j] = min(mat[i+1][j], mat[i][j+1], mat[i+1][j+1]) + 1;
				if(mat[i][j] >= 2){
					if(max < mat[i][j]) max = mat[i][j];
					for(int k = 2; k <= mat[i][j]; k++)
						ans[k]++;
				}
			}
		}
		//Print
		for(int i = 2; i <= max; i++){
			printf("%d %d\n", i, ans[i]);
		}
		//Reset
		memset(mat, 0, sizeof(mat));
		memset(ans, 0, sizeof(ans));
		max = 0;
	}
	return 0;
}