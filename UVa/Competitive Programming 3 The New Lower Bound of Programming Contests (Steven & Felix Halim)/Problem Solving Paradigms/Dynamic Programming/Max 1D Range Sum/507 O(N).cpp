//Title: Jill Rides Again
//Type: DP
//Complexity: O(N)
//Solution: Kadane's algorithm on Maximum Subarray Sum
#include <cstdio>
int C, R, n, minloc, maxloc, temploc, subsum, maxsum;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &C);
	for(int r = 1; r <= C; r++){
		scanf("%d", &R);
		minloc = maxloc = temploc = 1;
		subsum = maxsum = 0;
		for(int i = 1; i < R; i++){
			scanf("%d", &n);
			if((subsum + n) >= 0)
				subsum += n;
			else{
				subsum = 0;
				temploc = i+1;
			}
			if(subsum > maxsum){
				maxsum = subsum;
				maxloc = i+1;
				minloc = temploc; 
			}else if(maxsum == subsum && (i+1 - temploc) > (maxloc-minloc)){
				maxloc = i+1;
				minloc = temploc; 
			}
		}
		if(!maxsum)
			printf("Route %d has no nice parts\n", r);
		else
			printf("The nicest part of route %d is between stops %d and %d\n", r, minloc, maxloc);
	}
	return 0;
}