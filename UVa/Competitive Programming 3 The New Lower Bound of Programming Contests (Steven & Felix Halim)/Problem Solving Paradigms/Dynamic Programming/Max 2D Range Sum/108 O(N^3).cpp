//Title: Maximum Sum
//Type: DP
//Complexity: O(N^3)
//Solution: Kadane's algorithm on Maximum Subarray Sum on a 2D matrix by converting 2D into 1D array. Classical 2D DP Problem.
#include <cstdio>
#include <cstring>
int mat[100][100], summat[100], N, tempsum, maxsum;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			scanf("%d", &mat[i][j]);
	maxsum = mat[0][0];
	for(int i = 0; i < N; i++){
		memset(summat, 0, sizeof(summat));
		for(int j = i; j < N; j++){
			summat[0] += mat[j][0];
			tempsum = summat[0];
			for(int k = 1; k < N; k++){
				summat[k] += mat[j][k];
				tempsum = -summat[k] > tempsum || tempsum < 0 ? summat[k] : summat[k] + tempsum;
				if(tempsum > maxsum)
					maxsum = tempsum;
			}
		}
	}
	printf("%d\n", maxsum);
	return 0;
}