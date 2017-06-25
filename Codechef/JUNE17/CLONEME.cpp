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

#define MOD (1000000009)
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
			root = new node(100005, RAND_MAX);
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
		srand(time(NULL));
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

long long fexp(long long b, long long p){
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
	//O(N*log^2(N) + Q*log^2(N))
	int T, N, Q, l1, r1, l2, r2, t;
	long long diff, diff2, h1, h2, sum, n1, n2;
	bool rev;
	readInt(T);
	while(T--){
		readInt(N);
		readInt(Q);
		FenTreap fwt(N+1);
		vector<long long> a, a2, a3;
		a.push_back(0);
		a2.push_back(0);
		a3.push_back(1);
		for(int i = 1; i <= N; i++){
			readInt(t);
			fwt.update(i, t);
			a.push_back(t);
			a2.push_back(a[i]*a[i] + a2[i-1]); //Squared prefix
			a3.push_back((a[i]*a3[i-1])%MOD); //Multiplication hash
			a[i] += a[i-1]; //Prefix
		}
		for(int i = 0; i < Q; i++){
			readInt(l1);
			readInt(r1);
			readInt(l2);
			readInt(r2);
			diff = a[r2]-a[l2-1]-a[r1]+a[l1-1];
			diff2 = a2[r2]-a2[l2-1]-a2[r1]+a2[l1-1];
			h1 = (a3[r1]*fexp(a3[l1-1], MOD-2))%MOD; //Using Fermat's little theorem for modular multiplicative inverse
			h2 = (a3[r2]*fexp(a3[l2-1], MOD-2))%MOD;
			//Case 1: Congruent subarrays
			if(diff == 0 && diff2 == 0 && h1 == h2)
				printf("YES\n");
			else{
				rev = false;
				if(diff < 0){
					diff = -diff;
					diff2 = -diff2;
					rev = true;
				}
				//Case 2: Dissimilar subarrays: cannot find a+b
				if(diff2 < 0 || diff == 0 || diff2%diff)
					printf("NO\n");
				else{
					sum = diff2/diff;
					//Case 3: Dissimilar subarrays: cannot find a or b
					if((diff+sum)%2 || (sum-diff)%2)
						printf("NO\n");
					else{
						if(rev){
							n2 = (sum-diff)/2; //((a + b) - (a - b))/2 = 2b/2 = b
							n1 = (diff+sum)/2; //((a - b) + (a + b))/2 = 2a/2 = a
						}else{
							n2 = (diff+sum)/2;
							n1 = (sum-diff)/2;
						}
						//Case 4: Dissimilar subarrays: hashing not congruent after deleting a and b
						if(((h2*fexp(n2, MOD-2))%MOD) != ((h1*fexp(n1, MOD-2))%MOD))
							printf("NO\n");
						else{
							//Case 5: Dissimilar subarrays: there exist c such that a < c < b, which moves a and b into different indices after sorting subarrays
							if(rev)
								t = fwt.query(r1, n1) - fwt.query(r1, n2+1) - fwt.query(l1-1, n1) + fwt.query(l1-1, n2+1);
							else
								t = fwt.query(r1, n2) - fwt.query(r1, n1+1) - fwt.query(l1-1, n2) + fwt.query(l1-1, n1+1);
							if(t)
								printf("NO\n");
							else
								//Case 6: If all tests pass, subarrays must be similar
								printf("YES\n");
						}
					}
				}
			}
		}
	}
}