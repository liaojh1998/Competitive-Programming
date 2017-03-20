//Title: Modern Art 2
//Type: Data Structures
//Complexity: O(NlogN)
//Solution: As expected of every USACO Gold contest this year, some data structure will be useful. Here Fenwick's tree and Segment tree's proved extemely useful.
        //  Use Fenwick's tree to determine if any two colors criss-cross, INCLUDING 0. Fenwick update of 1 and -1, if any color criss-cross, prefix sum results in non-zero sum.
        //  Use Segment tree to determine the maximum depth, which is possible with the maximum range query. Start from smallest interval to the biggest interval. USACO's idea of using stack for the recursive search works better.
#include <bits/stdc++.h>
//#define getchar() (getchar_unlocked()) //For hackerrank
using namespace std;
//inline if read speed is needed, huge compilation time required though
int readInt(int &n){
    register int c;
    n = 0;
    bool neg = false;
    c = getchar();
    for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
    if(!(~c)) return -1;
    if(c == '-') neg = true, c = getchar();
    for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
    if(neg) n = -n;
    return 1;
}
int readLL(long long &n){
    register int c;
    n = 0;
    bool neg = false;
    c = getchar();
    for(; ((c < 48 || c > 57)) && c != '-' && ~c; c = getchar());
    if(!(~c)) return -1;
    if(c == '-') neg = true, c = getchar();
    for(; c > 47 && c < 58 && ~c; c = getchar()){n = (n<<1)+(n<<3)+c-48;}
    if(neg) n = -n;
    return 1;
}
int readDouble(double &n){
    register int c;
    n = 0;
    bool neg = false;
    c = getchar();
    for(; ((c < 48 || c > 57)) && c != '-' && c != '.' && ~c; c = getchar());
    if(!(~c)) return -1;
    if(c == '-') neg = true, c = getchar();
    if(c != '.'){
        for(; c > 47 && c < 58 && ~c; c = getchar()){n = n*10+c-48;}
        if(c != '.'){
            if(neg) n = -n;
            return 1;
        }
    }
    double div = 1;
    for(c = getchar(); c > 47 && c < 58 && ~c; c = getchar()){div *= 10, n = n*10+c-48;}
    n /= div;
    if(neg) n = -n;
    return 1;
}
int readStr(char *str){
    register char c = getchar();
    register int len = 0;
    while(c < 33 && ~c) c = getchar(); //32 if space should be included
    if(!(~c)) return -1;
    //32 if stop at space, 10 if stop at next line
    while(c != 10 && c != 32 && ~c){
        str[len++] = c;
        c = getchar();
    }
    str[len] = '\0';
    //Just in case if needs to return arriving at end of line
    //if(c == 10) return 10;
    return 1;
}
int readStr(char *str, int len){
    //Reading string of size len
    for(int i = 0; i < len; i++){
        str[i] = getchar();
        if(!(~str[i])){
            str[i] = '\0';
            return -1;
        }
        //Remove this if str can't go to next line
        /*if(str[i] == 10){
            str[i] = '\0';
            return 10;
        }*/
    }
    str[len] = '\0';
    return 1;
}
void readIntArr(int *n, int len){
    for(int i = 0; i < len; i++)
        if(!(~readInt(n[i]))){
            n[i] = 0;
            return;
        }
}
void readLLArr(long long *n, int len){
    for(int i = 0; i < len; i++)
        if(!(~readLL(n[i]))){
            n[i] = 0;
            return;
        }
}
void readDoubleArr(double *n, int len){
    for(int i = 0; i < len; i++)
        if(!(~readDouble(n[i]))){
            n[i] = 0;
            return;
        }
}

template<typename T> class FenTree{
private:
    T* fwt;
    size_t N;
public:
    FenTree(size_t n){
        N = n+2;
        fwt = new T[N];
        memset(fwt, 0, sizeof(T)*(N));
    }
    T applyfunc(const T& a, const T& b){
        return a + b;
    }
    T queryfunc(const T& a, const T& b){
        return a + b;
    }
    void modify(size_t i, const T& value){
        for(i++; i < N; i += (i & -i))
            fwt[i] = applyfunc(fwt[i], value);
    }
    T query(size_t i){
        T ans = 0;
        for(i++; i; i &= (i - 1))
            ans = queryfunc(ans, fwt[i]);
        return ans;
    }
};
template<typename T> class SegTree{
private:
    T* sgt;
    size_t N, height;
public:
    SegTree(size_t n){
        N = n;
        height = (size_t)ceil(log2(N));
        sgt = new T[1<<(height+1)];
        memset(sgt, 0, sizeof(T)*(1<<(height+1)));
    }
    T applyfunc(const T& a, const T& b){
        return b;
    }
    T queryfunc(const T& a, const T& b){
        return a > b ? a : b;
    }
    void modify(size_t pos, const T& value){
        if(pos < 0 || pos >= N) return; //Not possible
        for(sgt[(pos + (1<<height))] = applyfunc(sgt[(pos += (1<<height))], value); pos > 1; pos >>= 1)
            sgt[pos>>1] = queryfunc(sgt[pos], sgt[pos^1]);
    }
    T query(size_t l, size_t r){
        T resl = 0, resr = 0; //Set initial values
        for(l += (1<<height), r += (1<<height); l < r; l >>= 1, r >>= 1){
            if(l&1) resl = queryfunc(resl, sgt[l++]);
            if(r&1) resr = queryfunc(sgt[--r], resr);
        }
        return queryfunc(resl, resr);
    }
};
struct paint{
    int first, second;
};
bool cmp(const paint& a, const paint& b){
    if(a.first == -1)
        return false;
    if(b.first == -1)
        return true;
    return ((a.second-a.first) < (b.second-b.first));
}
void solve(){
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    int N, temp;
    readInt(N);
    FenTree<int> fwt(N);
    paint paintings[N+5];
    memset(paintings, -1, sizeof(paintings));
    bool impossible = false;
    for(int i = 0; i < N && !impossible; i++){
        readInt(temp);
        if(paintings[temp].first == -1)
            paintings[temp].first = paintings[temp].second = i;
        else{
            if((fwt.query(i)-fwt.query(paintings[temp].first-1)))
                impossible = true;
            else{
                fwt.modify(paintings[temp].second, -1);
                paintings[temp].second = i;
                fwt.modify(paintings[temp].second, 1);
            }
        }
    }
    if(impossible){
        printf("%d\n", -1);
        return;
    }
    paintings[0].first = paintings[0].second = -1;
    sort(paintings, paintings+N+1, cmp);
    SegTree<int> sgt(N+5);
    int ans = 0;
    for(int i = 0; paintings[i].first != -1 && i < N; i++){
        temp = sgt.query(paintings[i].first+1, paintings[i].second)+1;
        if(temp > ans)
            ans = temp;
        sgt.modify(paintings[i].first, temp);
        sgt.modify(paintings[i].second, temp);
    }
    printf("%d\n", ans);
}
int main(){
    solve();
    return 0;
}