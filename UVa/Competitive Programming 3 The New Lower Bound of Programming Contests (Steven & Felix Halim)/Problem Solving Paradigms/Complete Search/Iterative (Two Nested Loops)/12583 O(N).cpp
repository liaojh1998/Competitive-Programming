//Title: Memory Overflow
//Type: Complete Search
//Complexity: O(N)
//Solution: Since everything is relative, make a array of last encountered time so there's no need to do this problem in 2 nested loop format.
#include <cstdio>
#include <cstring>
int C, n, k, N[26], sum;
char str[500], c;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &C);
	for(int p = 1; p <= C; p++){
		scanf("%d %d %s", &n, &k, &str);
		for(int i = 1; i <= n; i++){
			c = str[i-1];
			if(N[c-'A'] && i - N[c-'A'] <= k)
				sum++;
			N[c-'A'] = i;
		}
		printf("Case %d: %d\n", p, sum);
		sum = 0;
		memset(N, 0, sizeof(N));
	}
	return 0;
}