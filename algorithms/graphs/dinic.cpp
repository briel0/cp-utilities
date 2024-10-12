#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, cnt = 0, s, t;
vector<int> level, ptr;
vector<vector<int>> adj;
queue<int> q;

struct edge{
    int v, u;
    int cap, flow = 0;
    edge(int v, int u, int cap) : v(v), u(u), cap(cap) {}
};

vector<edge> edges;

void add_edge(int v, int u, int cap){
    edges.push_back({v, u, cap});
    edges.push_back({u, v, 0});
    adj[v].push_back(cnt);
    adj[u].push_back(cnt + 1);
    cnt += 2;
}

int dfs(int v, int pushed){
    if(pushed == 0){
        return 0;
    }
    if(v == t){
        return pushed;
    }
    int temp = adj[v].size();
    for(int &cid = ptr[v]; cid < temp; cid++){
        int id = adj[v][cid];
        int u = edges[id].u;
        if(level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1){
            continue;
        }
        int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
        if(tr == 0){
            continue;
        }
        edges[id].flow += tr;
        edges[id ^ 1].flow -= tr;
        return tr;
    }
    return 0;
}

bool bfs(){
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int id : adj[v]){
            if(edges[id].cap - edges[id].flow < 1){
                continue;
            }
            if(level[edges[id].u] != -1){
                continue;
            }
            level[edges[id].u] = level[v] + 1;
            q.push(edges[id].u);
        }
    }
    return level[t] != -1;
}

int flow(){
    int f = 0;
    while(true){
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        q.push(s);
        if(!bfs()){
            break;
        }
        fill(ptr.begin(), ptr.end(), 0);
        while(int pushed = dfs(s, LLONG_MAX)){
            f += pushed;
        }
    }
    return f;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m;
    cin >> n >> m;

    adj.resize(n + 1);
    level.resize(n + 1);
    ptr.resize(n + 1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        add_edge(a, b + boy, 1);
    }
    
    s = 1;
    t = n; 
    flow();
    
}
