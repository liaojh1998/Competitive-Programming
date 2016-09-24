#include <cstdio>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int T, Q, sum, deck[1000][2], m;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &Q);
		for(int i = 0; i < Q; i++){
			scanf("%d%d", &deck[i][0], &deck[i][1]);
			if((deck[i][0]*deck[i][1]) > m)
				m = deck[i][0] * deck[i][1];
		}
		for(int i = 0; i < Q; i++){
			sum += m/deck[i][0];
		}
		printf("%d\n", sum);
		sum = m = 0;
	}
	return 0;
}