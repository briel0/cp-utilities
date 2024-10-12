#include <bits/stdc++.h>
using namespace std;
#define int long long

//maximum weighted edge in path between two nodes in an N-ary tree using binary lifting

int l, n, m;
const int MAX = 2e5 + 5;
vector<int> level;
vector<pair<int, int>> adj[MAX];
vector<vector<int>> up, _max;

//up[v][j] - 2^j-th ancestor above the node 
//_max[v][j] - value of the heaviest edge at the position

void dfs(int v, int p, int alt = 1){
    up[v][0] = p; //primeiro ancestral
    level[v] = alt;
    for(auto &[y, x] : adj[v]){
        if(x == p) continue;
        _max[x][0] = y; //primeiro peso
        dfs(x, v, alt + 1);
    }
}

void build(){
    for(int i = 1; i <= l; i++){
        for(int j = 1; j <= n; j++){
            up[j][i] = up[up[j][i - 1]][i - 1];
            _max[j][i] = max(_max[j][i - 1], _max[up[j][i - 1]][i - 1]);
        }
    }
}

int lca_max(int u, int v){
    if(level[u] > level[v]) swap(u, v);
    int ans = 0;
    //coloca os dois vertices na mesma altura
    for(int i = l; i >= 0; i--){
        if(level[v] - (1 << i) >= level[u]){ //garante que (1 << i) está entre o nível dos dois
            ans = max(ans, _max[v][i]);
            v = up[v][i];
        }
    }
    if(u == v) return ans;
    //termina de descer até o ancestral comum
    for(int i = l; i >= 0; i--){
        if(up[v][i] != up[u][i]){
            ans = max({ans, _max[v][i], _max[u][i]});
            u = up[u][i]; 
            v = up[v][i];
        }
    }
    ans = max({ans, _max[v][0], _max[u][0]});
    return ans;
}

void setup(){
    l = ceil(log(n));
    level.resize(n + 1);
    up.resize(n + 1, vector<int>(l + 1));
    _max.resize(n + 1, vector<int>(l + 1));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--){
      int a, b, peso;
      adj[a].push_back({peso, b});
      adj[b].push_back({peso, a});
    }
    
    dfs(1, 1); //ACHO QUE DA MERDA SE O PAI NAO FOR 1 NESSA PARTE
    build();
    
    
}
