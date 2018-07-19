#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int T;
	//cin >> T;
	//while(T--){
	int N, blazeit = -1, size = 0;
	cin >> N;
	int cookie[N+5];
	for(int i = 0; i < N; i++){
		string bank;
		cin >> bank;
		cookie[i] = bank.size();
		if(cookie[i] > blazeit)
			blazeit = cookie[i];
		size += cookie[i];
	}
	size += N;
	int dist[size + 5], last[size + 5], lastlen[size + 5], goldencookie = 0, ans = -1;
	memset(dist, 0, sizeof(dist));
	memset(lastlen, 0, sizeof(lastlen));
	memset(last, -1, sizeof(last));
	for(int lul = blazeit, minlul; lul < size; lul += minlul){
		//cout << lul << endl;
		minlul = blazeit + 1;
		int row = 1, total = cookie[0], count;
		//cout << "Row 1:\t";
		//for(int i = 0; i < cookie[0]; i++)
		//	cout << "X";
		//cout << " ";
		for(int i = 1; i < N; i++){
			count = 0;
			if(total + cookie[i] + 1 <= lul){
				if(last[total-1] == row-1 && lastlen[total-1] == lul && dist[total-1] > count)
					count = dist[total-1];
				if(last[total] == row-1 && lastlen[total] == lul && dist[total] > count)
					count = dist[total];
				if(last[total+1] == row-1 && lastlen[total+1] == lul && dist[total+1] > count)
					count = dist[total+1];
				last[total] = row;
				dist[total] = count + 1;
				lastlen[total] = lul;
				if(count + 1 > ans){
					goldencookie = lul;
					ans = count + 1;
				}
				//for(int k = 0; k < cookie[i]; k++)
				//	cout << "X";
				//cout << " ";
				total += cookie[i] + 1;
			}else{
				int newmin = cookie[i] - (lul - total) + 1;
				if(newmin < minlul)
					minlul = newmin;
				row++;
				//cout << total << endl << "Row " << row << ":\t";
				total = cookie[i];
				//for(int k = 0; k < cookie[i]; k++)
				//	cout << "X";
				//cout << " ";
			}
		}
		if(ans >= row)
			break;
		//cout << total << endl;
	}
	cout << goldencookie << " " << ans << endl;
//}
	return 0;
}