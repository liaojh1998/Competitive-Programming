//Title: Ecological Premium
//Type: Brute Force
//Solution: Just do it!
#include <cstdio>
using namespace std;
int n, f, p, q;
long long i, j, k, sum;
int main(){
	scanf("%d", &n);
	for(p = 0; p < n; p++){
		sum = 0;
		scanf("%d", &f);
		for(q = 0; q < f; q++){
			scanf("%lld%lld%lld", &i, &j, &k);
			sum += i*k;
		}
		printf("%lld\n", sum);
	}
	return 0;
}