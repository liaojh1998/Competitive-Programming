#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
	return b ? gcd(b, a%b) : a;
}

long long fexp(long long b, long long p, long long MOD){
	long long ans = 1;
	while(p){
		if(p&1)
			ans = (ans * b)%MOD;
		b = (b * b)%MOD;
		p >>= 1;
	}
	return ans;
}
long long modinverse(long long a, long long n){
		long long t = 0, newt = 1, r = n, newr = a, div, temp;
		int count = 0;
		while(newr){
			div = r/newr;
			temp = newt;
			newt = t - div*newt;
			t = temp;
			temp = newr;
			newr = r - div*newr;
			r = temp;
		}
		if(t < 0)
			t = t + n;
		return t;
	}

int main(){
	/*printf("Enter a: ");
	long long a, p;
	cin >> a;
	printf("Enter p: ");
	cin >> p;
	printf("Find %lldx = 1 mod %lld\n", a, p);
	printf("Reducing...\n");
	a %= p;
	printf("Find %lldx = 1 mod %lld\n", a, p);
	long long div = gcd(a, p);
	printf("gcd(%lld, %lld): %lld\n", a, p, div);
	printf("Find %lldx = 1 mod %lld\n", a/div, p/div);
	if(p/div == 1){
		printf("NOT POSSIBLE, mod = 1\n");
	}else{
		long long inv = fexp(a/div, p/div-2, p/div);
		printf("Modular multiplicative inverse x = %lld\n", inv);
		printf("Verify: %lld*%lld = %lld mod %lld\n", a/div, inv, (a/div*inv)%(p/div), p/div);
		printf("New modular multiplicative inverse x = %lld\n", inv*div);
		printf("Verify: %lld*%lld = %lld mod %lld\n", a, inv*div, (a*inv*div)%p, p);
		printf("EH...\n");
		printf("For all other possible inverses?\n");
		for(long long i = 1; i < p; i++)
			printf("%lld*%lld = %lld mod %lld\n", a, i, (a*i)%p, p);
	}*/
	long long n, p, MOD;
	while(n){
		cin >> n >> p;
		cout << modinverse(n, p) << endl;
	}
	return 0;
}