#include <bits/stdc++.h>
using namespace std;

double first_dfs(const int& u, const int& parent, double *T, vector<int> *G, vector<double> *EV){
	int size = G[u].size();
	double expected = 0;
	for(int i = 0; i < size; i++){
		int v = G[u][i];
		if(v != parent){
			EV[u].push_back(first_dfs(v, u, T, G, EV));
			expected += EV[u][i];
		}else{
			EV[u].push_back(-1);
		}
	}
	if(size > 1)
		expected /= size - 1;
	return expected + T[u];
}

void second_dfs(const int& u, double parent_EV, double *T, vector<int> *G, vector<double> *EV){
	int size = G[u].size();
	double total_expected = parent_EV;
	for(int i = 0; i < size; i++)
		if(EV[u][i] != -1)
			total_expected += EV[u][i];
	for(int i = 0; i < size; i++){
		int v = G[u][i];
		if(EV[u][i] == -1)
			EV[u][i] = parent_EV;
		else
			if(size - 1)
				second_dfs(v, (total_expected - EV[u][i]) / (size - 1) + T[u], T, G, EV);
			else
				second_dfs(v, T[u], T, G, EV);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//Initialize
	int N, u, v;
	cin >> N;
	double T[N+5];
	for(int i = 1; i <= N; i++)
		cin >> T[i];
	vector<int> G[N+5];
	for(int i = 0; i < N-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	//First DFS
	vector<double> EV[N+5];
	first_dfs(1, 0, T, G, EV);

	//Second DFS
	second_dfs(1, 0, T, G, EV);

	//Iterate all EVs
	int best = 1, size = EV[1].size();
	double total_expected = 0;
	for(int i = 0; i < size; i++)
		total_expected += EV[1][i];
	double best_reading_time = T[1] + total_expected / size;
	//cout << best << ": " << best_reading_time << endl;
	for(int i = 2; i <= N; i++){
		size = EV[i].size();
		total_expected = 0;
		for(int j = 0; j < size; j++)
			total_expected += EV[i][j];
		double expected_reading_time = T[i] + total_expected / size;
		if(expected_reading_time < best_reading_time){
			best_reading_time = expected_reading_time;
			best = i;
		}
		//cout << i << ": " << expected_reading_time << endl;
	}

	cout << best << endl;

	return 0;
}