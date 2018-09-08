#include <bits/stdc++.h>
using namespace std;

int dfs_up(int cur, const vector<vector<int>>& lost, int *rank, bool *vis){
    if(vis[cur])
        return -1;
    if(rank[cur] != -1)
        return rank[cur];

    vis[cur] = true;
    const vector<int> &lost_arr = lost[cur];
    int size = lost_arr.size();

    int maxrank = 0;
    for(int i = 0; i < size && maxrank != -1; i++){
        int thisrank = dfs_up(lost_arr[i], lost, rank, vis);
        if(thisrank == -1)
            maxrank = -1;
        else{
            thisrank++;
            if(thisrank > maxrank)
                maxrank = thisrank;
        }
    }

    rank[cur] = maxrank;
    vis[cur] = false;
    return maxrank;
}

bool cmp(const pair<int, string>& a, const pair<int, string>& b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        unordered_map<string, int> tonum;
        unordered_set<int> beat;
        vector<vector<int>> lost(2*N + 5);

        int wrestlers = 0;
        for(int i = 0; i < N; i++){
            string a, b;
            cin >> a >> b;
            int u, v;
            if(tonum.find(a) == tonum.end()){
                u = wrestlers;
                tonum[a] = wrestlers;
                wrestlers++;
            }else
                u = tonum[a];
            if(tonum.find(b) == tonum.end()){
                v = wrestlers;
                tonum[b] = wrestlers;
                wrestlers++;
            }else
                v = tonum[b];
            beat.insert(u);
            lost[v].push_back(u);
        }

        /*
        for(int i = 0; i < wrestlers; i++){
            cout << i << endl << "Beat: ";
            for(int j = 0; j < beat[i].size(); j++)
                cout << beat[i][j] << " ";
            cout << endl << "Lost: ";
            for(int j = 0; j < lost[i].size(); j++)
                cout << lost[i][j] << " ";
            cout << endl;
        }
        */

        int rank[wrestlers + 5];
        memset(rank, -1, sizeof(rank));

        bool cycle = false, none = true, vis[2*N + 5];
        memset(vis, 0, sizeof(vis));
        for(unordered_map<string, int>::iterator it = tonum.begin(); it != tonum.end() && !cycle; it++){
            if(!beat.count(it->second)){
                none = false;
                int res = dfs_up(it->second, lost, rank, vis);
                if(res == -1)
                    cycle = true;
            }
        }

        if(cycle || none)
            cout << "Rico needs a new ranking system" << endl;
        else{
            vector<pair<int, string>> final_rank;
            for(auto wrestler : tonum){
                string name = wrestler.first;
                int wrestler_rank = rank[wrestler.second];
                final_rank.push_back(pair<int, string>(wrestler_rank, name));
            }
            sort(final_rank.begin(), final_rank.end(), cmp);

            for(int i = 0; i < wrestlers; i++)
                cout << final_rank[i].second << endl;
        }
    }

    return 0;
}
