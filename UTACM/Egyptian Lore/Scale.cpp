//Type: Simulation
#include <cstdio>
#include <algorithm>
int T, N, p[10005], count, total;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
			scanf("%d", &p[i]);
		std::sort(p, p+N);
		for(int i = 0; i < N; i++){
			if(p[i] >= total){
				total+= p[i];
				count++;
			}
		}
		printf("%d\n", count);
		count = total = 0;
	}
	return 0;
}