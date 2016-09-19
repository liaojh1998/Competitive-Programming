//Title: Party Time
//Type: Math, median
#include <cstdio>
#include <algorithm>
using namespace std;
int T, x[1001], y[1001], F;
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &F);
		for(int i = 0; i <= F; i++)
			scanf("%d%d", &x[i], &y[i]);
		sort(x, x+F+1);
		sort(y, y+F+1);
		printf("%d %d\n", x[(F+1)/2], y[(F+1)/2]);
	}
	return 0;
}