//Title: Drawing Lines
//Type: Math
//Solution: Find the pattern basically
		/*	Lines Max
			0		1
			1		2
			2		4
			3		7
			4		11
			5		16
			6		22
			N 		Lines[N-1] + N*/
#include <cstdio>
long long N;
int main(){
	//Instantiation
	scanf("%d", &N);
	//Print answer
	printf("%lld\n", N*(N+1)/2+1);
	return 0;
}