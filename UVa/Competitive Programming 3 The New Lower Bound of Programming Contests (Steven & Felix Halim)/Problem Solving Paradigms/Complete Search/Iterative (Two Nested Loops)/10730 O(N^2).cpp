//Title: Antiarithmetic?
//Type: Complete Search
//Complexity: O(N^2)
//Solution: Enumeration using a median, set i as median, 0 -> i-1 before median and i+1 -> n after median (store this in location array to prune search).
		/*	This works if and only if numbers are distinct, and as stated, it is. */
#include <cstdio>
#include <cstring>
int n, p[10010], loc[10010];
bool arith(){
	for(int i = 1; i < n; i++)
		for(int j = 0; j < i; j++){
			int next = 2*p[i]-p[j];
			if(next >= 0 && next < n && loc[next] > loc[p[i]])
				return true;
		}
	return false;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(scanf("%d:", &n) && n){
		for(int i = 0; i < n; i++){
			scanf("%d", &p[i]);
			loc[p[i]] = i;
		}
		printf(arith() ? "no\n" : "yes\n");
	}
	return 0;
}