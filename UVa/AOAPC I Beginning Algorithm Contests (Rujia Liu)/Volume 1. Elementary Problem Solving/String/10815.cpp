//Title: Andy's First Dictionary
//Type: Simulation
//Solution: Ugh
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <cctype>
using namespace std;
class cmp{
	public:
	bool operator() (const char *a, const char *b) const{
		int len = strlen(a) < strlen(b) ? strlen(a) : strlen(b);
		for(int i = 0; i < len; i++)
			if(a[i] != b[i])
				return a[i] < b[i];
		return strlen(a) < strlen(b);
	}
};
set<char*, cmp> dict;
char line[300];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(gets(line)){
		int len = strlen(line);
		for(int i = 0; i < len; i++){
			if(tolower(line[i]) >= 'a' && tolower(line[i]) <= 'z'){
				for(int j = i; j < len+1; j++){
					line[j] = tolower(line[j]);
					if(line[j] < 'a' || line[j] > 'z'){
						char* word = (char*)malloc(sizeof(char)*(j-i));
						strncpy(word, line+i, j-i);
						word[j-i] = '\0';
						int dlen = dict.size();
						dict.insert(word);
						i = j;
						break;
					}
				}
			}
		}
	}
	int len = dict.size();
	for(set<char*>::iterator it = dict.begin(); it != dict.end(); it++){
		printf("%s\n", *it);
	}
	return 0;
}