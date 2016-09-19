/*
ID: liaojh11
PROG: prefix
LANG: C++
*/
//Title: prefix
//Type: DP
//Solution: Flag every single matching primitive and test for more primitives from there.
		/*	Instead of the normal DFS combination of every matching primitive into a prefix that matches with the sequence,
			we know that after a primitive requires another primitive such that it can create a prefix of the sequence,
			therefore we just need to find all primitives of the prefix and see if we can match more primitives after it.
			*/
#include <fstream>
#include <cstring>
using namespace std;
FILE *fin = fopen("prefix.in", "r");
FILE *fout = fopen("prefix.out", "w");
int flag[200001], len; //The extra 1 will be the last flag to say the prefix is the whole sequence.
char prim[201][11]; //The extra 1 in 200 is a case of having 200 primitives and 1 '.', the extra 1 in 10 is the true case of matching primitives of length 10
char seq[200000];
int main()
{   
	//Instantiation
	memset(flag, 0, sizeof(flag)); //Set all flags to nothing
	int primnum = 0; //Number of primitives
	while(1){
		fscanf(fin, "%s", prim[primnum]);
		if(prim[primnum][0] == '.') break;
		primnum++;
	}
	len = 0;
	while(fscanf(fin, "%s", seq+len) == 1)
		len += strlen(seq+len); //Length of sequence

	//DP
	int best, k, i;
	flag[0] = 1; //Start with first flag, even if there's no sequence
	for(i = 0; i < len; i++){
		if(flag[i]){
			best = i; //Best will be 0 even if length is 0
			for(int j = 0; j < primnum; j++){
				for(k = 0; k + i < len && prim[j][k] && prim[j][k] == seq[k+i]; k++); //Basically start at a flagged place, match the flagged character
																					  //with primitive characters and see which one completely matches.
				if(!prim[j][k]) //If ends at the end of a primitive where there's no character
					flag[i+k] = 1; //Set a flag point
			}
		}
	}

	if(flag[i]) best = i; //The case above ends at length of the sequence, this is where the last flag comes in,
						  //a flag beyond the length of the sequence which tells the whole sequence is a prefix.
	fprintf(fout, "%i\n", best);
	return 0;
}