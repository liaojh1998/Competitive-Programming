//Title: Kindergarten Counting Game
//Type: Brute Force
//Solution: Just do it!
#include <cstdio>
#include <locale>
using namespace std;
char c;
int count;
bool has;
int main(){
	while(~scanf("%c", &c)){
		c = toupper(c);
		if(c == 10){
			if(has){
				count++;
				has = false;
			}
			printf("%d\n", count);
			count = 0;
		}else if(c < 'A' || c > 'Z'){
			if(has){
				count++;
				has = false;
			}
		}else
			has = true;
	}
	return 0;
}