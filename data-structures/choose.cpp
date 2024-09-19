#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int MOD = 1e9 + 7;
vector<int> fatorial, inverso;

int binexp(int base, int expo){
    int res = 1;
    while(expo){
        if(expo & 1){
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        expo >>= 1;
    }
    return res;
}

int escolhe(int a, int b){
    if(b > a){
        return 0;
    }
    int temp = fatorial[a] * inverso[b];
    temp %= MOD;
    temp *= inverso[a - b];
    temp %= MOD;
    return temp;
}

void work(){
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    const int T = 2e5 + 1;
    fatorial.resize(T);
    inverso.resize(T);
    fatorial[0] = fatorial[1] = 1; 
    for(int i = 2; i < T; i++){
        fatorial[i] = fatorial[i - 1] * i;
        fatorial[i] %= MOD;
    }
    inverso[T - 1] = binexp(fatorial[T - 1], MOD - 2);
    for(int i = T - 1; i >= 1; i--){
        inverso[i - 1] = inverso[i] * i;
        inverso[i - 1] %= MOD;
    }

    int t = 1;
    //cin >> t;
    while(t--){
        work();
    }
}
