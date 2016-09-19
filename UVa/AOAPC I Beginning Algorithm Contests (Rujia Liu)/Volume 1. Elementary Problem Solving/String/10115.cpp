//Title: Automatic Editing
//Type: Simulation
//Solution: Just do it!
#include <cstdio>
#include <cstring>
using namespace std;
int C;
char str[300], f[10][80], r[10][80];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(scanf("%d", &C) && C){
		getchar();
		for(int i = 0; i < C; i++){
			gets(f[i]);
			f[i][strlen(f[i])] = '\0';
			gets(r[i]);
			r[i][strlen(r[i])] = '\0';
		}
		gets(str);
		str[strlen(str)] = '\0';
		for(int i = 0; i < C; i++){
			int len = strlen(f[i]);
			bool complete = false;
			while(!complete){
				complete = true;
				int slen = strlen(str);
				for(int j = 0; j <= slen-len; j++){
					char cmp[80];
					strncpy(cmp, str+j, len);
					cmp[len] = '\0';
					if(!strcmp(cmp, f[i])){
						complete = false;
						char right[300];
						int rlen = strlen(str)-j-len;
						strncpy(right, str+j+len, rlen);
						right[rlen] = '\0';
						str[j] = '\0';
						strcat(str, r[i]);
						strcat(str, right);
						break;
					}
				}
			}
		}
		printf("%s\n", str);
	}
	return 0;
}