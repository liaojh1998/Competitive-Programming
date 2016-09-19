//Title: Patties
//Type: Math
//Solution: Is this supposed to be hard?
#include <cstdio>
int P, M, C, K, R, V;
int main(){
	//Instantiation
	scanf("%d %d %d %d %d %d", &P, &M, &C, &K, &R, &V);
	int a = P/K, b = M/R, c = C/V;
	a = a < b ? a : b;
	a = a < c ? a : c;
	//Print answer
	printf("%d\n", a);
	return 0;
}