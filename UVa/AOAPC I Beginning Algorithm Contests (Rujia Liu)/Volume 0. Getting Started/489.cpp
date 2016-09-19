//Title: Hangman Judge
//Type: Simulation
//Solution: Just do it!
#include <cstdio>
#include <cstring>
using namespace std;
int r, len, wrong;
char str[100], c;
bool b[200], test[200], lose, done;
void reset(){
	memset(str, 0, sizeof(str));
	memset(b, 0, sizeof(b));
	memset(test, 0, sizeof(test));
	len = 0;
	wrong = 0;
	lose = false;
	done = false;
}
int main(){
	while(~scanf("%d", &r) && r != -1){
		getchar();
		printf("Round %d\n", r);
		while(scanf("%c", &c) && c != 10){
			str[len++] = c;
			b[c] = true;
		}
		while(scanf("%c", &c) && c != 10){
			if(!done){
				if(!test[c]){
					test[c] = true;
					if(!b[c]){
						wrong++;
					}else b[c] = false;
				}
				done = true;
				for(int i = 0; i < len; i++)
					if(b[str[i]]) done = false;
				if(wrong == 7)
					lose = true;
			}
		}
		if(lose){
			printf("You lose.\n");
			reset();
			continue;
		}
		for(int i = 0; i < len; i++)
			if(b[str[i]]) lose = true;
		if(lose){
			printf("You chickened out.\n");
			reset();
			continue;
		}
		printf("You win.\n");
		reset();
	}
	return 0;
}