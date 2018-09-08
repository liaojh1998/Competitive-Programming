#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<long long, long long>& a, const pair<long long, long long>& b){
    if(a.first == b.first)
        if(a.second < b.second)
            return true;
        else
            return false;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    pair<long long, long long> times[N+5];
    for(int i = 0; i < N; i++)
        cin >> times[i].first >> times[i].second;
    sort(times, times+N, cmp);
    priority_queue<long long, vector<long long>, greater<long long> > end;

    long long ans = 0, inclass = 0;
    for(int i = 0; i < N; i++){
        long long S = times[i].first, E = times[i].second;
        //cout << S << " " << E << endl;
        while(!end.empty() && end.top() <= S){
            //cout << end.top() << endl;
            inclass--;
            end.pop();
        }
        inclass++;
        end.push(E);
        if(inclass > ans)
            ans = inclass;
    }

    cout << ans << endl;

    return 0;
}
