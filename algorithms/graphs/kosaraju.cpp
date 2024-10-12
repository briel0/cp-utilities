#include <bits/stdc++.h>
using namespace std;
 
const int T = 1e5 + 5;
vector<int> adj[T], adj_t[T], saida, id;
bool visited[T];
int component;
 
void dfs(int v, int flag){
    visited[v] = 1;
    vector<int> &prov = (flag == 1 ? adj[v] : adj_t[v]);
    for(auto &x : prov){
        if(!visited[x]){
            dfs(x, flag);
        }
    }
    saida.push_back(v);
    id[v] = component;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    id.resize(n + 1);
    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_t[b].push_back(a);
    }
 
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i, 1);
        }
    }
 
    memset(visited, 0, sizeof(visited));
 
    for(int i = (n - 1); i >= 0; i--){
        int x = saida[i];
        if(!visited[x]){
            component++;
            dfs(x, 2);
        }
    }
 
    cout << component << '\n';
    for(int i = 1; i <= n; i++){
        cout << id[i] << ' ';
    }
 
}
