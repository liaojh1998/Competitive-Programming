//Title: Immediate Decodability
//Type: Simulation
//Solution: A special tree called binary trie!
#include <cstdio>
#include <cstring>
using namespace std;
int set;
bool has, trie[(2<<11)], triemapped[(2<<11)];
char str[10];
int index(char* word){
	int len = strlen(word), level = (1<<len)-2;
	for(int i = 0; i < len; i++){
		level += (str[len-1-i]-'0')*(1<<i);
	}
	return level;
}
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	set++;
	while(~scanf("%s", &str)){
		getchar();
		if(str[0]-'0' == 9){
			memset(trie, 0, sizeof(trie));
			memset(triemapped, 0, sizeof(triemapped));
			if(has)
				printf("Set %d is not immediately decodable\n", set++);
			else
				printf("Set %d is immediately decodable\n", set++);
			has = false;
		}else{
			char temp[11];
			int len = strlen(str);
			trie[index(str)] = true;
			for(int i = 1; i <= len; i++){
				strncpy(temp, str, i);
				temp[i] = '\0';
				//printf("%s\t%d %d\n", temp, trie[index(temp)], triemapped[index(temp)]);
				if(!has) has = trie[index(temp)] && triemapped[index(temp)];
				triemapped[index(temp)] = true;
			}
		}
	}
	return 0;
}