/*
ID: liaojh11
PROG: twofive
LANG: C++
*/
//Title: Two Five
//Type: DP
//Complexity: O(<5^10)
//Solution: The trick to this dynamic programming is to realize lexicographically alphabets can be placed in positions where its immediate top and left are filled.
		//	Base case lay in when all alphabets in all rows are filled lexicographically, giving only the starting case scenario.
		//	First step is to find all possible states for an alphabet to be placed and store those states.
		//	Second is to read the string or number, and iterate lexicographically on the matrix until reaching a specific alphabet or number.
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

	int states[26][100][5], possibility[26], r[25], c[25];

public:
	//Constructor, true if using file input/output, defaulted false
	FastIO(bool useFile = false){
		if(useFile){
			freopen("twofive.in", "r", stdin);
			freopen("twofive.out", "w", stdout);
		}
	}

	void solve();
	int dp();
};

int main(){
	FastIO fio(true);
	fio.solve();
	return 0;
}

void FastIO::solve(){
	//Step 1: Build possible states
	memset(possibility, 0, sizeof(possibility));
	for(int i = 0; i < 6; i++)
		for(int j = 0; j <= i; j++)
			for(int k = 0; k <= j; k++)
				for(int l = 0; l <= k; l++)
					for(int m = 0; m <= l; m++){
						int alphabet = i + j + k + l + m;
						states[alphabet][possibility[alphabet]][0] = i;
						states[alphabet][possibility[alphabet]][1] = j;
						states[alphabet][possibility[alphabet]][2] = k;
						states[alphabet][possibility[alphabet]][3] = l;
						states[alphabet][possibility[alphabet]++][4] = m;
					}
	//Read case
	char t;
	t = getchar();
	getchar();
	memset(r, 0, sizeof(r));
	//Step 2: Decipher
	if(t == 'N'){
		int N;
		readInt(N);
		//Subtract possible states of lexicographic alphabet in matrix from N until possible states is more than N and alphabet position cannot change
		for(int i = 1; i < 6; i++)
			for(int j = 1; j < 6; j++)
				for(int alphabet = 0; alphabet < 25; alphabet++)
					if(!r[alphabet]){
						r[alphabet] = i;
						c[alphabet] = j;
						int dpstates = dp();
						if(N > dpstates){
							N -= dpstates;
							r[alphabet] = 0;
							c[alphabet] = 0;
						}
					}
		char str[26];
		for(int alphabet = 0; alphabet < 25; alphabet++)
			str[(r[alphabet]-1)*5 + c[alphabet]-1] = alphabet + 'A';
		str[25] = '\0';
		printf("%s\n", str);
	}else{
		char cur;
		int N = 1;
		//Add possible states of lexicographic alphabets in matrix location until alphabet is same as alphabet in matrix
		for(int i = 1; i < 6; i++)
			for(int j = 1; j < 6; j++){
				cur = getchar() - 'A';
				for(int alphabet = 0; alphabet < cur; alphabet++)
					if(!r[alphabet]){
						r[alphabet] = i;
						c[alphabet] = j;
						N += dp();
						r[alphabet] = 0;
						c[alphabet] = 0;
					}
				r[cur] = i;
				c[cur] = j;
			}
		printf("%d\n", N);
	}
}

//Sum up possible states with specific characters in specific positions
int FastIO::dp(){
	int dpstates[6][6][6][6][6], row[6];
	dpstates[5][5][5][5][5] = 1;
	for(int alphabet = 24; alphabet >= 0; alphabet--)
		for(int i = 0; i < possibility[alphabet]; i++){
			row[0] = 5;
			row[1] = states[alphabet][i][0];
			row[2] = states[alphabet][i][1];
			row[3] = states[alphabet][i][2];
			row[4] = states[alphabet][i][3];
			row[5] = states[alphabet][i][4];
			dpstates[row[1]][row[2]][row[3]][row[4]][row[5]] = 0;
			if(!r[alphabet]){
				int sum = 0;
				for(int j = 1; j < 6; j++)
					if(row[j] < row[j-1]){
						row[j]++;
						sum += dpstates[row[1]][row[2]][row[3]][row[4]][row[5]];
						row[j]--;
					}
				dpstates[row[1]][row[2]][row[3]][row[4]][row[5]] += sum;
			}else{
				//All alphabet states specific to its matrix location
				if(row[r[alphabet]] < row[r[alphabet]-1] && row[r[alphabet]]+1 == c[alphabet]){
					row[r[alphabet]]++;
					int sum = dpstates[row[1]][row[2]][row[3]][row[4]][row[5]];
					row[r[alphabet]]--;
					dpstates[row[1]][row[2]][row[3]][row[4]][row[5]] += sum;
				}
			}
		}
	return dpstates[0][0][0][0][0];
}