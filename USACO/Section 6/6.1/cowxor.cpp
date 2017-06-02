/*
ID: liaojh11
PROG: cowxor
LANG: C++
*/
//Title: Cow XOR
//Type: Number Theory/Data Structures
//Complexity: O(N*21) - 21 binary digits
//Solution: Using the observation that if a ^ b = c, the process can be reversed in such a manner: a ^ c = b and b ^ c = a.
		//	Let sum[i] represent the xor sum from 1 to i, sum[i]^sum[j] where j < i gives a xor sum between j+1 and i.
		//	This effectively reduces the problem to searching for 2 numbers that give the maximum xor sum.
		//	Keep the sums in a trie of 0 and 1 for searching sums to reduce runtime from O(N^2) to O(Nlogb), where b is the xor sum and logb has a maximum of 21 digits.
		//	Barely passing memory limit but the time complexity is about the same as the USACO solution, which actually has a much better memory usage and search.
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
			freopen("cowxor.in", "r", stdin);
			freopen("cowxor.out", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}

#define b(n, i) ((n) & (1 << (i)))

struct data{
	int index, num;
	data(int a, int b){
		index = a;
		num = b;
	}
};

struct node{
	node* bit[2];
	data* d;
	node(){
		bit[0] = NULL;
		bit[1] = NULL;
		d = NULL;
	}
	~node(){
		if(bit[0] != NULL)
			delete bit[0];
		if(bit[1] != NULL)
			delete bit[1];
		if(d != NULL)
			delete d;
	}
};

node* find(node& root, const int& num){
	node* cur = &root;
	int bin;
	for(int i = 20; i >= 0; i--){
		bin = b(num, i) ? 0 : 1;
		cur = cur->bit[bin] != NULL ? cur->bit[bin] : cur->bit[!bin];
	}
	return cur;
}

void add(node& root, const int& index, const int& num){
	node* cur = &root;
	int bin;
	for(int i = 20; i >= 0; i--){
		bin = b(num, i) ? 1 : 0;
		if(cur->bit[bin] == NULL)
			cur->bit[bin] = new node();
		cur = cur->bit[bin];
	}
	if(cur->d == NULL)
		cur->d = new data(index, num);
	else
		cur->d->index = index;
}

void FastIO::solve(){
	//Init
	int N, maxxor = -1, xori, xorj;
	node root;
	//Algorithm
	readInt(N);
	int num = 0, tmp;
	add(root, 0, 0);
	for(int i = 1; i <= N; i++){
		readInt(tmp);
		num ^= tmp;
		node* cur = find(root, num);
		if((num^cur->d->num) > maxxor){
			maxxor = num^cur->d->num;
			xori = cur->d->index+1;
			xorj = i;
		}
		add(root, i, num);
	}
	printf("%d %d %d\n", maxxor, xori, xorj);
}