#include <cstdio>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int T, N, points[2];
char names[2][30], temp[30];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d%s%s", &N, &names[0], &names[1]);
		getchar();
		for(int i = 0; i < N; i++){
			gets(temp);
			if(!strcmp(names[0], temp)){
				if(points[0] == 3 && points[1] == 4)
					points[1]--;
				else
					points[0]++;
			}else{
				if(points[1] == 3 && points[0] == 4)
					points[0]--;
				else
					points[1]++;
			}
			if(points[0] < 3 && points[1] == 4)
				printf("%s won!", names[1]);
			else if(points[1] < 3 && points[0] == 4)
				printf("%s won!", names[0]);
			else if(points[0] == 3 && points[1] == 5)
				printf("%s won!", names[1]);
			else if(points[1] == 3 && points[0] == 5)
				printf("%s won!", names[0]);
			else if(points[0] == points[1] && points[0] == 3)
				printf("deuce");
			else if(points[0] == 4 && points[1] == 3)
				printf("advantage %s", names[0]);
			else if(points[1] == 4 && points[0] == 3)
				printf("advantage %s", names[1]);
			else{
				switch(points[0]){
					case 0: printf("love"); break;
					case 1: printf("15"); break;
					case 2: printf("30"); break;
					case 3: printf("40"); break;
				}
				printf(" ");
				if(points[0] == points[1])
					printf("all");
				else
					switch(points[1]){
						case 0: printf("love"); break;
						case 1: printf("15"); break;
						case 2: printf("30"); break;
						case 3: printf("40"); break;
					}
			}
			printf("\n");
		}
		memset(points, 0, sizeof(points));
	}
	return 0;
}