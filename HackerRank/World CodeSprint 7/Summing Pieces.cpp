#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#define MOD (1000000007)
using namespace std;
int N;
long long bi[1000000];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//Oh god, why...?
	bi[0] = 1;
	for(int i = 1; i < 1000000; i++)
		bi[i] = (bi[i-1]<<1)%MOD;
	long long sum = 0, t;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%lld", &t);
		sum = (((((((((3*bi[i])%MOD - 1 + MOD)%MOD)*bi[N-i-1])%MOD) - bi[i] + MOD)%MOD)*(t%MOD))%MOD + sum)%MOD;
	}
	printf("%lld\n", sum);
	return 0;
}