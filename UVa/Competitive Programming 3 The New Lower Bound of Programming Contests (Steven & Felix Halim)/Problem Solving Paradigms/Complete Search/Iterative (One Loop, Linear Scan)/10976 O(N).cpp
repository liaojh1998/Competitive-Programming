//Title: Fractions Again!
//Type: Complete Search
//Complexity: O(N)
//Solution: Ugh Fractions again! Either ways, rearrange that fraction equation for a solution if you will. There's no need to read this solution.
#include <cstdio>
#include <cstring>
int k, x[1000], y[1000], len;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%d", &k)){
		for(int i = k+1;; i++){
			if(!((k*i) % (i-k))){
				y[len] = i;
				x[len++] = (k*i)/(i-k);
				if(y[len-1] == x[len-1]) break;
			}
		}
		printf("%d\n", len);
		for(int i = 0; i < len; i++)
			printf("1/%d = 1/%d + 1/%d\n", k, x[i], y[i]);
		len = 0;
	}
	return 0;
}