//Title: Start Grid
//Type: Complete Search
//Complexity: O(N^2)
//Solution: Location check with 2 nested loop
#include <cstdio>
int n, oloc[30], floc[30], p, sum;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%d", &n)){
		for(int i = 0; i < n; i++){
			scanf("%d", &p);
			oloc[p] = i;
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &p);
			floc[p] = i;
		}
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(oloc[i] < oloc[j] && floc[i] > floc[j])
					sum++;
			}
		}
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}