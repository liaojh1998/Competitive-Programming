#include <bits/stdc++.h>
using namespace std;

class FastIO{
//#define getchar() (getchar_unlocked()) //For hackerrank
private:
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

class HILLJUMP{
private:
	int N, bsize;
	long long *arr;
	int *next, *bnext, *bk, *lazy;

	void update_range(int p){
		long long s[bsize+205];
		int lstop, loc[bsize+205], ss = 0, q = min(N-1, p+100), index, stop = max(0, ((p-99)/bsize)*bsize);
		while(q > p){
			if(lazy[q/bsize]){
				lstop = ((q/bsize)+1)*bsize;
				for(int i = (q/bsize)*bsize; i < lstop && i < N; i++)
					arr[i] += lazy[q/bsize];
				lazy[q/bsize] = 0;
			}
			index = lower_bound(s, s+ss, arr[q], greater<long long>())-s;
			s[index] = arr[q];
			loc[index] = q;
			ss = index+1;
			q--;
		}
		while(q >= stop){
			if(lazy[q/bsize]){
				lstop = ((q/bsize)+1)*bsize;
				for(int i = (q/bsize)*bsize; i < lstop && i < N; i++)
					arr[i] += lazy[q/bsize];
				lazy[q/bsize] = 0;
			}
			index = lower_bound(s, s+ss, arr[q], greater<long long>())-s;
			if(index && loc[index-1]-q <= 100){
				next[q] = loc[index-1];
				if(next[q] >= ((q/bsize)+1)*bsize){
					bnext[q] = next[q];
					bk[q] = 1;
				}else{
					bnext[q] = bnext[next[q]];
					bk[q] = bk[next[q]]+1;
				}
			}else{
				next[q] = bnext[q] = q;
				bk[q] = 0;
			}
			s[index] = arr[q];
			loc[index] = q;
			ss = index+1;
			q--;
		}
	}

public:
	HILLJUMP(int n, long long *a){
		N = n;
		bsize = max(100, static_cast<int>(sqrt(N)));
		arr = a;
		next = new int[N+5]();
		bnext = new int[N+5]();
		bk = new int[N+5]();
		lazy = new int[N/bsize+5]();
	}
	~HILLJUMP(){
		delete[] next;
		delete[] bnext;
		delete[] bk;
		delete[] lazy;
	}
	void init(){
		long long s[N+5];
		int loc[N+5], ss = 0, index;
		for(int i = N-1; i >= 0; i--){
			index = lower_bound(s, s+ss, arr[i], greater<long long>())-s;
			if(index && loc[index-1]-i <= 100){
				next[i] = loc[index-1];
				if(next[i] >= ((i/bsize)+1)*bsize){
					bnext[i] = next[i];
					bk[i] = 1;
				}else{
					bnext[i] = bnext[next[i]];
					bk[i] = bk[next[i]]+1;
				}
			}else{
				next[i] = bnext[i] = i;
				bk[i] = 0;
			}
			s[index] = arr[i];
			loc[index] = i;
			ss = index+1;
		}
	}
	int query(int i, int k){
		i--;
		while(bk[i] <= k && bnext[i] != i){
			k -= bk[i];
			i = bnext[i];
		}
		while(k-- && next[i] != i)
			i = next[i];
		return i+1;
	}
	void update(int L, int R, long long X){
		L--;
		R--;
		int lstop = ((L/bsize)+1)*bsize, rstart = R/bsize;
		for(int i = L; i < lstop && i <= R; i++)
			arr[i] += X;
		if(R >= lstop){
			for(int i = rstart*bsize; i <= R; i++)
				arr[i] += X;
			for(int i = L/bsize+1; i < rstart; i++)
				lazy[i] += X;
		}
		update_range(R);
		update_range(L-1);
	}
};

void FastIO::solve(){
	//Interestingly, brute force is always better than sqrt decomposition in average case (due to huge amount of memory manipulation)
	//But in the worst case sqrt decomposition is guaranteed to be better
	//Was trying to solve this using segment tree + lazy propagation (possible but I still don't know how, approached from a merge sort tree point of view)
	//zhouyuchen had an interesting solution which used link/cut splay tree data structure to solve the problem
	int N, Q, t, l, r, k;
	long long X;
	readInt(N);
	readInt(Q);
	long long arr[N+5];
	for(int i = 0; i < N; i++)
		readLL(arr[i]);
	HILLJUMP q(N, arr);
	q.init();
	while(Q--){
		readInt(t);
		if(t == 1){
			readInt(l);
			readInt(k);
			printf("%d\n", q.query(l, k));
		}else{
			readInt(l);
			readInt(r);
			readLL(X);
			q.update(l, r, X);
		}
	}
}