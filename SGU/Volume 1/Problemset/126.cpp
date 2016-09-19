//Title: Boxes
//Type: Math
//Solution: Find the pattern, since we need (1/2N, 1/2N) to move everything to one box,
		/*	we can extend from (1/2N, 1/2N) to (3/4N, 1/4N) to (7/8N, 1/8N), (3/8N, 5/8N) and so on.
			Careful of (0, 0) = 0 exception */
#include <cstdio>
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int main(){
	//Instantiation
	int A, B;
	scanf("%d %d", &A, &B);
	//0, 0 exception
	if(!A || !B){
		printf("0\n");
		return 0;
	}
	//gcd
	int div = gcd(A, B);
	A /= div;
	B /= div;
	//if A+B ends up being odd, there will not be any solution
	if((A + B) & 1){
		printf("-1\n");
		return 0;
	}
	//make sure we have a 2+4 kind of exception for -1, make sure we have a 3+5 kind of exception for possible answer
	int t = A + B, ans = 0;
	while(t > 1)
		if(t%2 == 0){
			ans++;
			t>>=1;
		}else{
			ans = -1;
			break;
		}
	printf("%d\n", ans);
	return 0;
}