//Title: The Collatz Sequence
//Type: Math
//Solution: Just do it!
#include <cstdio>
using namespace std;
long long A, lim;
int count, i;
int main(){
	while(scanf("%lld%lld", &A, &lim) && A > 0 && lim > 0){
		i++;
		printf("Case %d: A = %lld, limit = %lld, number of terms = ", i, A, lim);
		while(A <= lim){
			if(A == 1){
				count++;
				break;
			}
			if(A&1) A = A*3+1;
			else A/= 2;
			count++;
		}
		printf("%d\n", count);
		count = 0;
	}
	return 0;
}