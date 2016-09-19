//Type: Simulation
#include <cstdio>
#include <cstring>
int T, M, mood[6];
char str[9];
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &M);
		for(int i = 0; i < M; i++){
			memset(str, 0, sizeof(str));
			scanf("%s", &str);
			if(!strcmp(str, "ANGRY")) mood[0] = 1;
			else if(!strcmp(str, "SAD")) mood[1] = 1;
			else if(!strcmp(str, "HAPPY")) mood[2] = 1;
			else if(!strcmp(str, "CALM")) mood[3] = 1;
			else if(!strcmp(str, "JEALOUS")) mood[4] = 1;
			else if(!strcmp(str, "EXHAUSTED")) mood[5] = 1;
		}
		if(mood[5])
			printf("NO\n");
		else if(mood[1] & mood[3])
			printf("NO\n");
		else if(mood[1] & !mood[2] & !mood[0])
			printf("NO\n");
		else
			printf("YES\n");
		memset(mood, 0, sizeof(mood));
	}
	return 0;
}