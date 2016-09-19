//Title: Factorial
//Type: Math
//Solution: This was a little harder than expected. Thanks to the symmetries of 5s.
#include <cstdio>
int Q;
int q(int i){
	int count = 0;
	while(i){
		count += i/5;
		i /= 5;
	}
	return count;
}
int main(){
	//Instantiation
	scanf("%d", &Q);
	//Print answer
	//0 Case
	if(!Q){
		printf("1\n");
		return 0;
	}
	//All else
	//Since Q = N/5 + N/5^2 + N/5^3...
	//We can derive a function for the geometric progression: Q = N(5^k-1)/(4(5^k))
	//Change the function, since we want to find N, into N = 4*Q*(5^k)/(5^k-1)
	//The range for N then, is 4Q(k = inf) < N <= 5Q(k = 1)
	//We'll continuously search from 4Q to 5Q for the answer and if its not present by checking multiplication of 5s for 0s, then there is no solution.
	int i = 4*Q/5*5;
	while(q(i) < Q)
		i += 5;
	if(q(i) == Q)
		printf("%d\n", i);
	else
		printf("No solution\n");
	return 0;
}