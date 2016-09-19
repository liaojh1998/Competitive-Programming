//Title: Digital Roots
//Type: Math
//Solution: Not sure where anyone could learn this, or is it really up to a person to find out the pattern. This solution is based on the solutions of the Internet.
		/*	The digital root of any number, or f(n) of n, is equivalent to n%9 (test it out).
			The DR of a*b is DR(DR(a)*DR(b)). The DR of a+b is DR(DR(a)+DR(b)). Now solving the problem is a piece of cake while using Horner's rule.	*/
#include <cstdio>
using namespace std;
int K;
int DR(int n){
	if((n%9)) return n%9;
	return 9;
}
int main(){
	//Instantiation
	scanf("%d", &K);
	//Function
	for(int i = 0; i < K; i++){
		int N;
		scanf("%d", &N);
		int seq[N];
		for(int j = 0; j < N; j++)
			scanf("%d", &seq[j]);
		//Horner's rule
		int num = 1;
		for(int j = N-1; j > 0; j--)
			num = DR(DR(DR(num)*DR(seq[j]))+1);
		num = DR(DR(num)*DR(seq[0]));
		printf("%d\n", num);
	}
	return 0;
}