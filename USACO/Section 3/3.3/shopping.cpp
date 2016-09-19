/*
ID: liaojh11
PROG: shopping
LANG: C++
*/
//Title: shopping
//Type: DP (Multiple Knapsack)
//Solution: The legendary 5 knapsack DP. The knapsack is easy, but storing information is quite annoying since offers came before the product appearances.
		/*	So store the offers first before we actually put them in the offer array. Then simply DP all 5 knapsack since each needs less than 5 products. */
#include <fstream>
#include <cstring>
using namespace std;
const int INF = 9999*5 + 1;
ifstream fin("shopping.in");
ofstream fout("shopping.out");
typedef struct{
	int amount, prod_num[5], prod_amount[5];
}data;
data d[99];
int s, b, product_num[1000], price[105], offers[105][5], need[5] = {0}, dp[6][6][6][6][6];
int main(){
	//Instantiation
	fin >> s;
	for(int i = 0; i < s; i++){
		fin >> d[i].amount;
		for(int j = 0; j < d[i].amount; j++){
			fin >> d[i].prod_num[j] >> d[i].prod_amount[j];
		}
		fin >> price[i];
	}
	memset(product_num, -1, sizeof(product_num));
	fin >> b;
	for(int i = 0; i < b; i++){
		int p;
		fin >> p;
		product_num[p] = i;
		fin >> need[i] >> price[s+i];
		offers[s+i][i] = 1;
	}
	for(int i = 0; i < s; i++){
		for(int j = 0; j < d[i].amount; j++){
			if(product_num[d[i].prod_num[j]] == -1)
				price[i] = INF;
			else
				offers[i][product_num[d[i].prod_num[j]]] = d[i].prod_amount[j];
		}
	}
	//DP
	s += b;
	memset(dp, INF, sizeof(dp));
	dp[0][0][0][0][0] = 0;
	for(int i = 0; i <= need[4]; i++)
		for(int j = 0; j <= need[3]; j++)
			for(int k = 0; k <= need[2]; k++)
				for(int l = 0; l <= need[1]; l++)
					for(int m = 0; m <= need[0]; m++){
						for(int n = 0; n < s; n++){
							int p1 = m - offers[n][0];
							int p2 = l - offers[n][1];
							int p3 = k - offers[n][2];
							int p4 = j - offers[n][3];
							int p5 = i - offers[n][4];
							if(p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0 || p5 < 0) continue;
							if(dp[m][l][k][j][i] > dp[p1][p2][p3][p4][p5] + price[n])
								dp[m][l][k][j][i] = dp[p1][p2][p3][p4][p5] + price[n];
						}
					}
	fout << dp[need[0]][need[1]][need[2]][need[3]][need[4]] << endl;
	return 0;
}