#include <bits/stdc++.h>
using namespace std;

int n, h, d[10005];
vector<pair<int, int>> j[10005];

void djkt(int a){
    for(int i = 1; i <= n; i++){
        d[i] = INT_MAX; //CUIDADO SE FOR UM PROBLEMA DE LL
    }
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> p;
    d[a] = 0;
    p.push({0, a});
    while(!p.empty()){
        int v = p.top().second;
        int dv = p.top().first;
        p.pop();
        if(d[v] != dv){
            continue;
        }
        for(auto &x : j[v]){
            int w = x.first; //next node
            int l = x.second; //cost
            if((d[v] + l) < d[w]){
                d[w] = (d[v] + l);
                p.push({d[w], w});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    while(m--){
        int a, b, p;
        cin >> a >> b >> p;
        j[a].push_back({b, p});
        j[b].push_back({a, p}); //CHECAR SE É DIRECIONADO
    }
    
    djkt();
    
}
