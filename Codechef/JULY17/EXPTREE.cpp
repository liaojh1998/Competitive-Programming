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

long long fexp(long long b, long long p, const long long& MOD){
	b %= MOD;
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
	int T;
	long long N, N1, N2, P1, P2, b1, b2, Q1, Q2;
	readInt(T);
	//After 6 hours of experimenting:
	//Number of distinct possible N+1 ordered trees may be found by inserting an edge to each node on the rightmost branch of previous N ordered trees,
	//This results in a number sequence which is coincidentally known as the Catalan sequence (new combinatorics to learn~).
	//Number of vertices with 1 child may also be found through similar insertion which changes based on:
	//Number of vertices on the rightmost branch with number of children > 1, number of vertices on the rightmost branch with number of children = 1,
	//number of vertices not on the rightmost branch with number of children = 1.
	//These numbers are coincidentally known as a sequence closely related to the Catalan sequence, the Central Binomial Coefficients.
	//Except for where N = 1 (because there are no edges, answer = 0), answer = CBC(N-1)/Catalan(N) = (n+2)(n+1)^2/((2n+2)(2n+1)), where n = 0 when N = 2 (need at least 2 vertices for 1 edge).
	//Use Fermat's Little Theorem to find the answer mod 1000000007 and 1000000009 for the Modular Multiplicative Inverse.
	while(T--){
		readLL(N);
		if(N == 1)
			printf("0 0\n");
		else{
			N -= 2;
			N1 = N%1000000007;
			P1 = ((((N1+2)*(N1+1))%1000000007)*(N1+1))%1000000007;
			b1 = (((2*N1+2)%1000000007)*(2*N1+1))%1000000007;
			Q1 = fexp(b1, 1000000005, 1000000007);
			printf("%lld ", (P1*Q1)%1000000007);
			N2 = N%1000000009;
			P2 = ((((N2+2)*(N2+1))%1000000009)*(N2+1))%1000000009;
			b2 = (((2*N2+2)%1000000009)*(2*N2+1))%1000000009;
			Q2 = fexp(b2, 1000000007, 1000000009);
			printf("%lld\n", (P2*Q2)%1000000009);
		}
	}
}