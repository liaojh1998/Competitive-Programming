//Title: Closest Sums
//Type: Complete Search
//Complexity: O(N^2)
//Solution: Pure brute force solution based on finding the closest pair using a nested for loop for each query.
#include <cstdio>
int n, m, a[1000], q, c;
int abs(int i){
	if(i < 0)
		return -i;
	return i;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(scanf("%d", &n) && n){
		printf("Case %d:\n", ++c);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for(int i = 0; i < m; i++){
			scanf("%d", &q);
			int diff = 1<<31-1, sum = 0;
			for(int j = 0; j < n; j++)
				for(int k = 0; k < n; k++)
					if(j != k && abs(a[j]+a[k]-q) < diff){
						diff = abs(a[j]+a[k]-q);
						sum = a[j]+a[k];
					}
			printf("Closest sum to %d is %d.\n", q, sum);
		}
	}
	return 0;
}