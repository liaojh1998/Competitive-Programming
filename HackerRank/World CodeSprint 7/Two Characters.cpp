#include <cstdio>
#include <cstring>
using namespace std;
int len, llen;
char str[1000], last, list[26];
bool del[200], complete;
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &len);
	getchar();
	scanf("%s", &str);
	while(!complete){
		complete = true;
		last = 0;
		for(int i = 0; i < len; i++){
			if(!del[str[i]] && str[i] == last){
				complete = false;
				del[str[i]] = true;
				break;
			}else if(!del[str[i]] && str[i] != last)
				last = str[i];
		}
	}
	for(int i = 0; i < len; i++)
		if(!del[str[i]]){
			list[llen++] = str[i];
			del[str[i]] = true;
		}
	if(!llen){
		printf("0\n");
		return 0;
	}
	int sum = 0;
	for(int i = 0; i < llen-1; i++){
		for(int j = i+1; j < llen; j++){
			int temp = 0;
			last = 0;
			for(int k = 0; k < len; k++){
				if(str[k] == last){
					temp = 0;
					break;
				}else if(str[k] == list[i] || str[k] == list[j]){
					temp++;
					last = str[k];
				}
			}
			if(temp > sum)
				sum = temp;
		}
	}
	printf("%d\n", sum);
    return 0;
}