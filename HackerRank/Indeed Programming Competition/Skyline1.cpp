#include <bits/stdc++.h>
using namespace std;

template<typename T> class SegTree{
private:
	T* sgt;
	size_t N, height;
	#define defval (0)
	T applyfunc(const T& a, const T& b){
		return a > b ? a : b;
	}
	T queryfunc(const T& a, const T& b){
		return a > b ? a : b;
	}

public:
	SegTree(size_t n){
		N = n;
		height = (size_t)ceil(log2(N));
		sgt = new T[1<<(height+1)];
		fill_n(sgt, 1<<(height+1), defval);
	}
	~SegTree(){
		delete[] sgt;
	}
	T& operator[](const size_t& i){
		return sgt[i + (1<<height)];
	}
	void build(){
		for(size_t i = ((1<<height)-1); i > 0; i--)
			sgt[i] = queryfunc(sgt[i<<1], sgt[i<<1|1]);
	}
	void update(size_t pos, const T& value){
		if(pos < 0 || pos >= N) return; //Not possible
		for(sgt[(pos + (1<<height))] = applyfunc(sgt[(pos += (1<<height))], value); pos > 1; pos >>= 1)
			sgt[pos>>1] = queryfunc(sgt[pos], sgt[pos^1]);
	}
	T query(size_t l, size_t r){
		if(!((l+1)^r)) return (*this)[l];
		T resl = 0, resr = 0; //Set initial values
		for(l += (1<<height), r += (1<<height); l < r; l >>= 1, r >>= 1){
			if(l&1) resl = queryfunc(resl, sgt[l++]);
			if(r&1) resr = queryfunc(sgt[--r], resr);
		}
		return queryfunc(resl, resr);
	}
};

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
		for(; c != '.' && ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
		if(c == '-') neg = true, c = getchar();
		for(; c != '.' && c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
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

void FastIO::solve(){
	int N;
	readInt(N);
	long long prefix[N+1], length[N+1], W, H;
	prefix[0] = 0;
	length[0] = 0;
	SegTree<long long> sgt(N+5);
	for(int i = 1; i <= N; i++){
		readLL(W);
		readLL(H);
		length[i] = length[i-1]+W;
		prefix[i] = prefix[i-1]+W*H;
		sgt[i-1] = H;
	}
	sgt.build();
	int M;
	readInt(M);
	int u, v;
	while(M--){
		readInt(u);
		readInt(v);
		long long area = prefix[v+1]-prefix[u];
		long long l = length[v+1]-length[u];
		long long maxheight = sgt.query(u, v+1);
		double percent = (double)area/(maxheight*l);
		printf("%.6lf\n", percent);
	}
}