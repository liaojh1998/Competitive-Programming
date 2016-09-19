/*
ID: liaojh11
PROG: fact4
LANG: C++
*/
//Title: fact4
//Type: DP
//Solution: Dear lord please make all USACO problems as easy as this. (DAMN, IT TRICKED ME. THIS WAS ACTUALLY A BIT HARDER THAN I THOUGHT.)
#include <fstream>
using namespace std;
ifstream fin("fact4.in");
ofstream fout("fact4.out");
int main(){
	//Instantiation
	int N;
	fin >> N;
	//DP
	int holycow = 1, omg = 0; //holycow is the rightmost number, omg is the amount of 2s we will need to multiply.
	for(int i = 2; i <= N; i++){
		int whoa = i; //In cases of 15 or 45 or any number like those, we'll keep dividing and multiply them back later.
		while(!(whoa % 2)){
			omg++;
			whoa /= 2;
		}
		while(!(whoa % 5)){
			omg--;
			whoa /= 5;
		}
		holycow = (holycow * whoa) % 10; //Since all 5s and 2s are gone we can say the number must be 1-9.
	}
	while(omg != 0){
		holycow = holycow * 2 % 10; //Ayy Lmao, I'm tilted. Wait, what's tilted?1?!
		omg--; //Less omg! More holycows!
	}
	fout << holycow << endl; //Ayy look at them cows
	return 0;
}

//Greedy Solution
/*
int main(){
	//Instantiation
	int N;
	fin >> N;
	//DP
	int facts[N+1];
	facts[0] = 1;
	for(int i = 1; i <= N; i++){
		int lol = facts[i - 1] * i;
		while(!(lol % 10)) lol /= 10;
		facts[i] = lol % 1000; //Can't just mod 10 lmao, otherwise if (15 * 2 = 30) != (5 * 2 = 10). Mod at least 1000 for passing all tests.
	}
	fout << facts[N]%10 << endl;
	return 0;
}
*/