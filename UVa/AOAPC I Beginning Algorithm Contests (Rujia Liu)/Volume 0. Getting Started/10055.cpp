//Title: Hashmat the Brave Warrior
//Type: Brute Force
//Solution: Just do it!
#include <cstdio>
using namespace std;
long long i, j;
int main(){
	while(~scanf("%lld%lld", &i, &j))
		printf("%lld\n", j > i ? j - i : i - j);
	return 0;
}