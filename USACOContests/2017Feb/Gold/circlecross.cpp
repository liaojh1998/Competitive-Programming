#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
int readInt(int &n){
	register int c;
	n = 0;
	bool neg = false;
	c = getchar();
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
	if(!(~c)) return -1;
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
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
	if(!(~c)) return -1;
	if(c == '-') neg = true, c = getchar();
	if(c != '.'){
		for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
		if(c != '.'){
			if(neg) n = -n;
			return 1;
		}
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
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
	if(!(~c)) return -1;
	//32 if stop at space, 10 if stop at next line
	while(c != 10 && c != 32 && ~c){
		str[len++] = c;
		c = getchar();
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
void readIntArr(int *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readInt(n[i]))){
			n[i] = 0;
			return;
		}
}
void readLLArr(long long *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readLL(n[i]))){
			n[i] = 0;
			return;
		}
}
void readDoubleArr(double *n, int len){
	for(int i = 0; i < len; i++)
		if(!(~readDouble(n[i]))){
			n[i] = 0;
			return;
		}
}

template<typename T> class FenTree{
private:
	//Set array to static if using C++11
	T* fwt;
	size_t N;
	//N is useful if possibility of querying out of range

public:
	//Useful functions
	//Constructor, n - size of the array
	FenTree(size_t n){
		N = n+2;
		fwt = new T[N];
		memset(fwt, 0, sizeof(T)*(N));
	}

	//Functions that relates child to parent in the segment tree
	//This example apply sum
	T applyfunc(const T& a, const T& b){
		return a + b;
	}
	T queryfunc(const T& a, const T& b){
		return a + b;
	}

	//Calculating prefix sum from 0 to i
	//Update: O(logN)
	//Access: O(logN)
	//Modify (begins at original index of 0, but fenwick index start at 1)
	void modify(size_t i, const T& value){
		for(i++; i < N; i += (i & -i))
			fwt[i] = applyfunc(fwt[i], value);
	}
	//Query (same as modify)
	T query(size_t i){
		T ans = 0;
		for(i++; i; i &= (i - 1))
			ans = queryfunc(ans, fwt[i]);
		return ans;
	}
};

void solve(){
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	int N, temp;
	readInt(N);
	vector<pair<int, int> > loc(N+1, pair<int, int>(-1, -1));
	for(int i = 0; i < 2*N; i++){
		readInt(temp);
		if(loc[temp].first != -1)
			loc[temp].second = i;
		else
			loc[temp].first = i;
	}
	sort(loc.begin(), loc.end());
	FenTree<int> bit(2*N);
	int ans = 0;
	for(int i = 1; i <= N; i++){
		ans += bit.query(loc[i].second) - bit.query(loc[i].first);
		bit.modify(loc[i].second, 1);
	}
	printf("%d\n", ans);
}
int main(){
	solve();
	return 0;
}