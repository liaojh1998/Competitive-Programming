#include <bits/stdc++.h>
using namespace std;

bool contains(const string& A, const string& B, const bool& verbose){
	int i = 0;
	int j = 0;
	int asize = A.size();
	int bsize = B.size();
	if(verbose){
		cout << "A: " << A << endl;
		cout << "   i" << endl;
		cout << "B: " << B << endl;
		cout << "   j" << endl;
	}
	while(i < asize && j < bsize){
		if(A[i] == B[j]){
			i++;
			j++;
		}else if(i == 0)
			j++;
		else
			i = 0;
		if(verbose){
			cout << "A: " << A << endl;
			cout << "   ";
			for(int k = 0; k < i; k++)
				cout << ' ';
			cout << 'i' << endl;
			cout << "B: " << B << endl;
			cout << "   ";	
			for(int k = 0; k < j; k++)
				cout << ' ';
			cout << 'j' << endl;
		}
	}
	if(i == asize)
		return true;
	return false;
}

int main(int argc, char* argv[]){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	bool verbose = false;
	if(argc > 1)
		if(argv[1][1] == 'v')
			verbose = true;
	string A, B;
	while(cin >> A){
		cin >> B;
		cout << A << " " << B << endl;
		cout << contains(A, B, verbose) << endl;
	}
	return 0;
}
