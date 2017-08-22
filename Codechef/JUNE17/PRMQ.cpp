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

#define LIMIT (1000)
int s[LIMIT + 1];
void sieve(vector<int>& primes){
	//Add primes 2, 3
	primes.push_back(2);
	primes.push_back(3);
	//The Sieve of Atkin
	for(int x = 1; x*x <= LIMIT; x++)
		for(int y = 1; y*y <= LIMIT; y++){
			int n = 4*x*x+y*y;
			if(n <= LIMIT && (n%12 == 1 || n%12 == 5))
				s[n] = ~s[n];
			n = 3*x*x+y*y;
			if(n <= LIMIT && n%12 == 7)
				s[n] = ~s[n];
			n = 3*x*x-y*y;
			if(x > y && n <= LIMIT && n%12 == 11)
				s[n] = ~s[n];
		}
	for(int i = 5; i*i <= LIMIT; i++)
		if(s[i]){
			primes.push_back(i);
			int j = 1;
			int k = j++*i*i;
			while(k <= LIMIT){
				s[k] = 0;
				k = j++*i*i;
			}
		}
	for(int i = sqrt(LIMIT); i <= LIMIT; i++)
		if(s[i])
			primes.push_back(i);
}

template<typename T> class FenTree2D{
private:
	T* fwt;
	size_t N, M;
	T applyfunc(const T& a, const T& b){
		return a + b;
	}
	T queryfunc(const T& a, const T& b){
		return a + b;
	}

public:
	FenTree2D(size_t n, size_t m){
		N = n + 1;
		M = m + 1;
		fwt = new T[N * M]();
	}
	~FenTree2D(){
		delete[] fwt;
	}
	void update(size_t i, size_t j, T value){
		for(i++; i < N; i += (i & -i))
			for(size_t tempj = j+1; tempj < M; tempj += (tempj & -tempj))
				fwt[i*M+tempj] = applyfunc(fwt[i*M+tempj], value);
	}
	T query(size_t i, size_t j){
		T ans = 0;
		for(i++; i; i &= (i - 1))
			for(size_t tempj = j+1; tempj; tempj &= (tempj - 1))
				ans = queryfunc(ans, fwt[i*M+tempj]);
		return ans;
	}
};

class FenTreap{
private:
	class treap{
	//Modified treap to query number of elements less than a given element
	//Does not have remove function or bulk functions
	private:
		struct node{
			int num, priority, numleft, count;
			node *l, *r;
			node(int n, int p){
				num = n;
				priority = p;
				l = r = NULL;
				count = 1;
				numleft = 0;
			}
			~node(){
				if(l != NULL)
					delete l;
				if(r != NULL)
					delete r;
			}
		} *root;
		void rr(node *&p){ //Make left node the parent
			node *t = p->l;
			p->l = t->r;
			p->numleft -= t->numleft + t->count;
			t->r = p;
			p = t;
		}
		void lr(node *&p){ //Make right node the parent
			node *t = p->r;
			p->r = t->l;
			t->l = p;
			t->numleft += p->numleft + p->count;
			p = t;
		}
		void insert(node *&n, int num, int p){
			if(n == NULL)
				n = new node(num, p);
			else
				if(num < n->num){
					n->numleft++;
					insert(n->l, num, p);
					if(n->l->priority < n->priority)
						rr(n);
				}else if(num > n->num){
					insert(n->r, num, p);
					if(n->r->priority < n->priority)
						lr(n);
				}else
					n->count++;
		}
		int query(node *&n, int num){
			if(n == NULL) return 0;
			int sum = 0;
			if(n->num >= num)
				sum += query(n->l, num);
			else
				sum += n->numleft + n->count + query(n->r, num);
			return sum;
		}
	public:
		treap(){
			root = new node(1000005, RAND_MAX);
		}
		~treap(){
			delete root;
		}
		void insert(int num, int p){
			insert(root, num, p);
		}
		int query(int num){
			//Number of elements less than num
			return query(root, num);
		}
	};
	treap* fwt;
	size_t N;

public:
	FenTreap(size_t n){
		N = n + 1;
		fwt = new treap[N]();
	}
	~FenTreap(){
		delete[] fwt;
	}
	void update(size_t i, int value){
		int p = rand();
		for(i++; i < N; i += (i & -i))
			fwt[i].insert(value, p);
	}
	int query(size_t i, int num){
		int ans = 0;
		for(i++; i; i &= (i - 1))
			ans += fwt[i].query(num);
		return ans;
	}
};

void FastIO::solve(){
	//5 hours of experimenting, not suitable for competitive programming but definitely learned a lot
	//Next level Data Structure intense problem involving primes :D
	//O(N*169*(logN*log169 + logN) + Q*log169 + QlogN*log169 + Qlog^2(N)) for 169 primes
	srand(time(NULL));
	vector<int> primes;
	sieve(primes);
	int N, Q, size = primes.size();
	readInt(N);
	int a[N], count;
	FenTree2D<int> expcount(N, size);
	FenTreap bigprime(N);
	for(int i = 0; i < N; i++){
		readInt(a[i]);
		for(int j = 0; j < size && a[i] != 1; j++){
			count = 0;
			while(a[i]%primes[j] == 0){
				a[i] /= primes[j];
				count++;
			}
			if(count)
				expcount.update(i, j, count);
		}
		if(a[i] != 1)
			bigprime.update(i, a[i]);
	}
	int L, R, X, Y, k, l;
	readInt(Q);
	while(Q--){
		readInt(L);
		readInt(R);
		L--;
		R--;
		readInt(X);
		readInt(Y);
		int k = lower_bound(primes.begin(), primes.end(), X)-primes.begin();
		int l = lower_bound(primes.begin(), primes.end(), Y)-primes.begin();
		if(primes[l] > Y || l == size)
			l--;
		count = 0;
		count += expcount.query(R, l) - expcount.query(L-1, l) - expcount.query(R, k-1) + expcount.query(L-1, k-1);
		count += bigprime.query(R, Y+1) - bigprime.query(L-1, Y+1) - bigprime.query(R, X) + bigprime.query(L-1, X);
		printf("%d\n", count);
	}
}