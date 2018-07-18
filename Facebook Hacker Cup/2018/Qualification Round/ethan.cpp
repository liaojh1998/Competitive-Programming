#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("ethan_searches_for_a_string.txt", "r", stdin);
	freopen("ethan_searches_for_a_string-out.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for(int index = 1; index <= T; index++){
		string str;
		cin >> str;
		
		int size = str.size();
		
		//Using Z Algorithm's preprocessing
		int arr[size+5], L = 1, R = 1, sub = 0;
		arr[0] = size;
		//cout << arr[0] << " ";
		for(int i = 1; i < size && !sub; i++){
			if(arr[i-L] < R-i)
				arr[i] = arr[i-L];
			else{
				if(R < i) R = i;
				while(R < size && str[R-i] == str[R]) R++;
				arr[i] = R - (L = i);
			}
			//cout << arr[i] << " ";
			if(arr[i] && arr[i]+i < size)
				sub = i;
		}
		//cout << endl;
		
		cout << "Case #" << index << ": ";
		if(sub)
			cout << str.substr(0, sub) << str << endl;
		else
			cout << "Impossible" << endl;
	}
	return 0;
}
