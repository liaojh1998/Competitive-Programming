#include <cstdio>
void print(int n){
	if(!n)
		return;
	print(n>>1);
	printf("%d", n&1);
}
int main(){
	int n;
	while(~scanf("%d", &n)){
		print(n);
		printf("\n");
	}
	return 0;
}