/*
ID: liaojh11
PROG: nocows
LANG: C++
*/
//Title: nocows
//Type: DP
//Solution: If only I can visualize this properly in a text document, notice this solution used symmetry and is a reduced tree.
		/*  The solution basically takes a start on dp[1][1] tree, which has 1 node and 1 level, which will create 1 solution but it's reduced, so deleted.
			The it moves on from these reduced trees, such as a 3,2 tree will create a reduced 1,1 tree.
			5,3 will create 2 of these 3,2 trees which creates a 1,1 tree.
			7,3 will create a 3,2 tree which creates a 1,1 tree based on symmetry.
			This smart solution takes symmetry as the recurrence relation, and use it to find the complete answer.\

			Funny enough, the symmetry even goes in the mistakes.
			Consider 7,4, which makes 4 5,3 trees but doesn't make a 3,3 tree, but it's calculated.
			And the solution knows that the dp above it, 7,3, has the same amount as 3,3, so it subtracts it off.
			This coincidental symmetry flows throughout the whole dp table.
			*/
#include <fstream>
using namespace std;
ifstream fin("nocows.in");
ofstream fout("nocows.out");
//ofstream debug("nocows.txt"); //See for yourself
int dp[201][101], N, K;
int main(){
    fin >> N >> K;

    //Setting prerequisite
    for(int j = 0; j <= K; j++)
    	dp[1][j] = 1;
    //DP
    for(int j = 2; j <= K; j++){
    	for(int i = 2; i <= N; i++){
    		for(int m = 1; m <= i - 1; m++)
    			dp[i][j] = (dp[i][j] + dp[m][j - 1] * dp[i - 1 - m][j - 1]) % 9901;
    	}
    }

    /*debug
    for(int j = 0; j <= K; j++){
		for(int i = 0; i <= N; i++){
			debug << "[" << dp[i][j] << "]";
		}
		debug << endl;
    }
    */

	fout << (dp[N][K] - dp[N][K - 1] + 9901) % 9901 << endl;
	return 0;
}

// http://massivealgorithms.blogspot.com/2015/08/cow-pedigrees-usaco-232.html/
// http://zeffsalgo.blogspot.com/2013/12/usaco-training-problem-cow-pedigrees.html/
// I have to admit this is the hardest DP I've ever done. Absolutely no recurrence for me.