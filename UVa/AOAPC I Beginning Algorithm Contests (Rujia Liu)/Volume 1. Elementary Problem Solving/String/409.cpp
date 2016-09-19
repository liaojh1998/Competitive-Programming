//Title: Excuses, Excuses!
//Type: Simulation
//Solution: Just do it!
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;
char key[20][20], str[20][80];
int K, E, set;
vector<int> excuse;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(~scanf("%d%d", &K, &E)){
		set++;
		getchar();
		for(int i = 0; i < K; i++){
			scanf("%s", &key[i]);
			getchar();
		}
		for(int i = 0; i < E; i++){
			scanf("%[^\n]", &str[i]);
			getchar();
		}
		int maxocc = 0;
		for(int i = 0; i < E; i++){
			int len = strlen(str[i]), occ = 0;
			for(int j = 0; j < len; j++){
				if(tolower(str[i][j]) >= 'a' && tolower(str[i][j]) <= 'z'){
					for(int k = j; k < len+1; k++){
						if(tolower(str[i][k]) < 'a' || tolower(str[i][k]) > 'z'){
							char word[80];
							strncpy(word, str[i]+j, k-j);
							word[k-j] = '\0';
							int wordlen = strlen(word);
							for(int l = 0; l < wordlen; l++)
								word[l] = tolower(word[l]);
							for(int l = 0; l < K; l++){
								if(!strcmp(key[l], word))
									occ++;
							}
							j = k;
							break;
						}
					}
				}
			}
			if(occ > maxocc){
				excuse.clear();
				maxocc = occ;
				excuse.push_back(i);
			}else if(occ == maxocc){
				excuse.push_back(i);
			}
		}
		printf("Excuse Set #%d\n", set);
		int len = excuse.size();
		for(int i = 0; i < len; i++){
			printf("%s\n", str[excuse[i]]);
		}
		excuse.clear();
		printf("\n");
	}
	return 0;
}