//Problem: Contaminated Milk (Bronze)
//Type: Ad hoc (Almost like DP)
//Solution: Again, simple Brute Force
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("badmilk.in");
ofstream fout("badmilk.out");
int N, M, D, S, milk[51], visited[51][51], timeline[101][51][51];
int main(){
	//Instantiation
	fin >> N >> M >> D >> S;
	for(int i = 0; i < D; i++){
		int p, m, t;
		fin >> p >> m >> t;
		timeline[t][p][m] = 1;
		if(!visited[p][m]){
			milk[m]++;
			visited[p][m] = 1;
		}
	}
	//Assume person at time t drank all previous t milk
	for(int i = 1; i < 101; i++){
		for(int j = 1; j < 51; j++){
			for(int k = 1; k < 51; k++){
				timeline[i][j][k] |= timeline[i-1][j][k];
			}
		}
	}
	//Search for the milk that's gone bad by aligning all milk sick people have drank
	int bad[51];
	memset(bad, 1, sizeof(bad));
	for(int i = 0; i < S; i++){
		int p, t;
		fin >> p >> t;
		for(int j = 1; j < 51; j++)
			bad[j] &= timeline[t-1][p][j]; //t-1 because contaminated milk must be drank at some strictly earlier point in time
	}
	//Find the bad milk
	int bmilk = 0;
	for(int i = 1; i < 51; i++){
		if(bad[i] && milk[i] > milk[bmilk]){
			bmilk = i;
		}
	}
	//Print the amount of people that drank it
	fout << milk[bmilk] << endl;
	return 0;
}