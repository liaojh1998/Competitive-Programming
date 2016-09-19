//Title: Automatic Poetry
//Type: Simulation
//Solution: Just do it!
#include <cstdio>
#include <cstring>
int C, s1len, s2len, s3len, s4len;
char s1[100], s2[100], s3[100], s4[100], out[100], c;
int main(){
	scanf("%d", &C);
	getchar();
	while(C--){
		scanf("%[^'\n']", &out);
		getchar();
		int i = 0, len = strlen(out);
		for(; i < len && out[i] != '<'; i++)
			printf("%c", out[i]);
		i++;
		for(; i < len && out[i] != '>'; i++)
			s1[s1len++] = out[i];
		i++;
		for(; i < len && out[i] != '<'; i++)
			s2[s2len++] = out[i];
		i++;
		for(; i < len && out[i] != '>'; i++)
			s3[s3len++] = out[i];
		i++;
		for(; i < len; i++)
			s4[s4len++] = out[i];
		printf("%s%s%s%s\n", s1, s2, s3, s4);
		memset(out, 0, sizeof(out));
		scanf("%[^...]", &out);
		scanf("...");
		getchar();
		printf("%s%s%s%s%s\n", out, s3, s2, s1, s4);
		s1len = s2len = s3len = s4len = 0;
		memset(s1, 0, sizeof(s1));
		memset(s2, 0, sizeof(s2));
		memset(s3, 0, sizeof(s3));
		memset(s4, 0, sizeof(s4));
		memset(out, 0, sizeof(out));
	}
	return 0;
}