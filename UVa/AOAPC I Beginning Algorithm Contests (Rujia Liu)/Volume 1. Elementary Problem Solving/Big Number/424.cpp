//Title: Integer Inquiry
//Type: Math
//Solution: Make your own big number additions!
#include <cstdio>
#include <cstring>
using namespace std;
char str[200];
int sol[2000], num[200];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(scanf("%s", &str) && (str[0]-'0')){
		getchar();
		int len = strlen(str);
		memset(num, 0, sizeof(num));
		for(int i = len-1; i >= 0; i--)
			num[len-1-i] = str[i]-'0';
		//Make your own high precision addition algorithm lolz
		for(int i = 0; i < len; i++){
			sol[i] += num[i];
			while(sol[i] >= 10){
				sol[i+1]++;
				sol[i]-=10;
			}
		}
		for(int i = len; sol[i] >= 10; i++){
			while(sol[i] >= 10){
				sol[i+1]++;
				sol[i]-=10;
			}
		}
	}
	int len = 1999;
	for(;; len--)
		if(sol[len]) break;
	for(int i = len; i >= 0; i--)
		printf("%d", sol[i]);
	printf("\n");
	return 0;
}