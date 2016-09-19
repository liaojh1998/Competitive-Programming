//Title: Largest Submatrix
//Type: DP
//Complexity: O(N^4)
//Solution: Another classic, same as 108. Though I did 108 very differently by using kadane's sum, this solution is pretty interesting.
		/*	Turn the n × n input matrix into an n × n cumulative sum matrix where mat[i][j] no longer contains its
			own value, but the sum of all items within sub-matrix (0, 0) to (i, j).
			We simply need to set -1000 at places where there are 0 such that the matrix is relative to all sums and 0s are not considered.
			We can also do this in O(N^3) by converting all 0s to -1000s, but I'm leaving this O(N^4) as an example for future reference. */
#include <cstdio>
#include <cstring>
char c;
int N, maxsum, tempsum, len = 1, mat[30][30];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	getchar();
	getchar();
	while(N--){
		while(scanf("%c", &c) && c != 10){
			mat[1][len] = (c-'0' ? c-'0' : -1000) + mat[1][len-1];
			len++;
		}
		for(int i = 2; i < len; i++){
			for(int j = 1; j < len; j++){
				scanf("%c", &c);
				mat[i][j] = (c-'0' ? c-'0' : -1000) + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
			}
			getchar();
		}
		for(int i = 1; i < len; i++)
			for(int j = 1; j < len; j++)
				for(int p = i; p < len; p++)
					for(int q = j; q < len; q++){
						tempsum = mat[p][q] - mat[p][j-1] - mat[i-1][q] + mat[i-1][j-1];
						if(maxsum < tempsum)
							maxsum = tempsum;
					}
		printf("%d\n", maxsum);
		if(N)
			printf("\n");
		maxsum = 0;
		len = 1;
		memset(mat, 0, sizeof(mat));
		getchar();
	}
	return 0;
}