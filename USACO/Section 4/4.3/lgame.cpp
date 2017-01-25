/*
ID: liaojh11
PROG: lgame
LANG: C++
*/
//Title: Letter Game
//Type: Data Structures + DFS
//Complexity: O(letters!)
//Solution: First read word and sort for sorted output, use that to determine which words in the dictionary may be used and create a trie for it, then dfs first word while dfs second word and search.
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

struct tree{
	map<tree*, bool> sused;
	bool has, used, fused;
	char* word;
	tree* next[30];
	tree(){
		used = fused = false;
		has = false;
		for(int i = 0; i < 26; i++)
			next[i] = NULL;
	}
};
tree* trie[30];
int table[30] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};
int addWord(char* word, char* test){
	int len = strlen(word), s = strlen(test), used = 0;
	bool possible = true;
	for(int i = 0; i < len; i++){
		bool impossible = true;
		for(int j = 0; j < s; j++)
			if(!(used & (1 << j)) && word[i] == test[j]){
				used |= (1 << j);
				impossible = false;
				break;
			}
		if(impossible) return 0;
	}
	int score = table[word[0]-'a'];
	if(trie[word[0]-'a'] == NULL)
		trie[word[0]-'a'] = new tree;
	tree* cur = trie[word[0]-'a'];
	for(int i = 1; i < len; i++){
		score += table[word[i]-'a'];
		if(cur->next[word[i]-'a'] == NULL)
			cur->next[word[i]-'a'] = new tree;
		cur = cur->next[word[i]-'a'];
	}
	cur->word = new char[10];
	cur->has = true;
	memcpy(cur->word, word, sizeof(char)*10);
	return score;
}
int readDict(char* test){
	char str[10];
	freopen("lgame.dict", "r", stdin);
	int maxScore = 0;
	while(~readStr(str) && str[0] != '.'){
		int score = addWord(str, test);
		if(score > maxScore)
			maxScore = score;
	}
	return maxScore;
}
void sdfs(int &maxScore, vector<pair<char*, char*> >* ans, tree* first, tree* cur, char* str, int size, int used, int curScore){
	if(curScore && curScore == maxScore && cur->has && !cur->fused && !first->sused.count(cur)){
		first->sused[cur] = true;
		ans->push_back(pair<char*, char*>(first->word, cur->word));
	}
	if(curScore > maxScore && cur->has){
		ans->clear();
		maxScore = curScore;
		first->sused[cur] = true;
		ans->push_back(pair<char*, char*>(first->word, cur->word));
	}
	if(used == (1 << size)-1) return;
	for(int i = 0; i < size; i++)
		if(!(used & (1 << i)) && cur->next[str[i]-'a'] != NULL)
			sdfs(maxScore, ans, first, cur->next[str[i]-'a'], str, size, used | (1 << i), curScore+table[str[i]-'a']);
}
void dfs(int &maxScore, vector<pair<char*, char*> >* ans, tree* cur, char* str, int size, int used, int curScore){
	if(curScore == maxScore && cur->has && !cur->used){
		cur->used = true;
		ans->push_back(pair<char*, char*>(cur->word, NULL));
	}
	if(curScore > maxScore && cur->has){
		ans->clear();
		maxScore = curScore;
		cur->used = true;
		ans->push_back(pair<char*, char*>(cur->word, NULL));
	}
	if(used == (1 << size)-1) return;
	if(cur->has && !cur->fused){
		cur->fused = true;
		for(int i = 0; i < size; i++)
			if(!(used & (1 << i)) && trie[str[i]-'a'] != NULL)
				sdfs(maxScore, ans, cur, trie[str[i]-'a'], str, size, used | (1 << i), curScore+table[str[i]-'a']);
	}
	for(int i = 0; i < size; i++)
		if(!(used & (1 << i)) && cur->next[str[i]-'a'] != NULL)
			dfs(maxScore, ans, cur->next[str[i]-'a'], str, size, used | (1 << i), curScore+table[str[i]-'a']);
}
void solve(){
	freopen("lgame.in", "r", stdin);
	freopen("lgame.out", "w", stdout);
	char str[10];
	readStr(str);
	int s = strlen(str);
	sort(str, str+s);
	readDict(str);
	int maxScore = 0;
	vector<pair<char*, char*> > ans;
	for(int i = 0; i < s; i++)
		if(trie[str[i]-'a'] != NULL)
			dfs(maxScore, &ans, trie[str[i]-'a'], str, s, (1 << i), table[str[i]-'a']);
	printf("%d\n", maxScore);
	s = ans.size();
	for(int i = 0; i < s; i++)
		if(ans[i].second == NULL)
			printf("%s\n", ans[i].first);
		else
			printf("%s %s\n", ans[i].first, ans[i].second);
}
int main(){
	solve();
	return 0;
}