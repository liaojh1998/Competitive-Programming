//Title: Rotating Sentences
//Type: Brute Force
//Solution: Just do it!
#include <cstdio>
using namespace std;
char str[100][100];
int v, h, k;
int main(){
	while(~scanf("%c", &str[v][k++])){
		if(str[v][k-1] == 10){
			v++;
			if(k-1 > h) h = k-1;
			k = 0;
		}
	}
	for(int i = 0; i < h; i++){
		for(int j = v-1; j >= 0; j--)
			if(str[j][i] == 10 || str[j][i] == 0)
				printf(" ");
			else
				printf("%c", str[j][i]);
		printf("\n");
	}
	return 0;
}