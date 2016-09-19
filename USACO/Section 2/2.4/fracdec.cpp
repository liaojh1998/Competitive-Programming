/*
ID: liaojh11
PROG: fracdec
LANG: C++
*/
//Title: fracdec
//Type: Brute Force
//Solution: Simple Ad Hoc. Incorporate the way of doing long divisions into the code.
#include <fstream>
#include <sstream>
#include <map>
#include <list>
using namespace std;
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
int N, D;
map<long long, int> B;
list<long long> R;
int main(){
	fin >> N >> D;
	stringstream s;
	if(!(N % D)){
		s << N/D << ".0";
		for(int i = s.str().length(); i > 0; i -= 76){
			fout << s.str().substr(s.str().length() - i, 76) << endl;
		}
		return 0;
	}
	s << N / D << ".";
	bool perf = 0;
	while(1){
		N %= D;
		if(!N){
			perf = 1;
			break;
		}
		if(B.find(N)->second == 1) break;
		B[N] = 1;
		R.push_back(N);
		N *= 10;
	}
	for(list<long long>::iterator it = R.begin(); it != R.end(); ++it){
		int rem = *it;
		if(rem == N) s << "(" << (rem * 10 / D);
		else s << (rem * 10 / D);
	}
	if(!perf) s << ")";
	for(int i = s.str().length(); i > 0; i -= 76){
		fout << s.str().substr(s.str().length() - i, 76) << endl;
	}
	return 0;
}