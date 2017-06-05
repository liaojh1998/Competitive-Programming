/*
ID: liaojh11
PROG: calfflac
LANG: C++
*/
//Title: Calf Flac
//Type: DP
//Complexity: O(N)
//Solution: Manacher's algorithm that improves the DP solution from O(N^2) to O(N) by using the advantage of having palindromes within palindromes
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
			freopen("calfflac.in", "r", stdin);
			freopen("calfflac.out", "w", stdout);
		}
	}

	void solve();
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}

//Builds a Palindromic Substring Array for LPS
template<typename T> class Manacher{
private:
	int N;
	int* psa;
	T* S;

public:
	//Useful functions
	//Constructors: s - string array, N - size of array
	Manacher(T* s, const int& n){
		N = n;
		S = s;
		psa = new int[N*2+1];
	}
	~Manacher(){
		delete[] psa;
	}

	//Access PSA
	int operator[](const int& i){
		return psa[i];
	}

	//Manacher's Algorithm
	void exec(){
		int center = 0, size = N*2+1, bound = -1, rad, loc;
		psa[0] = 0;
		for(int i = 1; i < size; i++){
			rad = (i <= bound) ? min(psa[2*center-i], (bound-i)/2) : 0;
			loc = (i-1)/2;
			//Odd - on char; Even - between char
			if(i%2){
				while(loc+rad+1 < N && loc-rad-1 >= 0 && S[loc-rad-1] == S[loc+rad+1])
					rad++;
				if(i + rad*2 + 1 > bound){
					center = i;
					bound = i + rad*2 + 1;
				}
			}else{
				while(loc+rad+1 < N && loc-rad >= 0 && S[loc-rad] == S[loc+rad+1])
					rad++;
				if(i + rad*2 > bound){
					center = i;
					bound = i + rad*2;
				}
			}
			psa[i] = rad;
		}
		for(int i = 1; i < size; i++)
			psa[i] = ((i%2) ? 1 : 0) + 2*psa[i];
		//To get radius from psa, reverse operations:
		//rad[i] = (psa[i] - (i%2) ? 1 : 0)/2;
	}
};

void FastIO::solve(){
	//Weirdest input and output I'll ever witness
	char str[20005], S[20005], c = getchar();
	int size = 0, ssize = 0, index[20005];
	while(~c){
		str[size] = c;
		c = toupper(c);
		if(c >= 'A' && c <= 'Z'){
			S[ssize] = c;
			index[ssize++] = size;
		}
		size++;
		c = getchar();
	}
	Manacher<char> psa(S, ssize);
	psa.exec();
	int maxpsa = 0, maxindex = 0, s = 2*ssize+1;
	for(int i = 0; i < s; i++)
		if(psa[i] > maxpsa){
			maxpsa = psa[i];
			maxindex = i;
		}
	int start, end;
	if(maxindex%2){
		start = index[(maxindex-1)/2 - (maxpsa-1)/2];
		end = index[(maxindex-1)/2 + (maxpsa-1)/2];
	}else{
		start = index[(maxindex-1)/2 - maxpsa/2 + 1];
		end = index[(maxindex-1)/2 + maxpsa/2];
	}
	printf("%d\n", maxpsa);
	for(; start <= end; start++)
		printf("%c", str[start]);
	printf("\n");
}