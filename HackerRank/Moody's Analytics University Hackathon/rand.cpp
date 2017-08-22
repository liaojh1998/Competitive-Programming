#include <cstdio>
int main(){
	freopen("input.txt", "w", stdout);
	printf("100000\n");
	for(int i = 0; i < 99999; i++)
		printf("%d ", i);
	printf("99999\n");
	for(int i = 1; i <= 99999; i++)
		printf("%d %d\n", i, i+1);
	return 0;
}