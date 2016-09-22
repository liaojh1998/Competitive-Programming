//Title: Sales
//Type: Complete Search
//Complexity: O(N^2)
//Solution: This is the complete search concept before I come up with a dynamic programming solution.
		/*	After thoughtful considerations, there's an optimization for this program using a tree representation of the ai array,
			but due to simplicity of the problem, I'll not be implementing the O(NlogN) solution. */
#include <cstdio>
int C, a[5000], len, sum;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &C);
	while(C--){
		scanf("%d", &len);
		for(int i = 0; i < len; i++)
			scanf("%d", &a[i]);
		//O(N^2) solution
		for(int i = 1; i < len; i++)
			for(int j = i-1; j >= 0; j--)
				if(a[j] <= a[i])
					sum++;
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}