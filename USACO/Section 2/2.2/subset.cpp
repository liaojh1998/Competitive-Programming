/*
ID: liaojh11
PROG: subset
LANG: C++
*/
//Title: subset
//Type: DP
//Solution: Knapsack Algorithm. O(N^3)
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fin("subset.in");
ofstream fout("subset.out");
int N;
int main()
{   
	//Instantiation
	fin >> N;
	double ways[sum];
	for(int i = 0; i < sum; i++){
		ways[i] = 0;
	}

	int sum = (N+1)*N/2; //Sum for evens = number of pairings/2 * (first + last) (or 1 + N), sum for odds = number of pairings/2 * last.
					 //However, this can be simplified to just (N+1)*N/4. We know number of pairs is always for evens N/2, for odds (N+1)/2.
					 //And they both divide by 2, thus, evens N/4, odds (N+1)/4. Now because evens * (1+N) and odds * N.
					 //Both result end up being (N+1)*N/4.
					 //Here at knapsack we're trying to find amount of different sets to find a sum. We do not need to divide number of pairs by 2.

	//Notice that any sum/2 that is odd means there's no chance at a subset sum.
	if(sum%4){
		fout << 0 << endl;
		return 0;
	}

	//Knapsack Algorithm
	ways[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = sum - i; j >= 0; --j) { //sum is n*(n+1)/2
    		ways[j + i] += ways[j];
		}
	}
	fout << setprecision(10); //Why you no fit in an integer, fam?
	fout << ways[sum/2]/2 << endl; //Can someone tell me why is this true?!
	return 0;
}

//Look up DP Knapsack Algorithm for Practice!