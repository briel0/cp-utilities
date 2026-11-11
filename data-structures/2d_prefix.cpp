// Prefix sum 2D, matriz n x m (NAO precisa ser quadrada)
// prefix 1-indexed: prefix[i][j] = soma de a[0..i-1][0..j-1]
// consulta (x1,y1)-(x2,y2) 1-indexed, inclusiva; x = linha (ate n), y = coluna (ate m)
// para contar celulas, troque a[i-1][j-1] por (a[i-1][j-1] == alvo)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> a(n, vector<int>(m));
    for(auto &x : a){
        for(int &y : x){
            cin >> y;
        }
    }

    vector<vector<int>> prefix(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i - 1][j - 1];
        }
    }

    auto query = [&](int x1, int y1, int x2, int y2){
        return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
    };

    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1, y1, x2, y2) << '\n';
    }
}
