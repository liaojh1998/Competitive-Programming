#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
	if(argc != 3){
		cout << "Wrong number of arguments" << endl;
		return 1;
	}
	ios_base::sync_with_stdio(false);
	ifstream f1(argv[1]);
	ifstream f2(argv[2]);
	int line = 0;
	while(f1.good()){
		line++;
		string str1, str2;
		getline(f1, str1);
		getline(f2, str2);
		if(str1 != str2){
			cout << "Fail at line #" << line << ":" << endl;
			cout << "\t" << argv[1] << ": " << str1 << endl;
			cout << "\t" << argv[2] << ": " << str2 << endl;
			cout << endl;
		}
	}
	cout << "Done!" << endl;
	return 0;
}
