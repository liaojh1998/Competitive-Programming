//Title: Expert Enough?
//Type: Complete Search
//Complexity: O(N^2)
//Solution: You're already an expert man. Besides, I'm truly too lazy to come up with any solution that goes below O(N^2).
#include <cstdio>
#include <cstring>
int C, D, low[10000], high[10000], Q, d, n;
char brand[10000][20], temp[20];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &C);
	while(C--){
		scanf("%d", &D);
		for(int i = 0; i < D; i++)
			scanf("%s%d%d", &brand[i], &low[i], &high[i]);
		scanf("%d", &Q);
		for(int i = 0; i < Q; i++){
			scanf("%d", &d);
			n = 0;
			for(int j = 0; j < D; j++)
				if(d >= low[j] && d <= high[j]){
					n++;
					memcpy(temp, brand[j], sizeof(brand[j]));
				}
			if(n != 1)
				printf("UNDETERMINED\n");
			else
				printf("%s\n", temp);
		}
		if(C)
			printf("\n");
	}
	return 0;
}