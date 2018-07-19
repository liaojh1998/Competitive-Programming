#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	getline(cin, str);
	int size = str.size();
	long long sum = 0;
	for(int i = 0; i < size; i++)
		if(str[i] == str[(i+1)%size])
			sum += str[i] - '0';
	cout << sum << endl;
	return 0;
}

