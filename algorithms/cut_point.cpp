#include <bits/stdc++.h>
using namespace std;
#define int long long

int tempo, cnt;
const int N = 4e2 + 1;
vector<int> adj[N], low, tin, visited;
set<int> ans;

void dfs(int v, int pai){
    visited[v] = 1;
    tin[v] = low[v] = tempo++;
    int filho = 0;
    for(int &x : adj[v]){
        if(x == pai){
            continue;
        }
        if(visited[x]){
            low[v] = min(low[v], tin[x]);
        }
        else{
            dfs(x, v);
            low[v] = min(low[v], low[x]);
            if(low[x] >= tin[v] && pai != -1){
                ans.insert(v);
            }
            filho++;
        }
    }
    if(pai == -1 && filho > 1){
        ans.insert(v);
    }
}

void work(int n, int m){
    ans.clear();
    low.assign(n + 1, -1);
    tin.assign(n + 1, -1);
    visited.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        adj[i].clear();
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, -1);
        }
    }
    cout << "Teste " << cnt << '\n';
    if(ans.empty()){
        cout << "nenhum\n\n";
        return;
    }
    for(auto &x : ans){
        cout << x << ' ';
    }
    cout << "\n\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while(cin >> n >> m){
        tempo = 0;
        cnt++;
        work(n, m);
    }
}
