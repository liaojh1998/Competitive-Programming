//Title: Bathroom Stalls - Small input 1
//Type: Simulation
//Complexity: O(log^2(N))
//Solution: The process is a small improvement from previous, now recognizing that the actual outcome of each repetition is same, we can limit the priority queue search as well as get a count of how many of these segments we can have. The answer is when segment number summed up is bigger than K.
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
			long long N, K;
			readLL(N);
			readLL(K);
			//Added maps
			map<long long, long long> segCount;
			map<long long, bool> addedSeg;
			priority_queue<long long, vector<long long>, less<long long> > q;
			q.push(N);
			segCount[N] = 1;
			long long temp;
			for(long long i = 0; i < K; i += segCount[temp]){
				temp = q.top(); q.pop();
				if(!addedSeg[temp/2]){
					addedSeg[temp/2] = true;
					q.push(temp/2);
					segCount[temp/2] = segCount[temp];
				}else
					segCount[temp/2] += segCount[temp];
				if(!addedSeg[(temp-1)/2]){
					addedSeg[(temp-1)/2] = true;
					q.push((temp-1)/2);
					segCount[(temp-1)/2] = segCount[temp];
				}else
					segCount[(temp-1)/2] += segCount[temp];
			}
			printf("Case #%d: %lld %lld\n", cases, temp/2, (temp-1)/2);
		}
	}
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}