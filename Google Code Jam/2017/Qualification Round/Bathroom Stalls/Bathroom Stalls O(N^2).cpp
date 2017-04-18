//Title: Bathroom Stalls - Small input 1
//Type: Simulation
//Complexity: O(N^2)
//Solution: This is not the actual solution, I'm simulating the process to figure out the pattern to solve this problem in O(1) time.
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

	void solve(){
		//Enter Code here
		int T;
		readInt(T);
		for(int cases = 1; cases <= T; cases++){
			//Initiate simulation beginning
			long long N, K;
			readLL(N);
			readLL(K);
			char str[N+3];
			str[N+2] = '\0';
			long long Ls[N+3], Rs[N+3];
			str[0] = str[N+1] = 'O';
			for(long long i = 1; i <= N; i++){
				str[i] = '.';
				Ls[i] = i-1;
				Rs[i] = N-i;
			}
			//Enter people till K
			long long mins, maxs, index;
			for(long long i = 1; i <= K; i++){
				mins = maxs = index = -1;
				//Search for max mins
				for(long long j = 1; j <= N; j++)
					if(str[j] != 'O' && min(Ls[j], Rs[j]) > mins){
						mins = min(Ls[j], Rs[j]);
						maxs = max(Ls[j], Rs[j]);
						index = j;
					}else if(str[j] != 'O' && min(Ls[j], Rs[j]) == mins && max(Ls[j], Rs[j]) > maxs){
						maxs = max(Ls[j], Rs[j]);
						index = j;
					}
				str[index] = 'O';
				//Renew stalls
				for(long long j = index-Ls[index]; j < index; j++)
					Rs[j] = index-j-1;
				for(long long j = index+1; j <= index+Rs[index]; j++)
					Ls[j] = j-index-1;
				printf("%s %lld %lld %lld %lld\n", str, i, index, Ls[index], Rs[index]);
			}
			printf("Case #%d: %lld %lld\n", cases, max(Ls[index], Rs[index]), min(Ls[index], Rs[index]));
		}
	}
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}