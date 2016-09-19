//Title: Machined Surfaces
//Type: Brute Force
//Solution: Just do it!
#include <cstdio>
#include <cstring>
using namespace std;
char c;
int count[13], N, max, sum;
int main(){
	while(scanf("%d", &N), N){
		getchar();
		for(int i = 0; i < N; i++){
			for(int j = 0; j < 25; j++){
				scanf("%c", &c);
				if(c == 'X') count[i]++;
			}
			if(max < count[i]) max = count[i];
			getchar();
		}
		for(int i = 0; i < N; i++){
			sum+= max - count[i];
		}
		printf("%d\n", sum);
		memset(count, 0, sizeof(count));
		sum = 0;
		max = 0;
	}
	return 0;
}