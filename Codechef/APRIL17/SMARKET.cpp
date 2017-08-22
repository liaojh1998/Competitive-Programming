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

template<typename T> class FenTree{
private:
	T* fwt;
	size_t N;

	T applyfunc(const T& a, const T& b){
		return a + b;
	}
	T queryfunc(const T& a, const T& b){
		return a + b;
	}
	T reversefunc(const T& a, const T& b){
		return a - b;
	}

public:
	//Useful functions
	//Constructor, n - size of the array
	FenTree(size_t n){
		N = n + 1;
		fwt = new T[N]();
	}
	//Destructor
	~FenTree(){
		delete[] fwt;
	}

	T operator[](size_t i){
		T ans = fwt[i+1];
		for(size_t next = i & (i + 1); i > next; i &= (i - 1))
			ans = reversefunc(ans, fwt[i]);
		return ans;
	}
	void update(size_t i, T value){
		for(i++; i < N; i += (i & -i))
			fwt[i] = applyfunc(fwt[i], value);
	}
	T query(size_t i){
		T ans = 0;
		for(i++; i; i &= (i - 1))
			ans = queryfunc(ans, fwt[i]);
		return ans;
	}
};

int main(){
	FastIO fio;
	fio.solve();
	return 0;
}

/* Subtasks comments:

#1:
Where N, Q <= 3000, we can simply come up with a brute force O(Q*N) search algorithm for the correct answer.

#2:
I do not believe this solution is the most optimal one, but it was enough to AC.
Since queries are offline, we can remodel them for MO's square root decomposition.
Change N stocks into blocks, and change queries to query for blocks of size >= K.
To change queries, binary search two times for each end, and if the query is inside a block, simply trim it off, move to next block, and add trimmed to the query answer if it has a length of K or more.
Sort all queries into MO blocks. Here, MO's queries will query for blocks of size at least K, thus we can use K as indices of a Fenwick's tree and find the sum of stable block of order K by tree.query(N) - tree.query(K-1).
This allows the add and remove function of the MO blocks to be the update(K, 1) and update(K, -1) of the Fenwick's tree, respectively.

In total, our algorithm takes Q*log(N) of binary search, Q*log(Q) sorting of MO's blocks, and Q*sqrt(N)*log(N) queries from Fenwick's Tree under MO's decomposition, giving us a total run time of O(Q*(log(Q*N) + sqrt(N)*log(N))), barely AC under time limit.

*/

int BLOCK_SIZE;
//Query [L, R]
struct qinterval{
	int L, R, K, index;
};
//MO's comparison
bool cmp(const qinterval& a, const qinterval& b){
	int block_a = a.L / BLOCK_SIZE;
	int block_b = b.L / BLOCK_SIZE;
	if(block_a != block_b)
		return block_a < block_b;
	return a.R < b.R;
}

void FastIO::solve(){
	int T, N, Q;
	readInt(T);
	while(T--){
		readInt(N);
		readInt(Q);
		int values[N+5], isize[N+5];
		pair<int, int> intervals[N+5];
		int size = 0;
		//Read and remodel data
		readInt(values[1]);
		int L = 1, R = 1;
		for(int i = 2; i <= N; i++){
			readInt(values[i]);
			if(values[i] != values[i-1]){
				intervals[size].first = L;
				intervals[size].second = R;
				isize[size] = R-L+1;
				size++;
				L = R = i;
			}else
				R++;
		}
		intervals[size].first = L;
		intervals[size].second = R;
		isize[size] = R-L+1;
		size++;
		//Read query
		int queryAnswer[Q+5], K, qsize = 0, hi, len, qL, qR;
		memset(queryAnswer, 0, sizeof(queryAnswer));
		qinterval qi[Q+5];
		for(int i = 0; i < Q; i++){
			readInt(L);
			readInt(R);
			readInt(K);
			//Binary search for query L
			qL = 0, hi = size-1;
			while(qL < hi){
				int mid = (qL + hi)/2;
				if(L > intervals[mid].second)
					qL = mid + 1;
				else
					hi = mid;
			}
			//Binary search for query R
			qR = 0, hi = size-1;
			while(qR < hi){
				int mid = (qR + hi)/2;
				if(R > intervals[mid].second)
					qR = mid + 1;
				else
					hi = mid;
			}
			//Add query interval
			if(qL == qR && (R - L + 1 >= K))
				queryAnswer[i]++;
			else{
				if(L != intervals[qL].first){
					len = intervals[qL].second-L+1;
					if(len >= K)
						queryAnswer[i]++;
					qL++;
				}
				if(R != intervals[qR].second){
					len = R-intervals[qR].first+1;
					if(len >= K)
						queryAnswer[i]++;
					qR--;
				}
				if(qL <= qR){
					qi[qsize].L = qL;
					qi[qsize].R = qR;
					qi[qsize].K = K;
					qi[qsize].index = i;
					qsize++;
				}
			}
		}
		//MO's square root decomposition algorithm coupled with Fenwick's Tree
		BLOCK_SIZE = static_cast<int>(sqrt(size));
		sort(qi, qi+qsize, cmp);
		FenTree<int> ft(N+1); //Use K as indices
		int mol = 0, mor = -1;
		for(int i = 0; i < qsize; i++){
			L = qi[i].L;
			R = qi[i].R;
			while(mor < R){
				mor++;
				ft.update(isize[mor], 1);
			}
			while(mor > R){
				ft.update(isize[mor], -1);
				mor--;
			}
			while(mol < L){
				ft.update(isize[mol], -1);
				mol++;
			}
			while(mol > L){
				mol--;
				ft.update(isize[mol], 1);
			}
			queryAnswer[qi[i].index] += ft.query(N) - ft.query(qi[i].K-1);
		}
		//Print answer
		for(int i = 0; i < Q; i++)
			printf("%d\n", queryAnswer[i]);
	}
}