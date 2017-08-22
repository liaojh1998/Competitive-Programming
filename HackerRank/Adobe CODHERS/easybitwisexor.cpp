#include <cstdio>
long long ceil(long long a, long long b){
	return (a%b) ? (a/b)+1 : a/b;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int Q;
	scanf("%d", &Q);
	while(Q--){
		printf("i s a\n");
		long long a, b, d, m;
		scanf("%lld%lld%lld%lld", &a, &b, &d, &m);
		if(a >= b){
			printf("0\n");
			continue;
		}
		if(d%2){
			long long seq = ceil(b, d)-1;
			printf("%lld\n", ((((seq%m*(seq+1)%m)%m)*(d%m))/2 + ((a%m)*((seq+1)%m))%m)%m);
		}else{
			long long seq = ceil(b, d)-1;
			printf("%lld\n", (((((seq%m*(seq+1)%m)%m)*(d%m))/2)%m + seq%m + 1 + ((a%m)*((seq+1)%m))%m)%m);
		}
		long long s = 0;
		int it = 0;
		while(a < b){
			s = (s%m + (a^1)%m)%m;
			a = a + d;
			printf("%d %lld %lld\n", ++it, s, a);
		}
		printf("%lld\n", s);

	}
	return 0;
}