//Title: The Decoder
//Type: Brute Force
//Solution: Just do it!
#include <cstdio>
#include <cstring>
using namespace std;
char str[1000];
int len;
int main(){
	while(~scanf("%s", &str)){
		len = strlen(str);
		for(int i = 0; i < len; i++)
			str[i]-= 7;
		printf("%s\n", str);
	}
	return 0;
}