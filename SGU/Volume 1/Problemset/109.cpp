//Title: Magic of David Copperfield II
//Type: Math/Structure
//Solution: I don't know about David Copperfield, but I know this is no magic.
		/*	We don't have to follow the way sample input works to force a person into only 1 picture.
			Consider the odd-even properties.
			Starting from any start point and walking an odd number of steps, you will never return to your original starting position, which require an even number of steps to arrive at.
			In other words, starting from any start point, you'll never be able to walk to a place that require an even number of steps to arrive at.
			Another fact, pictures that require an even number of steps to arrive to are placed diagonally next to each other, so is the odd number ones.
			Like this:
			^1  *2  ^3  *4  ^5
			*6  ^7  *8  ^9  *10
			^11 *12 ^13 *14 ^15
			*16 ^17 *18 ^19 *20
			^21 *22 ^23 *24 ^25
			Like the black-white parts of the chess-board where ^ requires evens and * requires odds.
			Therefore, for this solution.
			Output N steps and remove all Manhattan distanced pictures, which can never be reached.
			Output as many odd steps as possible so the person can never arrive at the picture started with and the pictures diagonally right to the starting picture.
			Slowly delete these diagonally right placed pictures until the person is forced onto picture 1.
			For example:
			N = 5
			1  2  3  4  5
			6  7  8  9  10
			11 12 13 14 15
			16 17 18 19 20
			21 22 23 24 25
			output: 5 15 19 20 23 24 25
			1  2  3  4  5
			6  7  8  9  10
			11 12 13 14
			16 17 18
			21 22
			output: 7 10 14 18 22
			1  2  3  4  5
			6  7  8  9
			11 12 13
			16 17
			21
			output: 9 5 9 13 17 21
			1  2  3  4
			6  7  8
			11 12
			16
			And so on and so on until person's only left with:
			1
			*/
#include <cstdio>
int N;
int main(){
	//Instantiation
	scanf("%d", &N);
	//Manhattan distanced pictures
	printf("%d", N);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(i + j - 2 > N) printf(" %d", N*(i-1) + j);
		}
	}
	printf("\n");
	//Diagonally-right placed pictures
	int c = N;
	if(N%2) c += 2;
	else c++;
	for(int dist = 0; dist < N; dist++){
		printf("%d", c);
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if(i + j + dist - 2 == N) printf(" %d", N*(i-1) + j);
			}
		}
		printf("\n");
		c += 2;
	}
	return 0;
}