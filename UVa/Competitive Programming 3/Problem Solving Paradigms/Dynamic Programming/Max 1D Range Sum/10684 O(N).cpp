//Title: The jackpot
//Type: DP
//Complexity: O(N)
//Solution: Kadane's algorithm on Maximum Subarray Sum once again
#include <cstdio>
int N, b, subsum, maxsum;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%d", &N) && N){
		for(int i = 0; i < N; i++){
			scanf("%d", &b);
			subsum = -b > subsum ? 0 : subsum + b;
			if(maxsum < subsum)
				maxsum = subsum;
		}
		if(!maxsum)
			printf("Losing streak.\n");
		else
			printf("The maximum winning streak is %d.\n", maxsum);
		maxsum = subsum = 0;
	}
	return 0;
}