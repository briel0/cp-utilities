#include <bits/stdc++.h>
using namespace std;
#define int long long

//AJUSTE O FLUXO INFINITO CONFORME A NECESSIDADE
//AJUSTE O N CONFORME A NECESSIDADE

const int N = 5e2 + 1;

int m, s, t;
//controle de arestas, source, sink
vector<array<int, 4>> edges;
vector<int> level, last;
vector<int> adj[N];

void add_edge(int v, int u, int cap){
    edges.push_back({v, u, cap, 0});
    edges.push_back({u, v, 0, 0});
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
}

bool bfs(){
    queue<int> fila;
    fila.push(s);
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    while(!fila.empty()){
        int v = fila.front();
        fila.pop();
        for(int &id : adj[v]){
            auto &[a, b, cap, flow] = edges[id];
            if(cap - flow < 1 || level[b] != -1){
                continue;
            }
            level[b] = level[v] + 1;
            fila.push(b);
        }
    }
    return level[t] != -1;
}

int dfs(int v, int pushed){
    if(pushed == 0 || v == t){
        return pushed;
    }
    int limite = adj[v].size();
    for(int &cid = last[v]; cid < limite; cid++){
        int id = adj[v][cid];
        auto &[a, b, cap, flow] = edges[id];
        if(level[b] != level[v] + 1 || cap - flow < 1){
            continue;
        }
        int tr = dfs(b, min(pushed, cap - flow));
        if(tr == 0){
            continue;
        }
        flow += tr;
        edges[id ^ 1][3] -= tr;
        return tr;
    }
    return 0;
}

int flow(){
    int f = 0;
    while(bfs()){
        fill(last.begin(), last.end(), 0);
        while(int pushed = dfs(s, LLONG_MAX)){
            f += pushed;
        }
    }
    return f;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, e;
    cin >> n >> e;
    level.assign(n + 1, -1);
    last.assign(n + 1, -1);
    while(e--){
        int a, b, c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    s = 1;
    t = n;
    cout << flow();
}

