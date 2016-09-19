/*
ID: liaojh11
PROG: money
LANG: C++
*/
//Title: money
//Type: DP
//Solution: Probably the easiest DP to encounter. Time complexity of O(VN), Knapsack Algorithm. Imagine brute force search time complexity of O(V^V) and compare.
		/*  Let's use an example to demonstrate this:
			Say we have 3 different kind of coins: 1, 2, 5.
			We want to find how many different ways you can generate sum 10.
			Let's first set that to generate an exact sum of 1, 2, or 5, we need at least one coin. Store this in dp[0].
			First consider only using 1s.
			To generate sum 1, we need 1 coin of 1. dp[1]+= dp[1 - 1] which is 1;
			To generate sum 2, we need 2 coins of 1. dp[2]+= dp[2 - 1] which is also 1;
			To generate sum 3, we need 3 coins of 1. dp[3]+= dp[3 - 1] which is also 1;
			And so on and so on.
			There is only 1 way to generate only using 1s, so all dp[] should be filled with 1.

			Now consider using both 1s and 2s.
			We know we can't generate sum lower than 2 when using 2s, so start from when we can use 2, which is exact sum of 2.
			To generate sum 2, we need 1 coin of 2. dp[2]+= dp[2 - 2] which is 1, now dp[2] = 2;
			To generate sum 3, we need 1 coin of 2 and different ways to generate sum 1. dp[3]+= dp[3 - 2] which is 1, now dp[3] = 2;
			To generate sum 4, we need 1 coin of 2 and different ways to generate sum 2 (using both 1s and 2s). dp[4]+= dp[4 - 2] which is 2, now dp[4] = 3;
			To generate sum 5, we need 1 coin of 2 and different ways to generate sum 3 (using both 1s and 2s). dp[5]+= dp[5 - 2] which is 2, now dp[5] = 3;
			To generate sum 6, we need 1 coin of 2 and different ways to generate sum 4 (using both 1s and 2s). dp[6]+= dp[6 - 2] which is 3, now dp[6] = 4;
			And so on and so on.

			Now consider using 1s and 2s and 5s.
			We know we can't generate sum lower than 5 when using 5s, so start from when we can use 5, which is exact sum of 5.
			To generate sum 5, we need 1 coin of 5. dp[5]+= dp[5 - 5] which is 1, now dp[5] = 4;
			To generate sum 6, we need 1 coin of 5 and different ways to generate sum 1. dp[6]+= dp[6 - 5] which is 1, now dp[6] = 5;
			To generate sum 7, we need 1 coin of 5 and different ways to generate sum 2 (using both 1s and 2s). dp[7]+= dp[7 - 5] which is 2, now dp[7] = 6;
			And so on and so on.

			Thus, to generate sum 10, we combine:
			using 1 coin of 1 and different ways to generate sum 9 (using 1s).
			using 1 coin of 2 and different ways to generate sum 8 (using 1s, 2s).
			using 1 coin of 5 and different ways to generate sum 5 (using 1s, 2s, and 5s).
			dp[10] using coin of 1 has only 1 way.
			dp[10] using coin of 1 and 2 has 5 distinct ways.
			dp[10] using coin of 1 and 2 and 5 has 4 distinct ways.
			1 + 5 + 4 = 10, dp[10] = 10;
			dp[N] = dp[10] = answer.

			Basically, this DP combines different ways to generate a sum with different coin values to find new ways to generate an exact sum. */
#include <fstream>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
//ofstream debug("money.txt"); //See for yourself
int coins, N;
int main(){
	fin >> coins >> N;
	int coin[coins];
	long long dp[N + 1];
	for(int i = 0; i < coins; i++){
		fin >> coin[i];
	}
	for(int i = 0; i < N + 1; i++){
		dp[i] = 0;
	}
	//DP
	dp[0] = 1;
	for(int i = 0; i < coins; i++){
		for(int j = coin[i]; j <= N; j++){
			dp[j]+= dp[j - coin[i]];
		}
	}
	//Debug
	/*
	debug << "Using coin values of ";
	for(int i = 0; i < coins; i++){
		if(i == coins - 1){
			debug << "and " << coin[i] << "." << endl;
			break;
		}
		debug << coin[i] << ", ";
	}
	for(int i = 1; i <= N; i++){
		debug << "There are " << dp[i] << " ways to generate a sum of " << i << "." << endl;
	}
	*/
	fout << dp[N] << endl;
	return 0;
}