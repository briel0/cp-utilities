#include <bits/stdc++.h>
using namespace std;

//TALVEZ NAO FUNCIONE

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for(auto &[a, b, peso] : edges){
        cin >> a >> b >> peso;
    }
    vector<int> dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    for(int i = 0; i < n - 1; i++){
        bool mudou = 0;
        for(auto &[a, b, peso] : edges){
            if(dist[a] != LLONG_MAX){
                if(dist[a] + peso < dist[b]){
                    dist[b] = dist[a] + peso;
                    mudou = 1;
                }
            }
        }
        if(!mudou){
            break;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << dist[i] << ' ';
    }
}
