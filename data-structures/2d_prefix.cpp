#include <bits/stdc++.h>
using namespace std;

//CSES Forest Queries solution
//visualize -> https://www.youtube.com/watch?v=WibxoqMSMCw

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<string> original(n);
    for(auto &x : original){
        cin >> x;
    }
    int prefix[n + 1][n + 1] = {};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + (original[i - 1][j - 1] == '*');
        }
    }
    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << '\n'; 
    }
}
