//Title: Counting
//Type: Math (Factorization)
//Solution: Original thoughts: Sieve of Eratostenes out all the primes and factor out everything of N and K,
		/*	then multiply the factors of N by M and see if they're bigger than the factors of K. If so, divisible.
			Quick note: http://blog.csdn.net/a601025382s/article/details/9399861
			We can take Ni%K each time we multiply the number by itself. Since the mod represent the remainder that will need to be modded again, if the mod becomes 0,
			then Ni^M will always be divisible by K. This is the same concept as factorization. This solution is same as above and is much faster and smaller.*/
#include <cstdio>
using namespace std;
int N, M, K, sum;
int check(int Ni){
	int Mt = M, div = 1;
	while(Mt && div){
		if(Mt&1) //Still don't understand why odd parts?
			div = (div*Ni)%K;
		Ni = (Ni*Ni)%K;
		Mt>>=1;
	}
	return div;
}
int main(){
	//Instantiation
	scanf("%d %d %d", &N, &M, &K);
	//Check Ni
	for(int i = 0; i < N; i++){
		int Ni;
		scanf("%d", &Ni);
		if(!check(Ni))
			sum++;
	}
	printf("%d\n", sum);
	return 0;
}