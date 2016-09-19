//Title: Where's Waldorf?
//Type: Simulation
//Solution: Just do it!
#include <cstdio>
#include <cstring>
#include <vector>
#include <locale>
using namespace std;
char str[51][51], word[51], tword[51];
int C, x, y, W, ansy, ansx;
struct co{int x, y;} temp;
vector<co> coords[26];
int main(){
	scanf("%d", &C);
	while(C--){
		scanf("%d%d", &y, &x);
		getchar();
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				scanf("%c", &str[i][j]);
				str[i][j] = toupper(str[i][j]);
				temp.y = i;
				temp.x = j;
				coords[str[i][j] - 'A'].push_back(temp);
			}
			getchar();
		}
		scanf("%d", &W);
		getchar();
		for(int i = 0; i < W; i++){
			memset(word, 0, sizeof(word));
			memset(tword, 0, sizeof(tword));
			scanf("%s", &word);
			getchar();
			int len = strlen(word);
			tword[len] = '\0';
			for(int j = 0; j < len; j++)
				word[j] = toupper(word[j]);
			int flen = coords[word[0]-'A'].size(), letter = word[0]-'A';
			bool found = false;
			for(int j = 0; j < flen; j++){
				//Up
				if(!found && coords[letter][j].y - (len-1) >= 0){
					for(int k = 0; k < len; k++)
						tword[k] = str[coords[letter][j].y-k][coords[letter][j].x];
					if(!strcmp(tword, word)){
						found = true;
						ansy = coords[letter][j].y;
						ansx = coords[letter][j].x;
					}
				}
				//Down
				if(!found && coords[letter][j].y + len-1 < y){
					for(int k = 0; k < len; k++)
						tword[k] = str[coords[letter][j].y+k][coords[letter][j].x];
					if(!strcmp(tword, word)){
						found = true;
						ansy = coords[letter][j].y;
						ansx = coords[letter][j].x;
					}
				}
				//Left
				if(!found && coords[letter][j].x - (len-1) >= 0){
					for(int k = 0; k < len; k++)
						tword[k] = str[coords[letter][j].y][coords[letter][j].x-k];
					if(!strcmp(tword, word)){
						found = true;
						ansy = coords[letter][j].y;
						ansx = coords[letter][j].x;
					}
				}
				//Right
				if(!found && coords[letter][j].x + len-1 < x){
					for(int k = 0; k < len; k++)
						tword[k] = str[coords[letter][j].y][coords[letter][j].x+k];
					if(!strcmp(tword, word)){
						found = true;
						ansy = coords[letter][j].y;
						ansx = coords[letter][j].x;
					}
				}
				//Up-Left
				if(!found && coords[letter][j].x - (len-1) >= 0 && coords[letter][j].y - (len-1) >= 0){
					for(int k = 0; k < len; k++)
						tword[k] = str[coords[letter][j].y-k][coords[letter][j].x-k];
					if(!strcmp(tword, word)){
						found = true;
						ansy = coords[letter][j].y;
						ansx = coords[letter][j].x;
					}
				}
				//Up-Right
				if(!found && coords[letter][j].y - (len-1) >= 0 && coords[letter][j].x + len-1 < x){
					for(int k = 0; k < len; k++)
						tword[k] = str[coords[letter][j].y-k][coords[letter][j].x+k];
					if(!strcmp(tword, word)){
						found = true;
						ansy = coords[letter][j].y;
						ansx = coords[letter][j].x;
					}
				}
				//Down-Right
				if(!found && coords[letter][j].y + len-1 < y && coords[letter][j].x + len-1 < x){
					for(int k = 0; k < len; k++)
						tword[k] = str[coords[letter][j].y+k][coords[letter][j].x+k];
					if(!strcmp(tword, word)){
						found = true;
						ansy = coords[letter][j].y;
						ansx = coords[letter][j].x;
					}
				}
				//Down-Left
				if(!found && coords[letter][j].y + len-1 < y && coords[letter][j].x - (len-1) >= 0){
					for(int k = 0; k < len; k++)
						tword[k] = str[coords[letter][j].y+k][coords[letter][j].x-k];
					if(!strcmp(tword, word)){
						found = true;
						ansy = coords[letter][j].y;
						ansx = coords[letter][j].x;
					}
				}
				if(found) break;
			}
			printf("%d %d\n", ansy+1, ansx+1);
		}
		if(C != 0)
			printf("\n");
		for(int i = 0; i < 26; i++)
			coords[i].clear();
	}
	return 0;
}