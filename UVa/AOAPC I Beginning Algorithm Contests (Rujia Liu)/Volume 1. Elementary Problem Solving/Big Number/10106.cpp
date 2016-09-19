//Title: Product
//Type: Math
//Solution: Make your own big number multiplications!
#include <cstdio>
#include <cstring>
using namespace std;
char n1[300], n2[300];
int prod[700], num1[300], num2[300];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%s", &n1)){
		getchar();
		scanf("%s", &n2);
		getchar();
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
		if(!(n1[0]-'0') || !(n2[0]-'0')){
			printf("0\n");
			continue;
		}
		int len1 = strlen(n1);
		int len2 = strlen(n2);
		for(int i = len1-1; i >= 0; i--)
			num1[len1-1-i] = n1[i]-'0';
		for(int i = len2-1; i >= 0; i--)
			num2[len2-1-i] = n2[i]-'0';
		//Make your own high precision multiplication algorithms
		for(int i = 0; i < len1; i++)
			for(int j = 0; j < len2; j++){
				prod[i+j] += num1[i]*num2[j];
				prod[i+j+1] += prod[i+j]/10;
				prod[i+j] %=10;
			}
		for(int i = len1+len2-1; prod[i] >= 10; i++){
			prod[i+1] += prod[i]/10;
			prod[i] %=10;
		}
		int len = 699;
		for(;; len--)
			if(prod[len]) break;
		for(int i = len; i >= 0; i--)
			printf("%d", prod[i]);
		printf("\n");
		memset(prod, 0, sizeof(prod));
	}
	return 0;
}