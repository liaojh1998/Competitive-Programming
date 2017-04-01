#include <bits/stdc++.h>
using namespace std;

int gdiv[1000005];
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

	int gcd(int a, int b){
		return b ? gcd(b, a%b) : a;
	}
	bool partitionable(int index, int n, int k, int* seq, const vector<int>& primes){
		int minPartition = 0;
		for(int i = 0; i < n; minPartition++){
			if(minPartition >= k) return false;
			int cur = seq[i];
			if(gdiv[cur] < primes[index]) return false; //Lower primes required
			for(i++; i < n && gdiv[(cur = gcd(cur, seq[i]))] >= primes[index]; i++);
		}
		return true;
	}
	void solve(){
		//Enter Code here
		vector<int> primes;
		for(int i = 2; i <= 1000000; i++)
			if(!gdiv[i]){
				primes.push_back(i);
				for(int j = i; j <= 1000000; j+=i)
					gdiv[j] = i;
			}
		int n, k;
		readInt(n);
		readInt(k);
		int seq[n+5];
		for(int i = 0; i < n; i++)
			readInt(seq[i]);
		if(!partitionable(0, n, k, seq, primes)){ //When no primes work
			printf("0\n");
			return;
		}
		//Binary Search for a minimum prime
		int lo = 0, hi = primes.size()-1;
		while(lo < hi){
			int mid = (lo + hi)/2;
			if(partitionable(mid, n, k, seq, primes))
				lo = mid+1;
			else
				hi = mid;
		}
		while(lo < primes.size() && partitionable(lo, n, k, seq, primes)) lo++;
		printf("%d\n", primes[lo-1]);
	}
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}