//Title: Triangle Wave
//Type: Simulation
//Solution: Just do it!
#include <cstdio>
int N, A, f;
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d%d", &A, &f);
		for(int j = 0; j < f; j++){
			for(int k = 1; k <= A; k++){
				for(int l = 0; l < k; l++)
					printf("%d", k);
				printf("\n");
			}
			for(int k = A-1; k >= 1; k--){
				for(int l = 0; l < k; l++)
					printf("%d", k);
				printf("\n");
			}
			if(j != f-1 || i != N-1) printf("\n");
		}
	}
	return 0;
}