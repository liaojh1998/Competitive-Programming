//Title: Even Fibonacci numbers
//Solution: Experiment
#include <cstdio>
#include <cmath>
using namespace std;
int len, T;
long long efib[29], sum[29], N;
//After experimentation, found that 28th efib is bigger than 4*10^16, so only need 28 efibs.
int main(){
	freopen("2.in", "r", stdin);
	freopen("2.out", "w", stdout);
	efib[0] = sum[0] = 0;
	efib[1] = sum[1] = 2;
	efib[2] = 8;
	sum[2] = efib[2] + sum[1];
	for(len = 3; len < 29; len++){
		efib[len] = 4*efib[len-1] + efib[len-2];
		sum[len] = efib[len] + sum[len-1];
	}
	scanf("%d", &T);
	while(T--){
		scanf("%lld", &N);
		for(int i = 0; i < 29; i++)
			if(N <= efib[i]){
				printf("%lld\n", sum[i-1]);
				break;
			}
	}
}