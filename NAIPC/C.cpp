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
			freopen("input.txt", "r", stdin);
			freopen("output.txt", "w", stdout);
		}
	}

	#define INF (4005)
	void solve(){
		//Enter Code here
		int n, m;
		readInt(n);
		readInt(m);
		int mat[n+5][m+5], board = -1, parity = -1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				readInt(mat[i][j]);
		int sum = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(!mat[i][j]){
					int mini = 0, maxi = INF;
					for(int k = i+1; k < n; k++)
						if(mat[k][j] && mat[k][j] < maxi){
							maxi = mat[k][j];
							break;
						}
					for(int k = j+1; k < n; k++)
						if(mat[i][k] && mat[i][k] < maxi){
							maxi = mat[i][k];
							break;
						}
					for(int k = i-1; k >= 0; k--)
						if(mat[k][j] && mat[k][j] > mini){
							mini = mat[k][j];
							break;
						}
					for(int k = j-1; k >= 0; k--)
						if(mat[i][k] && mat[i][k] > mini){
							mini = mat[i][k];
							break;
						}
					int t = mini+1, c = 0;
					if(mini == 0 && maxi == INF){
						mat[i][j] = 1;
						sum++;
						continue;
					}
					if(i-1 >= 0 && j-1 >= 0 && mat[i-1][j-1] && (mat[i-1][j-1]%2 == (t+c)%2)) c++;
					if(i-1 >= 0 && j+1 < m && mat[i-1][j+1] && (mat[i-1][j+1]%2 == (t+c)%2)) c++;
					if(j-1 >= 0 && i+1 < n && mat[i+1][j-1] && (mat[i+1][j-1]%2 == (t+c)%2)) c++;
					if(i+1 < n && j+1 < m && mat[i+1][j+1] && (mat[i+1][j+1]%2 == (t+c)%2)) c++;
					if(c > 1 || (t+c >= maxi)){
						printf("-1\n");
						return;
					}else{
						mat[i][j] = t+c;
						sum += mat[i][j];
					}
				}else
					sum += mat[i][j];
		printf("%d\n", sum);
	}
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}