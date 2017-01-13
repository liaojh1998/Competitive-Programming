//Title: Password
//Type: Complete Search
//Complexity: O(6!) / O(1)
//Solution: Brute force generation and hashing strings / Like how the hashing worked, a little bit of math changes everything.
		//	Find all possible letters that can be used, make sure they're distinct, because no repetitions are allowed.
		//	If the possible amount of these letters in each column multiplied is < k, then there's no possible solution, because this is the total amount of combinations.
		//	Like how the hashing was done, dehash based on size division then modding.
#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
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
	for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
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
	if(!(~c)) return -1;
	while(c < 33 && ~c) c = getchar(); //32 if space should be included
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

/* //Brute force solution
bool found[12000000], has[5][30];
int config[6][5];
vector<int> passwords;
int pw[5] = {1, 26, 676, 17576, 456976};
void dfs(int col, int combi){
	if(col == 5 && !found[combi]){
		passwords.push_back(combi);
		found[combi] = true;
		return;
	}
	if(col == 5)
		return;
	for(int i = 0; i < 6; i++)
		if(has[col][config[i][col]])
			dfs(col+1, combi + config[i][col]*pw[4-col]);
}
void dehash(int pws){
	char c1 = pws/pw[4] + 'A';
	pws %= pw[4];
	char c2 = pws/pw[3] + 'A';
	pws %= pw[3];
	char c3 = pws/pw[2] + 'A';
	pws %= pw[2];
	char c4 = pws/pw[1] + 'A';
	pws %= pw[1];
	char c5 = pws/pw[0] + 'A';
	printf("%c%c%c%c%c\n", c1, c2, c3, c4, c5);
}
*/
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int t, k;
	readInt(t);
	while(t--){
		readInt(k);
		int has[5][30], checked[5][30];
		memset(has, 0, sizeof(has));
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++)
				has[j][getchar() - 'A'] = true;
			getchar();
		}
		int size[5], div[6];
		memset(size, 0, sizeof(size));
		memset(checked, 0, sizeof(checked));
		char config[5][6];
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++){
				int next = getchar() - 'A';
				if(has[j][next] && !checked[j][next]){
					config[j][size[j]++] = next;
					checked[j][next] = true;
				}
			}
			getchar();
		}
		int temp = size[0];
		for(int i = 1; i < 5; i++) temp *= size[i];
		if(temp < k){
			printf("NO\n");
			continue;
		}
		k -= 1;
		for(int i = 0; i < 5; i++) sort(config[i], config[i]+size[i]);
		div[4] = 1;
		for(int i = 3; i >= 0; i--) div[i] = div[i+1]*size[i+1];
		for(int i = 0; i < 5; i++){
			printf("%c", config[i][k/div[i]] + 'A');
			k %= div[i];
		}
		printf("\n");
		/* //Brute force solution
		memset(found, 0, sizeof(found));
		memset(has, 0, sizeof(has));
		passwords.clear();
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++)
				config[i][j] = getchar() - 'A';
			getchar();
		}
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++)
				has[j][getchar() - 'A'] = true;
			getchar();
		}
		for(int i = 0; i < 6; i++)
			if(has[0][config[i][0]])
				dfs(1, config[i][0]*pw[4]);
		if(k > passwords.size()){
			printf("NO\n");
			continue;
		}
		sort(passwords.begin(), passwords.end());
		dehash(passwords[k-1]);
		*/
	}
	return 0;
}