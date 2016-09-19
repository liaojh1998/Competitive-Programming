/*
ID: liaojh11
PROG: hamming
LANG: C++
*/
//Title: hamming
//Type: Brute Force
//Solution:	Finding the exact N position bit of a number M would be "int bit = (1 << N) & M". We know smallest number must
//		contain 0, so start from 0 and while loop or DFS loop till enough solution.
#include <fstream>
using namespace std;
ifstream fin("hamming.in");
ofstream fout("hamming.out");
int N, B, D, count;
//Check
bool check(int n, int s[]){
	//Check everything in solution array
	for(int i = 0; i < count; i++){
		//hamming distance
		int ham = 0;
		for(int j = 0; j < B; j++){
			int bit1 = (1 << j) & n;
			int bit2 = (1 << j) & s[i];
			//If bits at same position are different, ham++;
			if(bit1 != bit2)
				ham++;
		}
		//Less than required? Not a solution
		if(ham < D){
			return false;
		}
	}
	return true;
}
int main()
{   
	//Constructor and instantiation
	fin >> N;
	fin >> B;
	fin >> D;
	int sol[N];
	for(int i = 0; i < N; i++){
		sol[i] = 0;
	}

	//num is the number, checking every number, while loop till found needed amount of numbers
	//use count as the index in the solution (since 0 is a solution, start from count = 1)
	count = 1;
	int num = 1;
	while(sol[N-1] == 0){
		if(check(num, sol)){
			sol[count] = num;
			num++;
			count++;
		}else{
			num++;
		}
	}

	//Awkwardest kind of fout you'll ever witness, I'm so sorry
	int c = 1;
	for(int i = 0; i < N; i++){
		fout << sol[i];
		if(c == 10){
			fout << "\n";
			c = 1;
		}else if(i == N-1){
			fout << "\n";
		}else{
			fout << " ";
			c++;
		}
	}
	return 0;
}