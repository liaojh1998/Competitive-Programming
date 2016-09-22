//Title: Tour de France
//Type: Complete Search
//Complexity: O(N^4)
//Solution: I wish I could actually go on a tour in france!
#include <cstdio>
#include <algorithm>
using namespace std;
int f, r, fi[10], ri[10], rlen;
double ratio[100], spread;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(scanf("%d", &f) && f){
		scanf("%d", &r);
		for(int i = 0; i < f; i++)
			scanf("%d", &fi[i]);
		for(int i = 0; i < r; i++)
			scanf("%d", &ri[i]);
		for(int i = 0; i < f; i++)
			for(int j = 0; j < r; j++)
				ratio[rlen++] = (double)ri[j]/fi[i];
		sort(ratio, ratio+rlen);
		for(int i = 1; i < rlen; i++)
			if(spread < ratio[i]/ratio[i-1])
				spread = ratio[i]/ratio[i-1];
		printf("%.2f\n", spread);
		spread = rlen = 0;
	}
	return 0;
}