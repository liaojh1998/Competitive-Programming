//Title: Garbage Heap
//Type: DP
//Complexity: O(N^5)
//Solution: Kadane's algorithm on Maximum Subarray Sum but in 3D, the process is the same for submatrix with largest sum for 2D.
		/*	Basically, combine 3D into 1D and Kadane over the array */
#include <cstdio>
#include <cstring>
int N, A, B, C, i, j, k;
long long mat[21][21][21], summat[21][21][21], sum;
long long kadane(int x, int y){
	long long tempsum = summat[x][y][1];
	long long maxsum = tempsum;
	for(int index = 2; index <= C; index++){
		tempsum = -summat[x][y][index] >= tempsum || tempsum < 0 ? summat[x][y][index] + 0 : summat[x][y][index] + tempsum;
		if(tempsum > maxsum)
			maxsum = tempsum;
	}
	return maxsum;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	while(N--){
		scanf("%d%d%d", &A, &B, &C);
		for(i = 1; i <= A; i++)
			for(j = 1; j <= B; j++)
				for(k = 1; k <= C; k++)
					scanf("%lld", &mat[i][j][k]);
		sum = mat[1][1][1];
		for(int ileft = 1; ileft <= A; ileft++)
			for(int jleft = 1; jleft <= B; jleft++){
				memset(summat, 0, sizeof(summat));
				for(int iright = ileft; iright <= A; iright++)
					for(int jright = jleft; jright <= B; jright++){
						for(k = 1; k <= C; k++)
							summat[iright][jright][k] = summat[iright-1][jright][k] + summat[iright][jright-1][k] + mat[iright][jright][k] - summat[iright-1][jright-1][k];
						long long tempsum = kadane(iright, jright);
						if(tempsum > sum)
							sum = tempsum;
					}
			}
		printf("%lld\n", sum);
		if(N)
			printf("\n");
	}
	return 0;
}