//Type: Simulation
#include <cstdio>
#include <cstring>
int T, N, M, p, q;
long long m[150000], total, sum;
char command[9];
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; i++){
			scanf("%lld", &m[i]);
			total += m[i];
		}
		for(int i = 0; i < M; i++){
			memset(command, 0, sizeof(command));
			scanf("%s", &command);
			if(!strcmp(command, "MULTIPLY")){
				scanf("%d%d", &p, &q);
				m[p]*=q;
			}else if(!strcmp(command, "ADD")){
				scanf("%d%d", &p, &q);
				m[p]+=q;
			}else if(!strcmp(command, "GET")){
				scanf("%d%d", &p, &q);
				sum = 0;
				for(int j = p; j <= q; j++)
					sum+= m[j];
				printf("%lld\n", sum);
			}else{
				sum = 0;
				for(int j = 0; j < N; j++)
					sum+= m[j];
				printf("%lld", total - sum);
			}
		}
		memset(m, 0, sizeof(m));
		total = 0;
	}
}