//Title: Encoding
//Type: Simulation
//Solution: Okay, let me show you phi(W) function, but with numbers. Simply simulate where the location of q will be after going through phi.
#include <cstdio>
int N, q;
int phi(int len, int q){
	if(len == 1)
		return 1;
	int len2 = len - len/2;
	if(q > len/2)
		return phi(len2, len-q+1);
	else
		return len2 + phi(len/2, len/2-q+1);
}
int main(){
	//Instantiation
	scanf("%d %d", &N, &q);
	printf("%d\n", phi(N, q));
	return 0;
}