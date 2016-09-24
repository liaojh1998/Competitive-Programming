#include <cstdio>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
struct r{int low, high;}range[1000];
int T, N, M, sum;
double tutor;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; i++)
			scanf("%d%d", &range[i].low, &range[i].high);
		for(int i = 0; i < M; i++){
			scanf("%lf", &tutor);
			for(int j = 0; j < N; j++)
				if(tutor < range[j].high && tutor >= range[j].low)
					sum++;
			printf("%d\n", sum);
			sum = 0;
		}
	}
	return 0;
}