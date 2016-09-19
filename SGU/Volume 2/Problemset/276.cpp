//Title: Andrew's Troubles
//Type: Brute Force
//Solution: What?
#include <cstdio>
int S, P;
int main(){
	//Instantiation
	scanf("%d %d", &S, &P);
	P -= S;
	//Print Answer
	if(P && P >= 1800)
		printf("4\n");
	else if(P && P >= 900 && P < 1800)
		printf("3\n");
	else if(P && P >= 300 && P < 900)
		printf("2\n");
	else if(P && P > 0 && P < 300)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}