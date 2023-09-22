#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 4e5 + 1;
vector<int> adj[MAX], cor, s, e, rcolor;

//Abre um contador de "entrada" e "saída" de cada nó e faz esse registro.
//Acessando o range (start[v], end[v]) tem-se a subtree linearizada
int _time = 0;
void dfs(int v, int p){
    s[v] = _time++;
    rcolor[s[v]] = tmp[v]; //salvando a info de cada nó
    for(int &x : adj[v]){
        if(x == p) continue;
        dfs(x, v);
    }
    e[v] = _time;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i < (n - 1); i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
}
/*
*/
