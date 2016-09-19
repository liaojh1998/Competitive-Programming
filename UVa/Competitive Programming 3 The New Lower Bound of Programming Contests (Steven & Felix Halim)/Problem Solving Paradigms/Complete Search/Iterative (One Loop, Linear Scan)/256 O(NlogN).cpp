//Title: Quirksome Squares
//Type: Complete Search
//Complexity: O(NlogN)
//Solution: You know we can just store everything in a table right, let's make this solution simple as O(1).
#include <cstdio>
int N, len;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%d", &N)){
		len = 1;
		for(int i = 0; i < N/2; i++)
			len *= 10;
		for(int i = 0; i < len; i++){
			for(int j = 0; j < len; j++){
				int w = i * len + j;
				//Just a little bit of pruning can change this from O(N^2) to O(NlogN)
				if(w < (i+j)*(i+j)) break;
				if(w == (i+j)*(i+j)){
					for(int k = len*len/10; k > 0; k/=10){
						printf("%d", w/k);
						w %= k;
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}