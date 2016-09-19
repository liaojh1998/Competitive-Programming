//Title: X-Sequence
//Type: Math
//Solution: Rotating storage (Since mod, and no mod more than 1000) + Pigeonhole principle and do brute force.
#include <cstdio>
int A, a, b, g, M, k, loc[1001], ans[1001], len1, len2;
int main(){
	scanf("%d%d%d%d%d%d", &A, &a, &b, &g, &M, &k);
	//k == 0 exception
	if(!k){
		printf("%d\n", A);
		return 0;
	}
	//Pigeonhole principle for both k and xk, a memory array for location and a memory array for value
	//For loop all the way till M because if k = 1000 and M = 1000, and len1 is 1 and len2 is M-1, (k-len1)%len2+len1 will not give out 1000
	A %= M;
	for(int i = 1; i <= M; i++){
		A = (a*A*A + b*A + g)%M;
		ans[i] = A;
		if(loc[A]){
			len1 = loc[A];
			len2 = i-loc[A];
		}
		loc[A] = i;
	}
	//Print answer
	if(k <= M) printf("%d\n", ans[k]);
	else printf("%d\n", ans[(k-len1)%len2+len1]);
	return 0;
}