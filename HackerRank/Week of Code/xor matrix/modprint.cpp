#include <cstdio>
#include <cmath>
int main(){
	long long n;
	while(~scanf("%lld", &n)){
		long long q = (long long)1<<((long long)log2(n));
		printf("%lld %lld\n", q, (long long)log2(n));
	}
	return 0;
}