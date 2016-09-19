//Title: Integer Sequences from Addition of Terms
//Type: Simulation (Complete Search?)
//Complexity: O(1)
//Solution: Instead of iterating all the sequences, we can just go straight to k and print it.
#include <cstdio>
int poly[21], C, plen, p, d, k, n;
char c;
long long pow(int a, int exp){
	if(!exp) return 1;
	long long ans = a;
	for(int i = 1; i < exp; i++){
		ans *= a;
	}
	return ans;
}
long long b(int a){
	long long sum = 0;
	for(int i = 0; i <= plen; i++){
		sum += poly[i]*pow(a, i);
	}
	return sum;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &C);
	while(C--){
		scanf("%d", &plen);
		for(int i = 0; i <= plen; i++)
			scanf("%d", &poly[i]);
		scanf("%d%d", &d, &k);
		for(n = 1; n*d < k; n++)
			k -= n*d;
		printf("%lld\n", b(n));
	}
	return 0;
}