//Title: The Sum
//Type: DP
//Solution: The most basic DP
#include <cstdio>
int K, fib[41];
int main(){
	//Instantiation
	fib[0] = 1;
	fib[1] = 1;
	for(int i = 2; i <= 40; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	//Sum
	for(int i = 1; i <= 40; i++){
		fib[i]+= fib[i-1];
	}
	//Print solution
	scanf("%d", &K);
	printf("%d\n", fib[K-1]);
	return 0;
}