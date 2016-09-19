//Title: Magic Pairs
//Type: Math
//Solution: http://d.ream.at/sgu-119/
		/*	Let's rephrase this weird question.
			Find pairs A, B such that using the X and Y in A0X + B0Y to make the sum divisible by N in AX + BY can also make that sum divisible by N.
			Sounds better?
			Euclidean Algorithm. All pairs are found for(k = 0 --> N/gcd) (kA%N, kB%N) are the given answers.	*/
#include <cstdio>
#include <algorithm>
using namespace std;
struct p{
	int a, b;
	bool operator<(const p &n){
		if(a == n.a)
			return b < n.b;
		return a < n.a;
	}
}pairs[10000];
int gcd(int a, int b){
	return b ? gcd(b, a%b) : a;
}
int main(){
	//Instantiation
	int A, B, N;
	scanf("%d %d %d", &N, &A, &B);
	//Solution
	int div = gcd(gcd(A, B), N);
	printf("%d\n", N/div);
	for(int i = 0; i < N/div; i++){
		pairs[i].a = i*A%N;
		pairs[i].b = i*B%N;
	}
	sort(pairs, pairs+N/div);
	for(int i = 0; i < N/div; i++){
		printf("%d %d\n", pairs[i].a, pairs[i].b);
	}
	return 0;
}