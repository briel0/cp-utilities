#include <bits/stdc++.h>
using namespace std;
#define matrix vector<vector<int>>
#define int long long

const int MOD = 1e9 + 7;

int n, e, r1, c1, r2, c2;
matrix res, init;

matrix mult(matrix a, matrix b){
    matrix ans(r1, vector<int>(c2, 0));
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            for(int k = 0; k < c1; k++){
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}

void binexp(int expo){
    res.assign(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) res[i][i] = 1;
    while(expo){
        if(expo & 1){
            res = mult(res, init);
        }
        init = mult(init, init);
        expo >>= 1;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n >> e;
        init.assign(n, vector<int>(n, 0));
        
        for(auto &x : init){
            for(int &y : x){
                cin >> y;
            }
        }
        
        binexp(e);
        
        for(auto &x : res){
            for(int &y : x){
                cout << y << ' ';
            }
            cout << '\n';
        }
        
    }
    
}
/*
*/
