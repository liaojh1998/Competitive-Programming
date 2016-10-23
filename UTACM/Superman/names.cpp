#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <cstring>
using namespace std;
int T;
int main(){
	scanf("%d", &T);
	getchar();
	while(T--){
		string str[5][3];
		int checked[5][3];
		memset(checked, 0, sizeof(checked));
		for(int i = 0; i < 5; i++){
			cin >> str[i][0] >> str[i][1] >> str[i][2];
			for(int j = 0; j < i; j++){
				if(!(str[i][0].compare(str[j][0]))){
					checked[i][0] = checked[j][0] = 1;
				}
			}
		}
		int has = 0;
		for(int i = 0; i < 5 && !has; i++){
			has = checked[i][0];
		}
		if(has)
			printf("DISAPPOINTMENT\n");
		else
			printf("HAPPINESS\n");
	}
	return 0;
}