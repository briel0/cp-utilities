#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> tin, low, visited;
vector<pair<int, int>> ans;

int _time;
void dfs(int v, int p){
    visited[v] = 1;
    tin[v] = low[v] = _time++;
    for(auto &x : adj[v]){
        if(x == p){
            continue;
        }
        if(visited[x]){
            low[v] = min(low[v], tin[x]);
        }
        else{
            dfs(x, v);
            low[v] = min(low[v], low[x]);
            if(low[x] > tin[v]){
                ans.push_back({x, v});
            }
        }
    }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  ans.clear();
  adj.resize(n);
  visited.resize(n, 0);
  tin.resize(n, 0);
  low.resize(n, 0);
  
  while(m--){
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  for(int i = 0; i < n; i++){
    if(!visited[i]){
      dfs(i, -1);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << " bridges->\n";
  for(auto &[x, y] : ans){
    cout << x << " - " << y << '\n';
  }
  cout << '\n';
}
