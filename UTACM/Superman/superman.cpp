#include <cstdio>
#include <algorithm>
using namespace std;
struct bar{
	long long N, M, V;
}bank[600];
int T, B;
long long W;
bool cmp(const bar &a, const bar &b){
	return a.V > b.V;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%lld", &B, &W);
		for(int i = 0; i < B; i++){
			scanf("%lld%lld%lld", &bank[i].N, &bank[i].M, &bank[i].V);
		}
		sort(bank, bank+B, cmp);
		long long sum = 0;
		for(int i = 0; i < B; i++){
			if(W > bank[i].N*bank[i].M){
				W -= bank[i].N*bank[i].M;
				sum += bank[i].N*bank[i].M*bank[i].V;
			}else{
				sum += W*bank[i].V;
				break;
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}