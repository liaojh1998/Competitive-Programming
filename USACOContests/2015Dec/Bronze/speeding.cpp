//Problem: Speeding Ticket (Bronze)
//Type: Ad hoc
//Solution: Simple Brute Force
#include <fstream>
using namespace std;
ifstream fin("speeding.in");
ofstream fout("speeding.out");
int N, M, limit[100], bessie[100];
int main(){
	//Instantiation
	fin >> N >> M;
	int lindex = 0, bindex = 0;
	for(int i = 0; i < N; i++){
		int dist, speed;
		fin >> dist >> speed;
		int lim = dist + lindex;
		for(; lindex < lim; lindex++){
			limit[lindex] = speed;
		}
	}
	for(int i = 0; i < M; i++){
		int dist, speed;
		fin >> dist >> speed;
		int lim = dist + bindex;
		for(; bindex < lim; bindex++){
			bessie[bindex] = speed;
		}
	}
	//Loop it
	int maxspeed = 0;
	for(int i = 0; i < 100; i++){
		if(bessie[i] - limit[i] > maxspeed)
			maxspeed = bessie[i] - limit[i];
	}
	fout << maxspeed << endl;
	return 0;
}