#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        long long a, b, c;
        char type, dump;
        cin >> a >> type >> b >> dump >> c;
        switch(type){
            case '+':
                if(a + b == c)
                    cout << "Good job!" << endl;
                else
                    cout << "Nice try!" << endl;
                break;
            case 'x':
                if(a * b == c)
                    cout << "Good job!" << endl;
                else
                    cout << "Nice try!" << endl;
                break;
            default: break;
        }
    }

    return 0;
}
