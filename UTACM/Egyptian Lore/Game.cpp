//Type: Simulation
#include <cstdio>
#include <cstring>
int T, N, M, key, i, j;
char command[8];
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &N, &M, &key);
		for(int k = 0; k < M; k++){
			memset(command, 0, sizeof(command));
			scanf("%s", &command);
			if(!strcmp(command, "REVERSE"))
				key = N-1-key;
			else{
				scanf("%d%d", &i, &j);
				if(i != j){
					if(i == key)
						key = j;
					else if(j == key)
						key = i;
				}
			}
		}
		printf("%d\n", key);
	}
}