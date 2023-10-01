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
    multimap<int, pair<int, int>> e;
    while(m--){
        int a, b, p;
        cin >> a >> b >> p;
        e.insert({p, {a, b}});
    }
    for(int i = 1; i <= n; i++){ 
        p[i] = i;
        //parente inicial (ele mesmo)
        s[i] = 1;
        //tamanho inicial (1)
    }
    int cost = 0;
    for(auto &y : e){
        int a = y.S.F, b = y.S.S;
        if(find_set(a) != find_set(b)){
            //cout << "uniu-> " << y.S.F << ' ' << y.S.S << ' ';
            union_set(y.S.F, y.S.S);
            //cout << "sets-> " << fs(y.S.F) << ' ' << fs(y.S.S) << '\n';
            cost += y.F;
        }
    }
    cout << cost << '\n';
    
}
/*
*/
