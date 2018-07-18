#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("day3.in");
	ofstream fout("day3-1.out");
	long long sq = 1, in;
	fin >> in;
	while(sq*sq < in)
		sq += 2;
	long long start = (sq-2)*(sq-2), steps = 0;
	for(int i = 0; i < 4 && !steps; i++, start += sq-1){
		if(in <= start + sq-1){
			long long curmid = start + sq/2;
			steps = abs(in - curmid) + sq/2;
		}
	}
	fout << steps << endl;
	return 0;
}
