/*
ID: liaojh11
PROG: ratios
LANG: C++
*/
//Title: ratios
//Type: Brute Force
//Solution: Integers in the goal ratio and mixture ratios are all non-negative and smaller than 100 in magnitude.
		/*	The number of units of each type of feed in the mixture must be less than 100. The mixture ratios are not linear combinations of each other.

			If it must be less than 100, WOW. O(100^3) solution. LOL

			There's a matrix determinant solution but I'm lazy! Linear algebra can make it rain. :D
			*/
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("ratios.in");
ofstream fout("ratios.out");
int required[3], feeds[3][3];
int main(){
	//Instantiation
	for(int i = 0; i < 3; i++){
		fin >> required[i];
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			fin >> feeds[i][j];
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(!required[j] && feeds[i][j]){
				memset(feeds[i], 0, sizeof(feeds[i]));
			}
		}
	}
	//Brute Force (quite an annoying one actually, spent 2 hours wrecking through feed requirements of 0s)
	int sum[3], a, b, c, adiv, bdiv, cdiv;
	for(int o = 0; o <= 100; o++){
		for(int p = 0; p <= 100; p++){
			for(int q = 0; q <= 100; q++){
				sum[0] = o*feeds[0][0] + p*feeds[1][0] + q*feeds[2][0];
				sum[1] = o*feeds[0][1] + p*feeds[1][1] + q*feeds[2][1];
				sum[2] = o*feeds[0][2] + p*feeds[1][2] + q*feeds[2][2];
				if(!required[0])
					a = adiv = 0;
				else{
					a = sum[0] >= required[0] ? sum[0]%required[0] : 1;
					adiv = sum[0]/required[0];
				}
				if(!required[1])
					b = bdiv = 0;
				else{
					b = sum[1] >= required[1] ? sum[1]%required[1] : 1;
					bdiv = sum[1]/required[1];
				}
				if(!required[2])
					c = cdiv = 0;
				else{
					c = sum[2] >= required[2] ? sum[2]%required[2] : 2;
					cdiv = sum[2]/required[2];
				}
				if(!adiv) adiv = !bdiv ? cdiv : bdiv;
				if(!bdiv) bdiv = !adiv ? cdiv : adiv;
				if(!cdiv) cdiv = !adiv ? bdiv : adiv;
				if(!a && !b && !c){
					if(adiv == bdiv && bdiv == cdiv){
						fout << o << " " << p << " " << q << " " << adiv << endl;
						return 0;
					}
				}
			}
		}
	}
	fout << "NONE" << endl;
	return 0;
}