#include <bits/stdc++.h>
using namespace std;

void getlist(vector<long long>& sheldons){
	vector<long long> dp[64][64][2];
	for(int i = 1; i <= 63; i++){
		//ABABAB...AB
		for(int j = i; j >= 1; j--){
			if(!(i%j)){
				long long s = 0, str;
				int times = i/j;
				for(int k = j-1; k >= 1; k--){
					s |= ((long long)1)<<k;
					str = 0;
					for(int l = 0; l < times; l++){
						str = (str<<j)|s;
					}
					dp[i][j-k][0].push_back(str);
				}
			}
		}
		//ABABAB...ABA
		long long s = 0;
		for(int j = 1; j < i && j < i-j; j++){
			s |= ((long long)1)<<(j-1);
			int size = dp[i-j][j][0].size();
			for(int k = 0; k < size; k++)
				dp[i][j][1].push_back((dp[i-j][j][0][k]<<j)|s);
		}
		dp[i][i][1].push_back((((long long)1)<<i)-1);
	}
	for(int i = 1; i <= 63; i++){
		for(int j = 1; j <= i; j++){
			int ksize = dp[i][j][0].size(), lsize = dp[i][j][1].size(), l = 0;
			for(int k = 0; k < ksize; k++){
				while(l < lsize && dp[i][j][0][k] > dp[i][j][1][l])
					sheldons.push_back(dp[i][j][1][l++]);
				sheldons.push_back(dp[i][j][0][k]);
			}
			while(l < lsize)
				sheldons.push_back(dp[i][j][1][l++]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("output.txt", "w", stdout);
	vector<long long> sheldons;
	getlist(sheldons);
	/*for(int i = 0; i < sheldons.size(); i++)
		printf("%lld\n", sheldons[i]);*/
	long long a, b;
	cin >> a >> b;
	cout << upper_bound(sheldons.begin(), sheldons.end(), b)-lower_bound(sheldons.begin(), sheldons.end(), a) << endl;
	/*int total = 0, dp[65][65];
	memset(dp, 0, sizeof(dp));
	//ABABAB...AB
	for(int i = 1; i <= 64; i++){
		for(int j = 1; j <= i; j++){
			if(!(i%j)){
				for(int k = 1; k < j; k++){
					total++;
					dp[k][i]++;
				}
			}
		}
	}
	//ABABAB...ABA
	for(int i = 1; i <= 64; i++)
		for(int j = 1; j < i && j < i-j; j++)
			total += dp[j][i-j];
	//Full representation with 1s and no 0s
	total += 64;
	int N, num1, len;
	cin >> N;
	while(N){
		if(N == 2){
			cin >> num1 >> len;
			printf("%d\n", dp[num1][len]);
		}else{
			printf("%d\n", total);
		}
		cin >> N;
	}*/
	return 0;
}