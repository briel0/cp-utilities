#include <bits/stdc++.h>
using namespace std;
#define int long long
 
const int N = 2e5 + 1, lg = 30;
vector<int> adj[N], depth;
int lca[N][lg];
 
void dfs(int v, int pai){
    lca[v][0] = pai;
    for(int i = 1; i < lg; i++){
        if(lca[v][i - 1] != -1){
            lca[v][i] = lca[lca[v][i - 1]][i - 1];
        }
    }
    for(int &x : adj[v]){
        if(x == pai){
            continue;
        }
        depth[x] = depth[v] + 1;
        dfs(x, v);
    }
}
 
int uac(int a, int b){
    if(depth[b] > depth[a]){
        swap(a, b);
    }
    int diff = depth[a] - depth[b];
    for(int i = 0; i < lg; i++){
        if(diff & (1 << i)){
            a = lca[a][i];
        }
    }
    for(int i = lg - 1; i >= 0; i--){
        if(lca[a][i] != lca[b][i]){
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    if(a == b){
        return a;
    }
    return lca[a][0];
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, q;
    cin >> n >> q;
    depth.resize(n + 1);
    for(int i = 2, p; i <= n; i++){
        cin >> p;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    for(int i = 0; i < lg; i++){
        for(int j = 0; j <= n; j++){
            lca[j][i] = -1;
        }
    }
 
    dfs(1, 1);
 
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << uac(a, b) << '\n';
    }
 
}
