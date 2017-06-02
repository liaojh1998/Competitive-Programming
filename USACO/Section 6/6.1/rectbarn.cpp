/*
ID: liaojh11
PROG: rectbarn
LANG: C++
*/
//Title: A Rectangular Barn
//Type: DP/Computational Geometry
//Complexity: O(R*C)
//Solution: 浅谈用极大化思想解决最大子矩形问题
		//	A classic DP problem that had been solved in the Chinese IOI training in 2003.
		//	Crucial observation that the largest possible rectangle must have 4 sides touch an obstacle.
		//	So a line sweep of the columns and the amount of blocks it can extend left and right gives all possible largest rectangles.
		//	Honestly don't think this problem is a DP.
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
			freopen("rectbarn.in", "r", stdin);
			freopen("rectbarn.out", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}

void FastIO::solve(){
	//Enter code here
	int R, C, N, r, c;
	readInt(R);
	readInt(C);
	readInt(N);
	vector<int> damaged[R+5];
	for(int i = 0; i < N; i++){
		readInt(r);
		readInt(c);
		damaged[r].push_back(c);
	}
	for(int i = 1; i <= R; i++){
		damaged[i].push_back(0);
		sort(damaged[i].begin(), damaged[i].end());
		damaged[i].push_back(C+1);
	}
	//Search
	int maxarea = 0, curheight, curleft, curright, cur[R+5];
	fill_n(cur, R+5, 1);
	for(int j = 1; j <= C; j++){
		curheight = 0, curright = C+1, curleft = 0;
		for(int i = 1; i <= R; i++){
			if(damaged[i][cur[i]] != j){
				curheight++;
				if(damaged[i][cur[i]] < curright)
					curright = damaged[i][cur[i]];
				if(damaged[i][cur[i]-1]+1 > curleft)
					curleft = damaged[i][cur[i]-1]+1;
				if(curheight*(curright-curleft) > maxarea)
					maxarea = curheight*(curright-curleft);
			}else
				curheight = 0, curright = C+1, curleft = 0, cur[i]++;
		}
	}
	printf("%d\n", maxarea);
}