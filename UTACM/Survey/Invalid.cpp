#include <cstdio>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
int T, N, a, b, sum;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%d%d", &a, &b);
			if(a < 6 || a > 21 || b < 0 || b > 1024)
				sum++;
		}
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}