//Title: 987654321 problem
//Type: Math
//Solution: Find the pattern. We know anything lower than 8 has solution of 0 because 8 digits squared will not end up with 987654321 ending.
		/*	However, for N = 9, there are 8 solutions:
			111111111
			119357639
			380642361
			388888889
			611111111
			619357639
			880642361
			888888889
			For N = 10, we know our solution will contain solutions from N = 9, but because it starts from 10 digits rather than 9 digits, it will only have 9 sets
			rather than 10 sets of the 8 solutions from N = 9, therefore there are 8 * 9 = 72 solutions.
			For N > 10, we know our solution will contain solutions from the previous and will be 10 sets of the previous, thus 8 * 9 * (N - 10) * 10 solutions.
			*/
#include <stdio.h>
int main(){
	//Instantiation;
	int N;
	scanf("%d", &N);
	if(N <= 8) printf("0\n");
	else if(N == 9) printf("8\n");
	else{
		printf("72");
		for(int i = 0; i < N - 10; i++) printf("0");
		printf("\n");
	}
	return 0;
}