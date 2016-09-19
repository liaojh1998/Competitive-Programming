//Title: Exponentiation
//Type: Math
//Solution: Oh Ma Gawd
#include <cstdio>
#include <cstring>
using namespace std;
char str[6];
int exp;
struct bigdouble{
	int num[1000], deci, len;
	void pow(int exp){
		deci *= exp;
		int prod[1000], temp[1000], plen = len;
		memcpy(prod, num, sizeof(num));
		while(--exp){
			memset(temp, 0, sizeof(temp));
			for(int i = 0; i < plen; i++){
				for(int j = 0; j < len; j++){
					temp[i+j] += prod[i]*num[j];
					temp[i+j+1] += temp[i+j]/10;
					temp[i+j] %= 10;
				}
			}
			for(int i = plen + len - 1; temp[i]; i++){
				temp[i+1] += temp[i]/10;
				temp[i] %= 10;
			}
			memcpy(prod, temp, sizeof(temp));
			int i = 999;
			for(; i > 0; i--)
				if(prod[i]){
					plen = i+1;
					break;
				}
			if(!i) plen = 0;
		}
		len = plen;
		memcpy(num, prod, sizeof(prod));
	}
	void print(){
		if(!len){
			printf("0\n");
			return;
		}
		if(deci > len){
			printf(".");
			for(int i = 0; i < deci-len; i++)
				printf("0");
		}
		int trail = 0;
		for(; !num[trail]; trail++);
		for(int i = len-1; i >= trail; i--){
			if(i+1 == deci) printf(".");
			printf("%d", num[i]);
		}
		printf("\n");
	}
	void clear(){
		memset(num, 0, sizeof(num));
	}
}num;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%s %d", &str, &exp)){
		int len = strlen(str);
		num.len = len-1;
		int k = num.len;
		for(int i = 0; i < len; i++)
			if(str[k] == '.'){
				num.deci = len-k-1;
				k--;
				i--;
			}
			else num.num[i] = str[k--]-'0';
		for(int i = num.len-1; i >= 0; i--)
			if(num.num[i]){
				num.len = i+1;
				break;
			}
		num.pow(exp);
		num.print();
		num.clear();
	}
	return 0;
}