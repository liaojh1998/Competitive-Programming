/*
ID: liaojh11
PROG: stamps
LANG: C++
*/
//Title: stamps
//Type: DP
//Solution: Determine the minimum amount of stamps required to reach a postage.
		/*  1. Setting amount of stamps required to reach postage to infinity. Maximum postage is the biggest stamp * stamps allowed.
			2. Starting with dp[0] = 0, since 0 postage requires no stamp at all.
			3. for(all stamps)
			4. 	if(stamps required for this postage > stamps required for (postage - stamp cost) + 1) then
					change this postage to stamp required for (postage - stamp cost) + 1.
			5. Find the postage that first requires more than allowed stamps, the postage before is the answer.
			*/
#include <fstream>
#define INF 999999 //Random infinity lolz
using namespace std;
ifstream fin("stamps.in");
ofstream fout("stamps.out");
int K, N;
int main(){
	//Instantiation
	fin >> K >> N;
	int stamps[N], big = 0;
	for(int i = 0; i < N; i++){
		fin >> stamps[i];
		if(stamps[i] > big) big = stamps[i];
	}
	//DP instantiation
	int biggest = K * big;
	int dp[biggest + 1] = {0};
	for(int i = 1; i <= biggest; i++){
		dp[i] = INF;
	}
	//DP
	for(int i = 0; i < N; i++){
		for(int j = stamps[i]; j <= biggest; j++){
			if(dp[j - stamps[i]] + 1 < dp[j])
				dp[j] = dp[j - stamps[i]] + 1;
		}
	}
	//Print results, since i breaks at impossible number, possible number is i - 1.
	int i;
	for(i = 0; i <= biggest; i++){
		if(dp[i] > K) break;
	}
	fout << i - 1 << endl;
	return 0;
}