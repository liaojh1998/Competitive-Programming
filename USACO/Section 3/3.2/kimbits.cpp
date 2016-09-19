/*
ID: liaojh11
PROG: kimbits
LANG: C++
*/
//Title: kimbits
//Type: DP
//Solution: Time complexity O(N*L + N)
		/*  We'll keep a DP[N][L] of amount of strings that has maximum of L 1s and is within the size of N bits.
			For example: DP[0][0] 1 string that has size of 0 bits with 0 ones.
			DP[1][0] 1 string that has size of 1 byte with 0 ones.
			DP[1][1] 2 string that has size of 1 byte with 1 or less ones (0) (1).
			DP[2][0] 1 string that has size of 2 bits with 0 ones (00).
			DP[2][1] 3 strings that has size of 2 bits with 1 or less ones (00) (01) (10).
			DP[2][2] 4 strings that has size of 2 bits with 1 or less ones (00) (01) (10) (11).
			Notice this pattern then:
				L   0   1   2   3   4   5
			N
			0       1   1
			1       1   2
			2       1   3   4
			3       1   4   7   8
			4       1   5   11  15  16
			5       1   6   16  26  31  32
			Notice the recurring pattern that DP[i][j] = DP[i-1][j-1] + DP[i-1][j], except for DP[0][0] & where i == j.
			Logically, the pattern states that you'll build N bit strings with at least L ones repeatedly from N-1 bit strings which is build from previous N-1 bit strings.
			For example: 3 bit strings with at least 2 ones require 2 bit strings using at least 1 ones and 2 bit strings using at least 2 ones
			--> (01) (10) (00) (11).
			Logically stating that you'll use the N-1 strings using at least L bits twice (2 bit strings using at least 1 ones), and one extra new pattern (the 11, 2 bit 2 ones).
			For where i == j however, since it marks the new pattern that has not appeared, we simply add one from j - 1.
			For example: 3 bit strings with at least 3 ones will have this 111 pattern that has not appeared before.

			Then we'll take I. If I > DP[N-1][L] then we know that it used a 1 bit at N because DP[N-1][L] represents the maximum amount of strings possible using
			N-1 bit strings with at least L ones.
			Since I is the count of amount of strings counted, if > DP[N-1][L], then at N there must be a 1.
			If <= DP[N-1][L], then it definitely hasn't use a 1 at N because DP[N][L] - DP[N-1][L] is the range for where 1 is used.
			By subtracting I with DP[N-1][L] where I > DP[N-1][L] and print 1, or not do anything with I where I <= DP[N-1][L] and print 0, we'll end up with
			the correct bit string.
			*/
#include <fstream>
using namespace std;
ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
int N, L;
long long I;
int main(){
	//Instantiation
	fin >> N >> L >> I;
	//DP
	long long dp[N][L+1];
	for(int i = 0; i < N; i++){
		dp[i][0] = 1;
		for(int j = 1; j <= L; j++){
			if(i == j) dp[i][j] = dp[i][j - 1] + 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	int i = N - 1;
	//Build answer from DP and print results
	while(L > 0 || i >= 0){
		if(L > i) L = i;
		if(I > dp[i][L]){
			fout << 1;
			I -= dp[i][L];
			L--;
		}else fout << 0;
		i--;
	}
	fout << endl;
	return 0;
}