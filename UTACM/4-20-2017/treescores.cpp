#include <bits/stdc++.h>
using namespace std;

template<typename T> class MinTree{
private:
    T* sgt;
    size_t N, height;
    T applyfunc(const T& a, const T& b){
        return b;
    }
    T queryfunc(const T& a, const T& b){
        return a < b ? a : b;
    }

public:
    MinTree(size_t n){
        N = n;
        height = (size_t)ceil(log2(N));
        sgt = new T[1<<(height+1)];
        fill_n(sgt, 1<<(height+1), N+1);
    }
    ~MinTree(){
        delete[] sgt;
    }
    T& operator[](const size_t& i){
        return sgt[i + (1<<height)];
    }

    void build(){
        for(size_t i = ((1<<height)-1); i > 0; i--)
            sgt[i] = queryfunc(sgt[i<<1], sgt[i<<1|1]);
    }
    void update(size_t pos, const T& value){
        if(pos < 0 || pos >= N) return;
        for(sgt[(pos + (1<<height))] = applyfunc(sgt[(pos += (1<<height))], value); pos > 1; pos >>= 1)
            sgt[pos>>1] = queryfunc(sgt[pos], sgt[pos^1]);
    }
    T query(size_t l, size_t r){
        if(!((l+1)^r)) return (*this)[l];
        T resl = N+1, resr = N+1;
        for(l += (1<<height), r += (1<<height); l < r; l >>= 1, r >>= 1){
            if(l&1) resl = queryfunc(resl, sgt[l++]);
            if(r&1) resr = queryfunc(sgt[--r], resr);
        }
        return queryfunc(resl, resr);
    }
};
template<typename T> class MaxTree{
private:
    T* sgt;
    size_t N, height;
    #define defval (-1)
    T applyfunc(const T& a, const T& b){
        return b;
    }
    T queryfunc(const T& a, const T& b){
        return a > b ? a : b;
    }

public:
    MaxTree(size_t n){
        N = n;
        height = (size_t)ceil(log2(N));
        sgt = new T[1<<(height+1)];
        fill_n(sgt, 1<<(height+1), defval);
    }
    ~MaxTree(){
        delete[] sgt;
    }
    T& operator[](const size_t& i){
        return sgt[i + (1<<height)];
    }

    void build(){
        for(size_t i = ((1<<height)-1); i > 0; i--)
            sgt[i] = queryfunc(sgt[i<<1], sgt[i<<1|1]);
    }
    void update(size_t pos, const T& value){
        if(pos < 0 || pos >= N) return;
        for(sgt[(pos + (1<<height))] = applyfunc(sgt[(pos += (1<<height))], value); pos > 1; pos >>= 1)
            sgt[pos>>1] = queryfunc(sgt[pos], sgt[pos^1]);
    }
    T query(size_t l, size_t r){
        if(!((l+1)^r)) return (*this)[l];
        T resl = defval, resr = defval;
        for(l += (1<<height), r += (1<<height); l < r; l >>= 1, r >>= 1){
            if(l&1) resl = queryfunc(resl, sgt[l++]);
            if(r&1) resr = queryfunc(sgt[--r], resr);
        }
        return queryfunc(resl, resr);
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N;
    cin >> K;
    int scores[N+5];
    pair<int, int> arr[N+5];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> arr[j].first;
            arr[j].second = j;
        }
        MinTree<int> mint(N);
        mint.build();
        MaxTree<int> maxt(N);
        maxt.build();
        sort(arr, arr+N);
        for(int j = 0; j < N; j++){
            int k = 1;
            while(k < N && arr[j+k] == arr[j])
                k++;
            for(int l = 0; l < k; l++){
                int mini = mint.query(arr[j+l].second+1, N);
                int maxi = maxt.query(0, arr[j+l].second);
                printf("%d %d %d\n", mini, maxi, (mini-maxi-2)*arr[j+l].first);
                if((mini-maxi-2)*arr[j+l].first > scores[i])
                    scores[i] = (mini-maxi-2)*arr[j+l].first;
            }
            for(int l = 0; l < k; l++){
                printf("%d\n", arr[j+l].second);
                mint.update(arr[j+l].second, arr[j+l].second);
                maxt.update(arr[j+l].second, arr[j+l].second);
            }
            j += k-1;
        }
        /*
        if(arr[0].second < arr[1].second && arr[0].second > p)
            p = arr[0].second;
        if(arr[0].second > arr[1].second && arr[1].second < q)
            q = arr[0].second;
        tmp = arr[1].first * (q-p);
        if(tmp > scores[i])
            scores[i] = tmp;
        cout << "1 " << tmp << endl;
        for(int j = 2; j < N; j++){
            if(arr[j-1].first < arr[j].first){
                if(arr[j-1].second < arr[j].second && arr[j-1].second >= p)
                    p = arr[j-1].second+1;
                if(arr[j-2].second < arr[j].second && arr[j-2].second >= p)
                    p = arr[j-2].second+1;
            }
            if(arr[j-2].first < arr[j].first){
                if(arr[j-1].second > arr[j].second && arr[j-1].second <= q)
                    q = arr[j-1].second-1;
                if(arr[j-2].second > arr[j].second && arr[j-2].second <= q)
                    q = arr[j-2].second-1;
            }
            tmp = arr[j].first * (q-p);
            if(p == 0 || q == N-1)
                tmp += arr[j].first;
            if(tmp > scores[i])
                scores[i] = tmp;
            cout << j << " " << p << " " << q << " " << tmp << endl;
        }
        */
    }
    //for(int i = 0; i < N; i++)
      //  cout << scores[i] << endl;
    //step 1
    int step1[N+5];
    step1[0] = 0;
    for(int i = 0; i < K; i++)
        step1[0] += scores[i];
    for(int i = 1; i < N-K; i++)
        step1[i] = step1[i-1]-scores[i-1]+scores[i+K-1];
    //step 2
    int dp[N+5][N+5];
    memset(dp, 0, sizeof(dp));
    for(int i = N-K-K-1; i >= 0; i--){
        dp[i][i+K] = step1[i] + step1[i+K];
        for(int j = i+K+1; j < N-K; j++){
            dp[i][j] = step1[i] + step1[j];
            if(dp[i][j-1] > dp[i][j])
                dp[i][j] = dp[i][j-1];
            if(dp[i+1][j] > dp[i][j])
                dp[i][j] = dp[i+1][j];
        }
    }
    int maxi = 0;
    for(int i = 0; i < N-3*K; i++)
        if(scores[i] + dp[i+K-1][N-K-1] > maxi)
            maxi = scores[i] + dp[i+K-1][N-K-1];
    cout << maxi << endl;
    return 0;
}