//Title: Marvelous Mazes
//Type: Brute Force
//Solution: Just do it!
#include <cstdio>
#include <cstring>
using namespace std;
char c;
int n;
int main(){
	while(~scanf("%c", &c)){
		if(c >= 48 && c <= 57)
			n+= c-'0';
		else if(c == 'b')
			for(; n > 0; n--)
				printf(" ");
		else if(c == '!' || c == 10)
			printf("\n");
		else
			for(; n > 0; n--)
				printf("%c", c);
	}
	return 0;
}