//Title: Palindromes
//Type: Simulation
//Solution: Just do it!
#include <cstdio>
#include <cstring>
using namespace std;
char str[25];
bool mir(char a, char b){
	switch(a){
		case 'A': if(b != 'A') return false; break;
		case 'E': if(b != '3') return false; break;
		case 'H': if(b != 'H') return false; break;
		case 'I': if(b != 'I') return false; break;
		case 'J': if(b != 'L') return false; break;
		case 'L': if(b != 'J') return false; break;
		case 'M': if(b != 'M') return false; break;
		case 'O': if(b != 'O') return false; break;
		case 'S': if(b != '2') return false; break;
		case 'T': if(b != 'T') return false; break;
		case 'U': if(b != 'U') return false; break;
		case 'V': if(b != 'V') return false; break;
		case 'W': if(b != 'W') return false; break;
		case 'X': if(b != 'X') return false; break;
		case 'Y': if(b != 'Y') return false; break;
		case 'Z': if(b != '5') return false; break;
		case '1': if(b != '1') return false; break;
		case '2': if(b != 'S') return false; break;
		case '3': if(b != 'E') return false; break;
		case '5': if(b != 'Z') return false; break;
		case '8': if(b != '8') return false; break;
		default: return false;
	}
}
int main(){
	while(~scanf("%s", &str)){
		getchar();
		bool mirror = true, pal = true;
		int len = strlen(str);
		for(int i = 0; i < len/2; i++){
			//palindromes
			if(pal && str[i] != str[len-i-1]) pal = false;
			//mirrors
			if(mirror) mirror = mir(str[i], str[len-i-1]);
		}
		//Odd strings
		if(len & 1 && mirror) mirror = mir(str[len/2], str[len/2]);
		//Print answer
		if(mirror && pal)
			printf("%s -- is a mirrored palindrome.\n", str);
		else if(mirror && !pal)
			printf("%s -- is a mirrored string.\n", str);
		else if(!mirror && pal)
			printf("%s -- is a regular palindrome.\n", str);
		else if(!mirror && !pal)
			printf("%s -- is not a palindrome.\n", str);
		printf("\n");
	}
	return 0;
}