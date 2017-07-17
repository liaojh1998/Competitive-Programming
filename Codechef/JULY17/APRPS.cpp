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

	void solve();
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

#define MOD (1000000007)

long long fexp(long long b, long long p){
	long long ans = 1;
	while(p){
		if(p & 1)
			ans = (ans * b)%MOD;
		b = (b * b)%MOD;
		p >>= 1;
	}
	return ans;
}

void FastIO::solve(){
	//https://en.wikipedia.org/wiki/Pascal%27s_triangle
	//P(n, k) = P(n, k-1) * (n-k+1) / k
	//http://www.mathpages.com/home/kmath111/kmath111.htm //(60 points only...?)
	int T, N, len, newlen;
	long long *c = new long long[1<<15+5];
	long long *exptab = new long long[1<<13+5];
	long long *unroot = new long long[1<<14+5], *root = new long long[1<<14+5];
	long long pascal, temp;
	long long *inv = new long long[1<<14+5];
	for(int i = 1; i <= (1<<14); i++)
		inv[i] = fexp(i, MOD-2);
	readInt(T);
	while(T--){
		readInt(N);
		long long a[N+1];
		for(int i = 1; i <= N; i++)
			readLL(a[i]);
		memset(c, 0, sizeof(long long)*(1<<15+5));
		c[0] = MOD-a[1];
		c[1] = 1;
		for(int k = 2; k <= N; k++){
			memset(unroot, 0, sizeof(long long)*(1<<(k-1)+5));
			memset(root, 0, sizeof(long long)*(1<<(k-1)+5));
			len = 1 << (k - 2);
			//Exponent table
			exptab[0] = 1;
			for(int i = 1; i <= len; i++)
				exptab[i] = (exptab[i-1]*a[k])%MOD;
			//Partition into rooted and unrooted terms
			for(int i = 0; i <= len; i++){
				newlen = i << 1;
				pascal = 1;
				for(int j = 0; j < i; j++){
					if(j%2){
						root[j>>1] = ((((exptab[(newlen-j)>>1]*pascal)%MOD)*c[i])%MOD + root[j>>1])%MOD;
						root[(newlen-j)>>1] = ((((exptab[j>>1]*pascal)%MOD)*c[i])%MOD + root[(newlen-j)>>1])%MOD;
					}else{
						unroot[j>>1] = ((((exptab[(newlen-j)>>1]*pascal)%MOD)*c[i])%MOD + unroot[j>>1])%MOD;
						unroot[(newlen-j)>>1] = ((((exptab[j>>1]*pascal)%MOD)*c[i])%MOD + unroot[(newlen-j)>>1])%MOD;
					}
					pascal = (((pascal*(newlen-j))%MOD)*inv[j+1])%MOD;
				}
				if(i%2)
					root[i>>1] = ((((exptab[i>>1]*pascal)%MOD)*c[i])%MOD + root[i>>1])%MOD;
				else
					unroot[i>>1] = ((((exptab[i>>1]*pascal)%MOD)*c[i])%MOD + unroot[i>>1])%MOD;
			}
			memset(c, 0, sizeof(long long)*(1<<k+5));
			//Even if I did use FFT here, the above partition forces a (2^(N-2))^2 runtime...
			//Unrooted terms polynomial multiplication
			for(int i = 0; i <= len; i++)
				for(int j = 0; j <= len; j++)
					c[i+j] = ((unroot[i]*unroot[j])%MOD + c[i+j])%MOD;
			//Rooted terms polynomial multiplication
			for(int i = 0; i < len; i++)
				for(int j = 0; j < len; j++)
					c[i+j+1] = (c[i+j+1] + (((((root[i]*root[j])/MOD)*MOD+MOD-root[i]*root[j])%MOD)*a[k])%MOD)%MOD;
		}
		len = 1 << (N - 1);
		printf("%d\n", len<<1);
		for(int i = 0; i <= len; i++)
			printf("%lld%s", c[i], i == len ? "\n" : " 0 ");
	}
	delete[] c;
	delete[] exptab;
	delete[] inv;
	delete[] unroot;
	delete[] root;
}