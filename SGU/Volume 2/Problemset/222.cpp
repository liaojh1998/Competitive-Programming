//Title: Little Rooks
//Type: Math
//Solution: Combination numbers
#include <cstdio>
int n, k;
int main(){
	scanf("%d %d", &n, &k);
	if(k > n){
		printf("0\n");
		return 0;
	}
	long long int ans = 1;
	for(int i = n; i > n - k; i--)
		ans *= i*i;
	for(int i = k; i > 1; i--)
		ans /= i;
	printf("%d\n", ans);
	return 0;
}