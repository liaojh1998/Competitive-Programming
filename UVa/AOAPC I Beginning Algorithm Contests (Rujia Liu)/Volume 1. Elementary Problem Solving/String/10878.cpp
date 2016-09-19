//Title: Decode the tape
//Type: Simulation
//Solution: WTF
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char tape[12];
int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while(gets(tape)){
		if(tape[0] != '|') continue;
		//ASCII lol
		char c = 0;
		for(int i = 0; tape[i]; i++){
			if(tape[i] == ' ' || tape[i] == 'o')
				c <<= 1;
			if(tape[i] == 'o')
				c++;
		}
		printf("%c",c);
	}
	return 0;
}