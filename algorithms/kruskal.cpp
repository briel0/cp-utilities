#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

vector<int> p; //parenting
vector<int> s; // size of sets

int find_set(int v){
    if(p[v] == v){
        return v;
    }
    return p[v] = find_set(p[v]); 
    //reconstruindo a árvore de forma a "subir mais rápido"
}

void union_set(int v, int q){
    v = find_set(v);
    q = find_set(q);
    if(v != q){
        if(s[v] < s[q]){ // o v é o de maior tamanho
            swap(v, q);
        }
        //o parente do de menor tamanho se torna o de maior
        p[q] = v;
        s[v] += s[q];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    p.resize(n + 1), s.resize(n + 1); //1-indexed
    vector<array<int, 3>> e(m);
    for(auto &[peso, a, b] : e){
        cin >> a >> b >> peso;
    }
    sort(e.begin(), e.end());
    for(int i = 1; i <= n; i++){ 
        p[i] = i;
        //parente inicial (ele mesmo)
        s[i] = 1;
        //tamanho inicial (1)
    }
    int cost = 0;
    for(auto &[peso, a, b] : e){
        if(find_set(a) != find_set(b)){
            //cout << "uniu-> " << a << ' ' << b << ' ';
            union_set(a, b);
            //cout << "sets-> " << fs(a) << ' ' << fs(b) << '\n';
            cost += peso;
        }
    }
    cout << cost << '\n';
}
/*
*/
