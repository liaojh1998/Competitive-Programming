/*
ID: liaojh11
PROG: vans
LANG: C++
*/
//Title: Postal Vans
//Type: DP
//Complexity: O(N)
//Solution: There are many ways to solve this problem. Wolframalpha can derive a recurrence relation for it, but finding the recurrence relation is a skill made through practice.
		//	Sadly, I don't have that skill, so I had to consult the internet for this type of question.
		//	Crucial observation for the problem is that the hamitonian path must return from a 2nd horizontal street or the 4th horizontal street.
		//	Let dp[i] represent having i vertical streets, the number of hamitonian paths that travels from the northwest corner to the node beneath it.
		//	This path require 1 more street to complete the cycle, thus, dp[i] is the answer with i vertical streets.
		//	When adding a new vertical street on the left, we can prolong the corner and 2nd node to cover the new vertical street with 2 extra nodes beneath that will conveniently be covered by the hamitonian path as well:
		//	._ _ _ _        .<_._ _ _ _
		//	._|_|_|_|       .<_._|_|_|_|
		//	|_|_|_|_|  -->  | _|_|_|_|_|
		//	|_|_|_|_|       | _|_|_|_|_|
		//
		//	Let g[i] represent having i vertical streets, the number of hamitonian paths that travels from the northwest corner to the southwest corner.
		//	This is useful because adding 1 vertical street on the west side gives new path for dp[i+1].
		//	This gives the recurrence relation: dp[i] = dp[i-1] + g[i-1];
		//	To derive g[i], 4 different cases arise that allows g[i] to be related to dp[i-1], g[i-1], g[i-2], and g[i-3]: http://blog.csdn.net/jiangshibiao/article/details/21446033
#include <bits/stdc++.h>
using namespace std;

class FastIO{
//#define getchar() (getchar_unlocked()) //For hackerrank
private:
	//inline if read speed is needed, huge compilation time required though
	//safe no fread implementation
	int readInt(int &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
		if(neg) n = -n;
		return 1;
	}
	int readLL(long long &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
		if(neg) n = -n;
		return 1;
	}
	int readDouble(double &n){
		register int c;
		n = 0;
		bool neg = false;
		c = getchar();
		if(!(~c)) return -1;
		for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
		}
		double div = 1;
		for(c = getchar(); c > 47 && c < 58 && ~c; c = getchar()){div *= 10, n = n*10+c-48;}
		n /= div;
		if(neg) n = -n;
		return 1;
	}
	int readStr(char *str){
		register char c = getchar();
		register int len = 0;
		if(!(~c)) return -1;
		while(c < 33 && ~c) c = getchar(); //32 if space should be included
		//32 if stop at space, 10 if stop at next line
		while(c != 10 && c != 32 && ~c){
			str[len] = c;
			c = getchar();
			len++;
		}
		str[len] = '\0';
		//Just in case if needs to return arriving at end of line
		//if(c == 10) return 10;
		return 1;
	}
	int readStr(char *str, int len){
		//Reading string of size len
		for(int i = 0; i < len; i++){
			str[i] = getchar();
			if(!(~str[i])){
				str[i] = '\0';
				return -1;
			}
			//Remove this if str can't go to next line
			/*if(str[i] == 10){
				str[i] = '\0';
				return 10;
			}*/
		}
		str[len] = '\0';
		return 1;
	}

public:
	//Constructor, true if using file input/output, defaulted false
	FastIO(bool useFile = false){
		if(useFile){
			freopen("vans.in", "r", stdin);
			freopen("vans.out", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}

class bigNum{
private:
	#define BASE (1000000000)
	#define MAXNUM (50)
	int num[MAXNUM], len;
public:
	bigNum(){
		memset(num, 0, sizeof(num));
		len = 0;
	}
	bigNum operator=(int n){
		memset(num, 0, sizeof(num));
		num[0] = n;
		len = 1;
	}
	bigNum operator=(const bigNum& n){
		memcpy(num, n.num, sizeof(n.num));
		len = n.len;
	}
	bigNum operator+(const bigNum& n){
		bigNum temp;
		temp.len = max(len, n.len);
		for(int i = 0; i < temp.len; i++){
			temp.num[i] += num[i]+n.num[i];
			temp.num[i+1] += temp.num[i]/BASE;
			temp.num[i] %= BASE;
		}
		temp.len = MAXNUM;
		while(!temp.num[temp.len-1]) temp.len--;
		return temp;
	}
	bigNum operator-(const bigNum& n){
		bigNum temp;
		temp.len = max(len, n.len);
		for(int i = 0; i < temp.len; i++){
			temp.num[i] += num[i]-n.num[i];
			while(temp.num[i] < 0){
				temp.num[i] += BASE;
				temp.num[i+1]--;
			}
		}
		temp.len = MAXNUM;
		while(!temp.num[temp.len-1]) temp.len--;
		return temp;
	}
	bigNum two(){
		bigNum temp;
		temp.len = len;
		for(int i = 0; i < temp.len; i++){
			temp.num[i] += num[i]*2;
			temp.num[i+1] += temp.num[i]/BASE;
			temp.num[i] %= BASE;
		}
		temp.len = MAXNUM;
		while(!temp.num[temp.len-1]) temp.len--;
		return temp;
	}
	void print(){
		if(!len)
			printf("0\n");
		else{
			printf("%d", num[len-1]);
			for(int i = len-2; i >= 0; i--){
				int k = BASE/10;
				while(k > num[i]){
					k /= 10;
					printf("0");
				}
				if(num[i])
					printf("%d", num[i]);
			}
			printf("\n");
		}
	}
};

void FastIO::solve(){
	int N;
	readInt(N);
	bigNum dp[N+5], g[N+5];
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 2;
	dp[3] = 4;
	g[0] = 0;
	g[1] = 2;
	g[2] = 2;
	g[3] = 8;
	for(int i = 4; i <= N; i++){
		dp[i] = (dp[i-1] + g[i-1]);
		g[i] = (dp[i-1].two() + g[i-1] + g[i-2] - g[i-3]);
	}
	dp[N].print();
}