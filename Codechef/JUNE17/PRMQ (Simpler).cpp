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

class FenTreap{
#define MOD (100000000)
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
			root = new node(1000005, MOD);
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
		int p = rand()%MOD;
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
	//RIP, this problem does not have updates, query can be simply returned in O(Qlog^2(N)) time, Treap and Fenwick's tree is enough
	//Interestingly, the runtime is actually slower than using a 2D Fenwick's tree :O
	srand(time(NULL));
	vector<int> primes;
	sieve(primes);
	int N, Q, size = primes.size();
	readInt(N);
	int a[N], count, primeprefix[N][size];
	memset(primeprefix, 0, sizeof(primeprefix));
	FenTreap bigprime(N);
	for(int i = 0; i < N; i++){
		readInt(a[i]);
		for(int j = 0; j < size; j++){
			primeprefix[i][j] += (i ? primeprefix[i-1][j] : 0) + (j ? primeprefix[i][j-1] : 0) - (i && j ? primeprefix[i-1][j-1] : 0);
			count = 0;
			while(a[i]%primes[j] == 0){
				a[i] /= primes[j];
				count++;
			}
			primeprefix[i][j] += count;
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
		if(l >= 0)
			count += primeprefix[R][l] - (L ? primeprefix[L-1][l] : 0) - (k ? primeprefix[R][k-1] : 0) + (L && k ? primeprefix[L-1][k-1] : 0);
		count += bigprime.query(R, Y+1) - bigprime.query(L-1, Y+1) - (X > 1000 ? bigprime.query(R, X) - bigprime.query(L-1, X) : 0);
		printf("%d\n", count);
	}
}