#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for(int idx = 1; idx <= T; idx++){
		double A;
		cin >> A;
		cout << "Case #" << idx << ":" << endl;
		//Case 1: Area less than sqrt(2)
			//I give up XD
		if(A <= 1.41421356237){
			double x = (A*A-1)/(2*A);
			double y = sqrt(1.00000000/2-x)*sqrt(1.000000000/2+x);
			printf("%.12lf %.12lf 0\n", y, x);
			printf("%.12lf %.12lf 0\n", -x, y);
			cout << "0 0 0.5" << endl;
		}else{
		//Case 2: Area less than sqrt(3)
			//I give up XD
			cout << "0 0 0.5" << endl << "0 0.5 0" << endl << "0.5 0 0" << endl;
		}
	}
	return 0;
}