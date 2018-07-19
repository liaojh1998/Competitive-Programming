#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("day2.in");
	ofstream fout("day2-1.out");
	long long sum = 0;
	while(fin.good()){
		string str;
		getline(fin, str);
		istringstream issin(str);
		long long t;
		issin >> t;
		long long M = t, m = t;
		while(issin >> t){
			if(M < t)
				M = t;
			if(m > t)
				m = t;
		}
		sum += M - m;
	}
	fout << sum << endl;
	return 0;
}
