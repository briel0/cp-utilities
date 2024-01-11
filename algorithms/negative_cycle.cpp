#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 0x3f3f3f3f3f3f3f3f; 
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for(auto &[a, b, peso] : edges){
        cin >> a >> b >> peso;
    }
    vector<int> dist(n + 1, INF), parent(n + 1, -1);
    dist[1] = 0;
    int last;
    for(int i = 0; i < n; i++){
        last = -1;
        for(auto &[a, b, peso] : edges){
            if(dist[a] + peso < dist[b]){
                dist[b] = max(-INF, dist[a] + peso);
                parent[b] = a;
                last = b;
            }
        }
    }
    if(last == -1){
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < n; i++){
        last = parent[last];
    }
    vector<int> cycle;
    for(int i = last;; i = parent[i]){
        cycle.push_back(i);
        if(i == last && cycle.size() > 1){
            break;
        }
    }
    cout << "YES\n";
    reverse(cycle.begin(), cycle.end());
    for(int &x : cycle){
        cout << x << ' ';
    }
}
