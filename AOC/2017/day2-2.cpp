#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	ifstream fin("day2.in");
	ofstream fout("day2-2.out");
	long long sum = 0;
	while(fin.good()){
		string str;
		getline(fin, str);
		istringstream issin(str);
		long long t, ans = 0;
		vector<long long> arr;
		while(issin >> t)
			arr.push_back(t);
		int size = arr.size();
		for(int i = 0; i < size && !ans; i++)
			for(int j = 0; j < size && !ans; j++)
				if(i != j)
					if(!(arr[i] % arr[j]))
						ans = arr[i] / arr[j];
		sum += ans;
	}
	fout << sum << endl;
	return 0;
}
